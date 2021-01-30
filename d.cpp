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

bool isPrime (ull a) {
  if(a == 0 || a == 1) return false;
  if(a == 2) return true;
  if(a == 3) return true;

  for(ull i = 2; i * i <= a; i++) {
    if(a % i == 0) {
      return false;
    }
  }

  return true;
}


// const int MAX = 510000;
// const int MOD = 1000000007;

// long long fac[MAX], finv[MAX], inv[MAX];

// // テーブルを作る前処理
// void COMinit() {
//     fac[0] = fac[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for (int i = 2; i < MAX; i++){
//         fac[i] = fac[i - 1] * i % MOD;
//         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
//         finv[i] = finv[i - 1] * inv[i] % MOD;
//     }
// }

// // 二項係数計算
// long long COM(int n, int k){
//     // COMinit();

//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
// }


vector<string> vec;
ll n;
ll res = 0;
ll countN = 0;

void check(bool yFlag, int currentN, ll resultPattern) {
  if(currentN == -1) {
    res += resultPattern;
    return;
  }

  if(vec[currentN] == "AND") {
    if(yFlag) {
      // (true true)
      check(true, currentN-1, resultPattern);
    }else {
      if(currentN == 0) {
        check(false, currentN-1, resultPattern);
        check(true, currentN-1, resultPattern);
      } else {
        // (false, false) (false, true) (true, false)
        check(false, currentN-1, resultPattern * 2);
        check(true, currentN-1, resultPattern);
      }
    }
  } else {
    if(yFlag){
      res++;
      if(currentN == 0) {
        check(false, currentN-1, resultPattern);
        check(true, currentN-1, resultPattern);
      } else {
      // (true, false) (false, true) (true, true)
        check(false, currentN-1, resultPattern);
        check(true, currentN-1, resultPattern * 2);
      }
    } else {
      // (false false)
      check(false, currentN-1, resultPattern);
    }
  }
}

int main () {
  cin >> n;
  string query;

  for(int i = 0; i < n; i++) {
    cin >> query;
    vec.push_back(query);
  }

  check(true, n-1, 1);
// cout << countN << endl;
  cout << res - n<< endl;
}
