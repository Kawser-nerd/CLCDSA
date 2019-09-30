import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt();
        int H = sc.nextInt();
        int prime = 1_000_000_007;

        out.println(combinationMod(W - 1, H - 1, prime));
    }

    // (w+h)!/w!h!
    public static long combinationMod(int w, int h, long prime) {
        int n = w + h;

        // ????
        long fac[] = new long[n + 1];
        long finv[] = new long[n + 1];
        long inv[] = new long[n + 1];
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % prime;
            inv[i] = prime - inv[(int) (prime % Long.valueOf(i))] * (prime / i) % prime;
            finv[i] = finv[i - 1] * inv[i] % prime;
        }

        return fac[w + h] * (finv[w] * finv[h] % prime) % prime;
    }
}