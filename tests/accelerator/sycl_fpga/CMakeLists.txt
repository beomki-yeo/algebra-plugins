# Algebra plugins library, part of the ACTS project (R&D line)
#
# (c) 2023 CERN for the benefit of the ACTS project
#
# Mozilla Public License Version 2.0

# Set the default SYCL compiler flags.
include( algebra-plugins-compiler-options-sycl-fpga )

# Add FPGA Emulator Test
algebra_add_test( array_fpga_emu "array_cmath.cpp" LINK_LIBRARIES algebra::array_cmath )
set_target_properties( algebra_test_array_fpga_emu PROPERTIES COMPILE_FLAGS "${EMULATOR_COMPILE_FLAGS}")
set_target_properties( algebra_test_array_fpga_emu PROPERTIES LINK_FLAGS "${EMULATOR_LINK_FLAGS}")
