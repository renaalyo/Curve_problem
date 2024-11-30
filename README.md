# Curve_problem

Design a small C++ program to implement support for a 3D curves hierarchy, including circles, ellipses, and 3D helixes. 
Where each curve should be able to return a 3D point and its first derivative (3D vector) for a given parameter t. 
The program should populate a container (e.g., a vector or list) with objects of these types created in a random manner with random parameters. 
It should also then print the coordinates of points and derivatives of all curves in the container at t=π/4. 
Next, the program should populate a second container containing only circles from the first container, ensuring the second container shares circles from the first one, e.g., via pointers. 
The second container should be sorted in ascending order of circles’ radii, with the first element having the smallest radius and the last having the greatest. 
Finally, the program should compute the total sum of radii of all curves in the second container.
