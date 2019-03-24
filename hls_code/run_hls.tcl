############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################

##############################################
# Project settings

# Create a project
open_project cordic_prj


# The source file and test bench
add_files cir_cordic.cpp
add_files -tb mysin.dat
add_files -tb mycos.dat
add_files -tb myalpha.dat
add_files -tb cir_cordic_tb.cpp


# Specify the top-level function for synthesis
set_top cir_cordic

###########################
# Solution settings

# Create solution1
open_solution -reset "solution1"

# Specify a Xilinx device and clock period
set_part {xc7z020clg400-2}
create_clock -period 10 -name default

# Simulate the C code
csim_design

# Do not perform any other steps
# - The basic project will be opened in the GUI 

exit