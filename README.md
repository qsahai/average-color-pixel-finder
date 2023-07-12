This is a program that takes the average hex color of an image with arbitrary dimensions via OpenCV, then finds a target pixel color by traversing the image either by rows or columns first. This is part of a larger project where the target pixel will be utilized.


TO COMPILE:
This requires your system to have OpenCV installed. I used version 4.8.0 but the makefile allows for the minimum version to be OpenCV 2.8.

Once you have OpenCV installed, enter the folder in the command line and enter the following:

cmake .

make

The cmake command only needs to be entered once, should the source code be altered.
