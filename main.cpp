#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/shift-2d-grid/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  void correctColRow(int &rn, int &cn, int row, int col) {
    //PV4(rn, cn, row, col);
    rn += cn / col;
    cn %= col;
    rn %= row;
  }

  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int row = grid.size();
    int col = grid[0].size();
    k = k % (col * row);
    if (k == 0)
      return grid;
    int shifts = 0;
    for (int startcolumn = 0; startcolumn < k && shifts < (row * col); ++startcolumn) {
      int rn = 0;
      int cn = startcolumn;
      correctColRow(rn, cn, row, col);
      int startrn = rn;
      int startcn = cn;
      int prev = grid[rn][cn];
      do {
        cn += k;
        correctColRow(rn, cn, row, col);
        int next = grid[rn][cn];
        ++shifts;
        grid[rn][cn] = prev;
        prev = next;
      } while (! (rn == startrn && cn == startcn));
    }
    return grid;
  }
};

void test1() {
  vector<vector<int>> v1{vector<int>{1, 2, 3}, vector<int>{4, 5, 6}, vector<int>{7, 8, 9}};
  int k = 1;

  cout << " ? " << Solution().shiftGrid(v1, k) << endl;

  vector<vector<int>>
      v2{vector<int>{3, 8, 1, 9}, vector<int>{19, 7, 2, 5},
         vector<int>{4, 6, 11, 10}, vector<int>{12, 0, 21, 13}};
  int k2 = 4;
  cout << " ? " << Solution().shiftGrid(v2, k2) << endl;
}

void test2() {

}

void test3() {

}