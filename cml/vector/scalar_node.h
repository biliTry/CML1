/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 */

#pragma once

#ifndef	cml_vector_scalar_node_h
#define	cml_vector_scalar_node_h

#include <cml/common/size_tags.h>
#include <cml/vector/readable_vector.h>

namespace cml {

template<class Sub, class Scalar, class Op> class vector_scalar_node;

/** vector_scalar_node<> traits. */
template<class Sub, class Scalar, class Op>
struct vector_traits< vector_scalar_node<Sub,Scalar,Op> >
{
  /* Figure out the basic types of Sub and Scalar: */
  typedef Sub						left_arg_type;
  typedef Scalar 					right_arg_type;
  typedef cml::unqualified_type_t<Sub>			left_type;
  typedef cml::unqualified_type_t<Sub>			left_traits;
  typedef cml::unqualified_type_t<Scalar>		right_type;
  typedef scalar_traits<typename Op::result_type>	element_traits;
  typedef typename element_traits::value_type		value_type;
  typedef typename element_traits::immutable_value	immutable_value;
  typedef typename left_traits::size_tag		size_tag;
  typedef typename left_traits::temporary_type		temporary_type;
};

/** Represents a binary vector operation, where one operand is a scalar
 * value, and the other is a vector.
 */
template<class Sub, class Scalar, class Op>
class vector_scalar_node
: public readable_vector< vector_scalar_node<Sub,Scalar,Op> >
{
  public:

    typedef vector_scalar_node<Sub,Scalar,Op>		node_type;
    typedef vector_traits<node_type>			traits_type;
    typedef typename traits_type::left_arg_type		left_arg_type;
    typedef typename traits_type::right_arg_type	right_arg_type;
    typedef typename traits_type::left_type		left_type;
    typedef typename traits_type::right_type		right_type;
    typedef typename traits_type::element_traits	element_traits;
    typedef typename traits_type::value_type		value_type;
    typedef typename traits_type::immutable_value	immutable_value;
    typedef typename traits_type::size_tag		size_tag;
    typedef typename traits_type::temporary_type	temporary_type;


  public:

    /** The array size constant is the same as the subexpression. */
    static const int array_size = left_type::array_size;


  public:

    /** Construct from the wrapped sub-expression and the scalar to apply.
     * @c sub must be an lvalue reference or rvalue reference.
     */
    vector_scalar_node(Sub left, const right_type& right);

    /** Move constructor. */
    vector_scalar_node(node_type&& other);


  public:

    /** Return the size of the vector expression. */
    int size() const;

    /** Apply the scalar operator to element @c i of the subexpression and
     * return the result.
     */
    immutable_value get(int i) const;


  protected:

    /** The type used to store the left subexpression.  The expression is
     * stored as a copy if Sub is an rvalue reference (temporary), or by
     * const reference if Sub is an lvalue reference.
     */
    typedef cml::if_t<std::is_rvalue_reference<Sub>::value,
	    left_type, const left_type&>		left_wrap_type;


  protected:

    /** The vector operand. */
    left_wrap_type		m_left;

    /** The read-only scalar operand. */
    const right_type		m_right;


  private:

    // Not copy constructible.
    vector_scalar_node(const node_type&);

    // Not assignable.
    node_type& operator=(const node_type&);
};

} // namespace cml

#define __CML_VECTOR_SCALAR_NODE_TPP
#include <cml/vector/scalar_node.tpp>
#undef __CML_VECTOR_SCALAR_NODE_TPP

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp:sw=2
