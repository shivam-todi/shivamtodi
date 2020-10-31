// A divide and conquer program in C++ to generate a random pair of 100 values and
// to find the closest pair(distance).
  
#include <bits/stdc++.h>
using namespace std; 
  
// A structure to represent a Point in 2D plane 
struct Point 
{ 
    int x, y; 
}; 
  
// Needed to sort array of points according to X coordinate 
int compareX(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a,  *p2 = (Point *)b; 
    return (p1->x - p2->x); 
} 
// Needed to sort array of points according to Y coordinate 
int compareY(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a,   *p2 = (Point *)b; 
    return (p1->y - p2->y); 
} 
  
// A function to find the distance between two points 
double dist(Point p1, Point p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                 (p1.y - p2.y)*(p1.y - p2.y) 
               ); 
} 
  
// A Brute Force method to return the smallest distance between two points 
// in P[] of size n 
double bruteForce(Point P[], int n) 
{ 
    double mn = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < mn) 
                mn = dist(P[i], P[j]); 
    return mn; 
} 
  
// A function to find a minimum of two double values 
double min(double x, double y) 
{ 
    return (x < y)? x : y; 
} 
  
  
//To find the distance between the closest points of strip of a given size.
// All points in strip[] are sorted according to y coordinate.
// It's an O(n) method as the inner loop runs at most 6 times.
double stripClosest(Point strip[], int size, double d) 
{ 
    double min = d; 
  
    // This loop runs at most 6 times 
    for (int i = 0; i < size; ++i) 
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
  
    return min; 
} 
  
// A recursive function to find the smallest distance.
double solve(Point x1[], Point y1[], int n) 
{ 
    // If there are 2 or 3 points, then use brute force 
    if (n <= 3) 
        return bruteForce(x1, n); 
  
    int mid = n/2; 
    Point midPoint = x1[mid]; 
  
  
    // Divide points in y sorted array around the vertical line. 
    Point Pyl[mid];   
    Point Pyr[n-mid]; 
    int li = 0, ri = 0;  
    for (int i = 0; i < n; i++) 
    { 
      if (y1[i].x <= midPoint.x && li<mid) 
         Pyl[li++] = y1[i]; 
      else
         Pyr[ri++] = y1[i]; 
    } 
  
    // Consider the vertical line passing through the middle point 
    // calculate the smallest distance dl on left of middle point and 
    // dr on right side 
    double dl = solve(x1, Pyl, mid); 
    double dr = solve(x1 + mid, Pyr, n-mid); 
  
    double d = min(dl, dr); 
  
    // Build an array strip[] that contains points close (closer than d) 
    // to the line passing through the middle point 
    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(y1[i].x - midPoint.x) < d) 
            strip[j] = y1[i], j++; 
  
    return stripClosest(strip, j, d); 
} 
  
double closest(Point P[], int n) 
{ 
    Point x1[n]; 
    Point y1[n]; 
    for (int i = 0; i < n; i++) 
    { 
        x1[i] = P[i]; 
        y1[i] = P[i]; 
    } 
    qsort(x1, n, sizeof(Point), compareX); 
    qsort(y1, n, sizeof(Point), compareY); 
    return solve(x1, y1, n); 
} 

int main() 
{ 
    int n = 100;
    srand(time(0));
    Point P[100]; 
    for(int i=0;i<100;i++)
    {
        int x1 = rand();
        int y1 = rand();
        P[i].x = x1;
        P[i].y = y1;
    }
    cout << "The smallest distance is " << closest(P, n); 
    return 0; 
} 