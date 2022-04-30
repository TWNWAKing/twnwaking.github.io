/*
ID: twnwaking
TASK: 
LANG: C++                 
*/
/*
   __________________
  | ________________ |
  ||          ____  ||
  ||   /\    |      ||
  ||  /__\   |      ||
  || /    \  |____  ||
  ||________________||
  |__________________|
  \###################\
   \###################\
    \        ____       \
     \_______\___\_______\

 An AC a day keeps the doctor away.
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple> 
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

//#include <bits/extc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;

//#include <ext/rope>
//using namespace __gnu_cxx;

//#include <atcoder/all>
//using namespace atcoder;

//#include <atcoder/convolution>
//#include <atcoder/dsu>
//#include <atcoder/fenwicktree>
//#include <atcoder/lazysegtree>
//#include <atcoder/math>
//#include <atcoder/maxflow>
//#include <atcoder/mincostflow>
//#include <atcoder/modint>
//#include <atcoder/scc>
//#include <atcoder/segtree>
//#include <atcoder/string>
//#include <atcoder/twosat>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define endl '\n'
#define pc putchar
#define nl putchar('\n')
#define int long long
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define FILEIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)


#ifndef LOCAL_DBG
//black magic
#pragma GCC optimize("Ofast","unroll-loops","no-stack-protector","fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#else
#pragma GCC optimize("trapv") //overflow check
#endif

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count()); //good random
inline int rnd(int x,int y){return rng()%(y-x+1)+x;}

const int MOD1=1000000007;
const int MOD2=998244353;
const int INF=2139062143;
const int LLINF=1000000000000000000LL;

template<class T> bool chmin(T &a,T b){return b<a?(a=b,true):false;}
template<class T> bool chmax(T &a,T b){return b>a?(a=b,true):false;}

//https://oi-wiki.org/contest/io/
namespace IO{

template <typename T> inline void R(T &x){ //for any type of integer input only
    x=0; T Sign=1;
    char c=getchar();
    while(c<'0'||c>'9') if(c=='-') Sign=-1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=Sign;
}
template<class A> inline void R(vector<A> &x){ //any type of integer vector only
    for(auto &a: x) R(a);
}
template<class H, class... T> inline void R(H& h, T&... t){ //read a lot of integers:R(a,b,c,...);
    R(h);
    R(t...);
}
template <typename T> void W(T y){
    if(y<0)y=-y,putchar('-');
    if(y>9)W(y/10);
    putchar(y%10+'0');
}
} //namespace IO
using namespace IO;

namespace DBG{
//Debugging template from Neal Wu and adapted a little by me :)
template<typename A, typename B> ostream& operator<<(ostream &os,const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v){ os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug_out() { cerr << "]\n";}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T){cerr << H;if(sizeof...(T)) cerr << ", "; debug_out(T...);}
#ifdef LOCAL_DBG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
}//namespace DBG
using namespace DBG;

//-------------
/*
bool cmp(){
    return
}
*/
inline __int128_t safe_mod(__int128_t x,__int128_t m){
    x%=m;
    if(x<0) x+=m;
    return x;
}
namespace bigint_io{

std::istream &operator>>(std::istream &is,__int128_t &n){
    n=0;
    __int128_t Sign=1;
    std::string s;
    is >> s;
    int __length=s.length();
    ((s[0]=='-')?Sign=-1:n=s[0]-'0');
    for(int i=1;i<__length;i++){
        n=10*n+s[i]-'0';
    }
    n*=Sign;
    return is;
}

std::istream &operator>>(std::istream &is,__uint128_t &n){
    n=0;
    std::string s;
    is >> s;
    int __length=s.length();
    for(int i=0;i<__length;i++){
        n=10*n+s[i]-'0';
    }
    return is;
}
 
std::ostream &operator<<(std::ostream &os,__int128_t n){
    if(n==0) {
        return os << 0;
    }
    std::string s;
    bool Neg=false;
    if(n<0){
        n=-n;
        Neg=true;
    }
    while(n>0){
        s+=n%10+'0';
        n/=10;
    }
    if(Neg){
        s+='-';
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

std::ostream &operator<<(std::ostream &os,__uint128_t n){
    if(n==0) {
        return os << 0;
    }
    std::string s;
    while(n>0){
        s+=n%10+'0';
        n/=10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

} //namespace bigint_io

using namespace bigint_io;
struct cmp {
    bool operator()(int a,int b) {
        return a>b;
    }
};
void solve(){
    __gnu_pbds::priority_queue<int, greater<int>, __gnu_pbds::pairing_heap_tag> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top()<<endl;
    pq.pop();
    cout << pq.top();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
#ifdef LOCAL_DBG
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w+",stdout);
    //freopen("error.txt","w+",stderr);
    auto begin = std::chrono::high_resolution_clock::now();
#endif
    int test_cases=1;
    //cin >> test_cases;
    //R(test_cases);
    while(test_cases--) solve();
#ifdef LOCAL_DBG
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << endl << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
    return 0;
}
/* For USACO submissions: Remember turn on file IO and add newline when the output is done*/