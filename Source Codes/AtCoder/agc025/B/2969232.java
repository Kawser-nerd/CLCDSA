import java.util.*;

public class Main {
    public static final long DIV = 998244353;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long k = sc.nextLong();
        sc.close();

        long[] comb = new long[(int)n+1];

        comb[0] = 1;
        for(int i=0; i<n; i++){
            comb[i+1] = comb[i] * (n-i);
            if(comb[i+1] > DIV) comb[i+1] = comb[i+1] % DIV;
            comb[i+1] = comb[i+1] * modinv(i+1, DIV);
            if(comb[i+1] > DIV) comb[i+1] = comb[i+1] % DIV;
        }

        long ans = 0;

        for(int i=0; i<=n; i++){
            if((k-a*i) % b != 0) continue;

            long tmp = (k-a*i) / b;
            if(tmp > n || tmp < 0) continue;
            int bi = (int)tmp;
            ans += comb[i] * comb[bi];
            if(ans >= DIV) ans = ans % DIV;
        }

        System.out.println(ans);
    }

    public static long modinv(long a, long n){
        long b = n, u=1, v=0;
        while(b > 0) {
            long t = a/b;
            a -= t*b;
            u -= t*v;
            t = a;
            a = b;
            b = t;
            t = u;
            u = v;
            v = t;
        }
        u = u % n;
        if(u < 0) u += n;
        return u;
    }
}