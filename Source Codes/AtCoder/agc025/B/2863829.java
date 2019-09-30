import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
    public static long comb(long a, long b, long mod, long[] pw, long[] ipw) {
        return (((pw[(int)a] * ipw[(int)a - (int)b]) % mod ) * ipw[(int)b]) % mod;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int max = 400000;
        int mod = 998244353;
        long[] pw  = new long[max];
        pw[0] = 1;
        long[] ipw = new long[max];
        BigInteger modb = new BigInteger(String.valueOf(mod));

        for(int i = 1; i < max; i++) {
            pw[i] = (i * pw[i-1]) % mod;
        }
        for(int i = 0; i < max; i++) {
            ipw[i] = new BigInteger(String.valueOf(pw[i])).modInverse(modb).longValue();
        }

        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long k = sc.nextLong();

        long ans = 0;
        for(int A = 0; A <= n; A++) {
            if((k - A * a) % b != 0) continue;
            long B = (k - A * a) / b;
            if(B > n || B < 0) continue;



            ans += ( comb(n,A,mod,pw,ipw) * comb(n,B,mod,pw,ipw) ) % mod;
            ans %= mod;
        }

        System.out.println(ans);






    }
}