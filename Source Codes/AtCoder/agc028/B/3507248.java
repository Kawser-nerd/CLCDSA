import java.util.*;

public class Main {
    public static void main(String[] args) {
        final long DIV = 1000000007;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextLong();
        }
        sc.close();

        long[] p = new long[n];
        long[] sump = new long[n+1];
        for(int i=0; i<n; i++){
            p[i] = inverseElement(i+1, DIV);
            sump[i+1] = sump[i] + p[i];
            sump[i+1] %= DIV;
        }

        long ans = 0;
        for(int i=0; i<n; i++){
            ans += a[i] * (sump[i-0+1] + sump[n-i] - p[0]);
            if(ans < 0) ans += DIV*DIV;
            if(ans > 0) ans %= DIV;
        }

        for(int i=0; i<n; i++){
            ans *= (i+1);
            ans %= DIV;
        }

        System.out.println(ans);
    }

    public static long inverseElement(long a, long n){
        long b = n, u=1, v=0;
        while(b > 0) {
            long t = a/b;
            a -= t*b;
            u -= t*v;
            //swap
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