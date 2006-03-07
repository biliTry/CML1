/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 */

#ifndef matrix_traits_h
#define matrix_traits_h

#include <cml/core/fwd.h>
#include <cml/et/traits.h>

namespace cml {
namespace et {

template<typename E, class AT, typename L>
struct ExprTraits< cml::matrix<E,AT,L> >
{
    typedef typename cml::matrix<E,AT,L> expr_type;
    typedef typename expr_type::value_type value_type;
    typedef typename expr_type::expr_reference reference;
    typedef typename expr_type::expr_const_reference const_reference;
    typedef typename expr_type::result_tag result_tag;
    typedef typename expr_type::size_tag size_tag;
    typedef expr_type result_type;
    typedef expr_leaf_tag node_tag;

    value_type get(const expr_type& m, size_t i, size_t j) const {
        return m(i,j);
    }

    matrix_size size(const expr_type& e) const { return e.size(); }
    size_t rows(const expr_type& m) const { return m.rows(); }
    size_t cols(const expr_type& m) const { return m.cols(); }
};

} // namespace et
} // namespace cml

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp