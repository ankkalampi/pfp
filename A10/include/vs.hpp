/**
 * You can use this file for programmign task 1 of set 1.
 */

#pragma once

#include <algorithm>
#include <array>

#include <vector>

namespace pfp {

template <class dtype> class vs {
public:
  static const int numberVecs = 100000;
  static constexpr int numbersInVec = 2147483647 / numberVecs;
  std::vector<std::vector<dtype>> vecs;

  vs() { vecs.resize(numberVecs); }

  void insert(dtype val) {
    int index = val / numbersInVec;
    // if (index >= numberVecs) index = numberVecs -1;
    vecs[index].push_back(val);
  }

  int count(dtype val) {

    int index = val / numbersInVec;
    std::sort(vecs[index].begin(), vecs[index].end());
    return std::binary_search(vecs[index].begin(), vecs[index].end(), val) ? 1
                                                                           : 0;
  }
};

} // namespace pfp
