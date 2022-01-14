/** Algebra plugins library, part of the ACTS project
 *
 * (c) 2020-2021 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */

// Project include(s).
#include "algebra/vc_vc.hpp"

// Test include(s).
#include "test_host_basics.hpp"

// GoogleTest include(s).
#include <gtest/gtest.h>

// System include(s).
#include <string>

/// Struct providing a readable name for the test
struct test_specialisation_name {
  template <typename T>
  static std::string GetName(int i) {
    switch (i) {
      case 0:
        return "vc_vc<float>";
      case 1:
        return "vc_vc<double>";
      default:
        return "unknown";
    }
  }
};

// Instantiate the test(s).
typedef testing::Types<
    test_types<float, algebra::vc::point2<float>, algebra::vc::point3<float>,
               algebra::vc::vector2<float>, algebra::vc::vector3<float>,
               algebra::vc::transform3<float>, algebra::vc::cartesian2<float>,
               algebra::vc::polar2<float>, algebra::vc::cylindrical2<float> >,
    test_types<double, algebra::vc::point2<double>, algebra::vc::point3<double>,
               algebra::vc::vector2<double>, algebra::vc::vector3<double>,
               algebra::vc::transform3<double>, algebra::vc::cartesian2<double>,
               algebra::vc::polar2<double>,
               algebra::vc::cylindrical2<double> > >
    vc_vc_types;
INSTANTIATE_TYPED_TEST_SUITE_P(algebra_plugins, test_host_basics, vc_vc_types,
                               test_specialisation_name);
