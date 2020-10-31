# Divide and conquer approach

# The idea is to presort all points according to y coordinates. Let the sorted array be y1[]. When we make recursive calls, we need to divide points of y1[] also according to the vertical line. We can do that by simply processing every point and comparing its x coordinate with x coordinate of the middle line.
