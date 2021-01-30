#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <climits>
#include <map>

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

bool isPrime (ull a) {
  if(a == 0 || a == 1) return false;
  if(a == 2) return true;
  if(a == 3) return true;

  for(int i = 2; i * i <= a; i++) {
    if(a % i == 0) {
      return false;
    }
  }

  return true;
}


int main () {
  int n, x;
  cin >> n >> x;
  ll currentRes = 0;
  int v, p;

  x *= 100;

  for(int i = 0; i < n; i++) {
    cin >> v >> p;
    currentRes += v * p;

    if(currentRes > x) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
