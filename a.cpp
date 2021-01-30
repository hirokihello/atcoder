#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <iomanip>
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
  string a;
  cin >> a;

  if(a[0] == a[1] && a[1] == a[2]) cout << "Won" << endl;
  else cout << "Lost" << endl;
}
