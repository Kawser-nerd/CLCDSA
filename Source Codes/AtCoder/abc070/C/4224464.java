import java.util.*;
import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        long a = 1000000000000000000L;
        //out.println(a % 10);

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] T = new long[N];
        for (int i = 0; i < N; i++){ T[i] = sc.nextLong(); }

        solver(N, T);
    }

    public static void solver(int N, long[] T) {
        long ans = 1;
        for(int n = 0; n < N; n++) {
            ans = lcm(ans, T[n]);
        }
        out.println(ans);
    }

    //??: https://www.suzushin7.jp/entry/2016/11/05/calculate-least-common-multiple-in-java/
    //????? ?????????? O(logN)
    static long gcd(long m, long n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        //out.println(m+" "+n);
        return gcd(n, m % n);
    }

    //?????lcm ?????????? O(logN)
    static long lcm(long m, long n) {
        return m * (n / gcd(m, n));
    }
}