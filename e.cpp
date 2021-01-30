#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

ull gcd (ull a, ull b) {
  if(b == 0) return a;

  return gcd(b, a % b);
}

ull lcm (ull a, ull b){
  // バッファ溢れを抑えるために順番大事！！！
  return a / gcd(a, b) * b;
}

ull calcDigitLength(ull n, int count) {
  if(n < 10) return count + 1;

  return calcDigitLength(n/10, count+1);
}

ll res = -9999999999999999;

array<vector<int>, (int)1e6> arr2;
array<bool, (int)1e6> mitansaku = { true };

vector<ll> vec;
void check(ll startN, ll currentMin) {
  for(int j = 0; j < arr2[startN].size(); j++) {
    int nextN = arr2[startN][j];
    mitansaku[nextN] = false;

    // cout << "startN = " << startN <<  " nextN = " << nextN << endl;
    // cout << "currentMin = " << currentMin << endl;

    res = max(res, vec[nextN] - currentMin);

    currentMin = min(currentMin, vec[nextN]);

    // cout << "res = " << res << endl;
    check(nextN, currentMin);
  }
}

int main () {
  vec.push_back(0);
  int n, m;
  ll a;
  cin >> n >> m;
  for(int i = 0; i < mitansaku.size(); i++) mitansaku[i] = true;

  for(int i = 0; i < n; i++) {
    cin >> a;
    vec.push_back(a);
  }

  int X, Y;

  for(int i = 0; i < m; i++) {
    cin >> X >> Y;
    arr2[X].push_back(Y);
  }

  for(int i = 0; i < n + 1; i++) {
    // cout << "i " << i << " vec[i] = " << vec[i] << endl;
    if(mitansaku[i]) check(i, vec[i]);
  }

  cout << res << endl;
}

