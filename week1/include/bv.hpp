/**
 * You can use this for programming task 2 of set 1 
*/

#pragma once

#include <algorithm>
#include <vector>
namespace pfp {

template <class dtype>
class bv {
  public:
  static const int numberVecs = 100000;
  std::vector<std::vector<dtype>> vecs;
  int numbersInVec;
    bv(dtype limit) {
      if (numberVecs > limit){
        numbersInVec = limit;
        vecs.resize(limit);
      } else {
        numbersInVec = limit / numberVecs;
        vecs.resize(numberVecs);
      }
      
    }

    void insert(dtype value) { 
      int index = value / numbersInVec;
      vecs[index].push_back(value);
    }

    int count(dtype value)  {
      int index = value / numbersInVec;
      std::sort(vecs[index].begin(), vecs[index].end());
      return std::binary_search(vecs[index].begin(), vecs[index].end(), value) ? 1 : 0;
    }
};

} // namespace pfp