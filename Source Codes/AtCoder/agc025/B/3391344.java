import java.util.*;

class Main
{
    static int MOD = 998244353;

    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        long K = sc.nextLong();
        long ans = 0;
        long[] comb = new long[n+1];
        comb[0] = 1;
        for(int i = 1; i < n+1; i++){
            comb[i] = comb[i-1] * (n - i + 1) % MOD * pow(i, MOD - 2) % MOD;
        }
 //       long yy = Math.max(K / n - B , 0);
 //       long xx = Math.min(n, K / A); 
        long q = K + A;
        for(int x = 0; x <= n; x++){
            q -= A;
            if(q % B == 0){
                long y = q / B;
                if(y > n ) continue;
                if(y < 0 ) break;
                ans = (ans + comb[x] * comb[(int)y] % MOD) % MOD;
            }
        }
        System.out.println(ans);
    }
    static long calc(int n, long a)
    {
        long MulSumN = 1;
        long MulSumA = 1;
        for(int i = 1; i <= a; i++){
            MulSumN *= n - i + 1;
            MulSumN %= MOD;
            MulSumA *= i;
            MulSumA %= MOD;
        }
        return MulSumN * pow(MulSumA, MOD - 2) % MOD;
    }
    public static long pow(long a, int b){
        if(b == 1) return a;
        if(b % 2 == 0){
            long d = pow(a, b / 2);
            return d * d % MOD;
        }
        return a * pow(a, b - 1) % MOD;
    }
 }