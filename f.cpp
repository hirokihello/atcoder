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

int main () {
  ll n, q, a;
  cin >> n >> q;
  vector<ll> vec;
  vec.push_back(0);
  for(int i = 0; i < n; i++) {
    cin >> a;
    vec.push_back(a);
  }

  array<array<ll, 300100>, 300100> arr = {{0}};

  for(int i = 1; i < vec.size(); i++) {
    for(int j = i; j < vec.size(); j++) {
      if(i == j) arr[i][j] = vec[i];
      else arr[i][j] = vec[i] ^ arr[i][j-1];
    }
  }

  int t;
  ll x,y;

  ll num;

  for(int i = 0; i < q; i++) {
    cin >> t >> x >> y;
    if(t ==1) {
        for(int i = 1; i < vec.size(); i++) {
    for(int j = i; j < vec.size(); j++) {
      if(i == j) arr[i][j] = vec[i];
      else arr[i][j] = vec[i] ^ arr[i][j-1];
    }
  }
    } else {
      cout << arr[x][y] << endl;
    }
  }
}

