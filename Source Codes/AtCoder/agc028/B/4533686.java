import java.util.*;
class Main
{
    static long mod = 1000000007;
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextLong();
        }
        long[] b = new long[n+1];
        b[0] = 0;
        for(int i = 1; i <= n; i++){
            b[i] = (b[i-1] + pow(i, mod - 2)) % mod;
        }
        long ans = 0;
        for(int i = 0; i < n; i++){
            ans += a[i] * (b[i+1] + b[n - i] - 1);
            ans %= mod;
        }
        for(int i = 1; i <= n; i++){
            ans *= i;
            ans %= mod;
        }
        System.out.println(ans);
    }
    static long pow(long a, long p){
        if(p == 0) return 1;
        else if(p % 2 == 0){
            long d = pow(a, p/2);
            return d * d % mod;
        }
        else return pow(a, p-1) * a % mod;
    }
}