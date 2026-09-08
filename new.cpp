//author: mishra__prateek_
//date: 7th sept 2026
  
/*==============================================================
██████╗░███████╗░█████╗░████████╗███████╗███████╗██╗░░██╗
██╔═██╗ ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██╔════╝██║░██╔╝
██████╦╝███████╝███████║░░░██║░░░█████╗░░█████╗░░█████═╝░
██╔══  ╗██╔══██╗██╔══██║░░░██║░░░██╔══╝░░██╔══╝░░██╔═██╗░
██╦╝║░  ██║  ██║██║░░██║   ██    ███████╗███████╗██   ██
╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚══════╝╚═╝░░╚═╝
================================================================*/
 
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define prateek int32_t
#define mishra main()
#define mod 1000000007
int count_same_side_vertex = 0;
vector<int> col(100001, -1);
vector<int> vis(100001, 0);
vector<vector<int>> ar(100001);
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define v_ka_input_lelo for(int i=0; i<n; i++) cin>>v[i];
#define vector_banado vector<int> v(n);
#define v_print_kardo for(int i=0; i<n; i++) cout<<v[i]<<" ";
typedef long long ll;
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m),m)+m)%m;}
 
#define plz_do_not_stalk_my_code ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"
 
#define MAX 10000000
vector<int> primes;
void sieve() {
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
 
    for (int i = 2; i * i <= MAX; i++) {
      if (isPrime[i]) {
           for (int j = i * i; j <= MAX; j += i) {
               isPrime[j] = false;
           }
      }
    }
 
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
           primes.push_back(i);
        }
    }
}
 
bool cycle_detection(int node, int par){
    vis[node] = 1;
 
    for(int child : ar[node]){
       if(vis[child]==0){
            if(cycle_detection(child, node) == true){
               return true;
            }
       }else{
            if(child != par){
               return true;
            }
       }
     }
 
         return false;
}
 
void jai_shree_ram(){
  for(int i=1; i<=1069; i++){
    int x = 9+9;
    int y = x+x;
    int z = y+y;
    //PRATEEK MISHRA
  }
}
 
int find_OR_between(int val1, int val2){
 
     vector<int> light;
     for(int i=0; i<40; i++) light.push_back(pow(2,i));
 
         int ans = 0, res = 0, indx1 = 0, indx2= 0;
         auto it = upper_bound(light.begin(), light.end(), val1);
         auto gt = upper_bound(light.begin(), light.end(), val2);
         indx1 = it - light.begin(), indx2 = gt - light.begin();
 
         if(indx1==indx2){
 
             while(true){
                if(val1<=0 and val2<=0) break;
                ans += light[indx1-1];
                val1 -= light[indx1-1], val2 -= light[indx1-1];
                auto it = upper_bound(light.begin(), light.end(), val1);
                auto gt = upper_bound(light.begin(), light.end(), val2);
                indx1 = it - light.begin(), indx2 = gt - light.begin();
                if(indx1==indx2){
                   continue;
                }else{
                   ans |= (light[indx2-1]|(light[indx2-1]-1));
                   break;
                }
             }
        }else{
            if(val2==light[indx2-1]){
               ans = val2*2-1;
            }else{
               val1 = light[indx2-1]-1;
               for(int i=val1; i<= val1+1; i++){
                   ans |= i;
               }
            }
        }
 
        return ans;
}
 
void dfs(int v){
   vis[v] = 1;
   for(auto child : ar[v]){
      if(vis[child]==0){
         dfs(child);
      }
   }
}
 
int gcd(int a, int b){
   if(b==0) return a;
   return gcd(b, a%b);
}
 
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
 
void bit_set(int n){
 for(int i = 31; i>=0; i--){
      if((1 & (n>>i))==1){
            cout<<1;
       }
 }
}
 
int fibonacci(int n) {
 if (n == 0) return 0;
 if (n == 1) return 1;
 
 vector<int> dp(n+1);
 dp[0] = 0;
 dp[1] = 1;
 
 for (int i = 2; i <= n; i++) {
   dp[i] = dp[i-1] + dp[i-2];
 }
 
 return dp[n];
}
  
int sqrt_integer(int n) {
  int low = 1, high = n, ans = 1;
    while (low <= high) {
       int mid = (low + high) / 2;
  
      if (mid <= n / mid) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
   }
}
    return ans;
}
 
bool bipartite(int v, int c) {
 vis[v] = 1;
 col[v] = c;
 
 if(c == 0) count_same_side_vertex++;
 
 for(int child : ar[v]) {
     if(vis[child] == 0) {
        if(bipartite(child, c ^ 1) == false) {
           return false;
        }
     } else {
         if(col[v] == col[child]) {
            return false;
         }
     }
 }
 
 return true;
}
 
int po(int n) {
   if (n == 0) return 1;
   if (n == 1) return 2;
   int h = po(n / 2);
   if (n & 1) {
      return 2 * h * 1LL * h;
   } else {
      return h * 1LL * h;
   }
}
  
/*    =============================================================================================*/
   
void func(){
  
}
 
 
prateek mishra{
    plz_do_not_stalk_my_code
    jai_shree_ram();
//ifstream input("input.txt");
//ofstream output("output.txt");
    int T;
    cin>>T;
    while(T--){
        int count = 0, mount =0, ans = 0, res = 0, count_0 = 0, count_1 =0, sum = 0, num = 0, maxi = -1e9-69, mini = 1e9+69;
        bool flag = false, check = false, good = false;
        int altu = 0, faltu = 0, count_od = 0, count_ev = 0, indx = 0, indx1 = 0, indx2 = 0;
        map<int,int> mp, mpp;
        map<string,int> ms, msp;
        map<char,int> mc, mcp;
        set<string> ss;
        set<char> sc;
        set<int> st, stt;
        vector<int> vec, v1, v2;
        int n;
/*      =====================================================================================*/
        //func();
  }
       //input.close();
       //output.close();
}