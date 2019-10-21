# Update
In this update, I've added an electrostatic charge class, to simulate various electric charge distributions and calculate 
the electric field and potential they create.

Currently, you can create a monopole, hollow, or solid sphere, and calculate the field vector it creates at a specified point.

Coming up, I will be implementing other charge distributions, including dipoles, lines, rings, and disks. I'm also going to 
add functions to calculate potential, and a system class to facilitate simulating an arbitrary number of charges.

# Overview
This is a small library I wrote to store and manipulate 3D vectors.

I used Unity's Vector3 library as inspiration, and implemented the functions I felt were important.

It's designed to be usable for whatever application of 3D vectors one may need (3D physical simulation, doing your math HW, etc.).

I rather like dealing with vectors in calc and physics, so I thought it'd be fun to write some code and play around with them

# Features
Create an arbitrary number of vectors and perform a variety of operations on them

Operations on multiple vectors include: dot product, cross product, angle, distance, projection, reflection

Also: scalar-vector multiplication/division, vector addition/subtraction, vector magnitude, vector normalization

# Coming up
I intend to implement a vector field class, though I've yet to figure out exactly how to go about implementing user-input of
a single/multi-variable function.
