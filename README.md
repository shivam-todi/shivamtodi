# Divide and conquer approach

# The idea is to presort all points according to y coordinates. Let the sorted array be y1[]. When we make recursive calls, we need to divide points of y1[] also according to the vertical line. We can do that by simply processing every point and comparing its x coordinate with x coordinate of the middle line.

# 1) We sort all points according to x and y coordinates.

# 2) Divide all points in two halves.

# 3) Recursively find the smallest distances in both subarrays.

# 4) Take the minimum of two smallest distances. Let the minimum be mn. 

# 5) Create an array strip[] that stores all points which are at most mn distance away from the middle line dividing the two sets.

# 6) Find the smallest distance in strip[].

# 7) Return the minimum of mn and the smallest distance calculated in above step 6.
