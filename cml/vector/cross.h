/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 */

#pragma once

#ifndef	cml_vector_cross_h
#define	cml_vector_cross_h

namespace cml {

/** Convenience alias to determine the fixed-length vector type to return
 * from cml::cross.
 */
template<class Sub1, class Sub2> using cross_promote_t
  = vector<value_type_promote_t<Sub1, Sub2>, cml::fixed<3>>;

/** Compute the cross-product of two 3D vectors, and return the result as a
 * fixed-length vector (cml::fixed<3>).
 *
 * @note Currently, the result is computed immediately, even if it appears
 * as a term in an expression.
 *
 * @throws vector_size_error at run-time if left or right is
 * dynamically-sized and is not a 3D vector.  The size is checked at
 * compile time for fixed-sized expressions.
 */
template<class Sub1, class Sub2> auto cross(
  const readable_vector<Sub1>& left, const readable_vector<Sub2>& right
  ) -> cross_promote_t<Sub1,Sub2>;

} // namespace cml

#define __CML_VECTOR_CROSS_TPP
#include <cml/vector/cross.tpp>
#undef __CML_VECTOR_CROSS_TPP

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp:sw=2
