# 3D-_Spinning_Donut

This C program renders a spinning ASCII donut using mathematical projections and depth buffering. It employs trigonometry and shading to create a 3D torus illusion in a terminal window.

How It Works:

Uses sin() and cos() functions to simulate a rotating 3D torus.
Implements a Z-buffer algorithm to handle depth perception.
Utilizes ASCII shading characters (.,~:;=!*#$@) for a lighting effect.
Continuously updates the screen using ANSI escape codes for smooth animation.

Requirements:

1.A C compiler (e.g., gcc)

2.A terminal that supports ANSI escape sequences


How to Compile and Run:
 
  make
  
  ./donut

***Inspired by Andy Sloane’s ASCII Donut, rewritten with improvements for clarity and efficiency.***
