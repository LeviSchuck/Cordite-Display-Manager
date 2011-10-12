#ifndef DIMENSION_2D
#define DIMENSION_2D
template<class T>
struct dim2d {
 T x;
 T y;
 inline dim2d(T _x = 0, T _y = 0) {
   x = _x;
   y = _y;
  }
};
typedef dim2d<int> dim2di;
#endif