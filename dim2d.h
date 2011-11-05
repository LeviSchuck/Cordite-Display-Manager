#ifndef DIMENSION_2D
#define DIMENSION_2D
/*! \brief A 2D couple of numbers
 * 
 * Just a general 2D struct, meant for primitives like ints, floats, doubles, longs.
 */
template<class T>
struct dim2d {
 T x;
 T y;
 inline dim2d(T _x = 0, T _y = 0) {
   x = _x;
   y = _y;
  }
};
//! integer pair
typedef dim2d<int> dim2di;
#endif