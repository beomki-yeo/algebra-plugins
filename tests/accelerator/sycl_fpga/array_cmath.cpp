/** Algebra plugins library, part of the ACTS project
 *
 * (c) 2023 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */

// Project include(s).
#include "algebra/array_cmath.hpp"

// SYCL include(s).
#include <sycl/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>

// System include(s).
#include <iostream>

using namespace sycl;

// Simple asynchronous handler function
auto handle_async_error = [](::sycl::exception_list elist) {
    for (auto& e : elist) {
        try {
            std::rethrow_exception(e);
        } catch (::sycl::exception& e) {
            std::cout << "ASYNC EXCEPTION!!\n";
            std::cout << e.what() << "\n";
        }
    }
};

int main() {

  // Select either the FPGA emulator, FPGA simulator or FPGA device
#if FPGA_SIMULATOR
  auto selector = sycl::ext::intel::fpga_simulator_selector_v;
#elif FPGA_HARDWARE
  auto selector = sycl::ext::intel::fpga_selector_v;
#else  // #if FPGA_EMULATOR
  auto selector = sycl::ext::intel::fpga_emulator_selector_v;
#endif

  // the array size of vectors a, b and c
  constexpr size_t kArraySize = 32;

  std::vector<float> vec_a(kArraySize);
  std::vector<float> vec_b(kArraySize);
  std::vector<float> vec_r(kArraySize);

  // Create a queue bound to the chosen device.
  // If the device is unavailable, a SYCL runtime exception is thrown.
  queue q(selector, handle_async_error);

  auto device = q.get_device();

  std::cout << "Running on device: "
            << device.get_info<sycl::info::device::name>().c_str() << std::endl;
};