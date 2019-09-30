import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A {
    public void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter("A-large.out");

        int[] p = new int[100000];
        int[] len = new int[100000];
        int pn = 1;
        p[0] = 2;
        len[0] = 1;
        for (int i = 3; i <= 1000000; i++) {
            boolean isP = true;
            for (int j = 0; p[j] * p[j] <= i; j++) {
                if (i % p[j] == 0) {
                    isP = false;
                    break;
                }
            }
            if (isP) {
                p[pn] = i;
                int k = i;
                len[pn] = 0;
                while (k > 0) {
                    len[pn]++;
                    k /= 10;
                }
                pn++;
            }
        }

        int testN = in.nextInt();
        for (int test = 1; test <= testN; test++) {
            long time = System.currentTimeMillis();
            out.print("Case #" + test + ": ");

            int d = in.nextInt();
            int k = in.nextInt();
            long[] s = new long[k];
            int minp = 0;
            for (int i = 0; i < k; i++) {
                s[i] = in.nextInt();
                if (s[i] + 1 > minp) {
                    minp = (int) s[i] + 1;
                }
            }

            if (k == 1) {
                out.println("I don't know.");
                continue;
            }
            if (k == 2) {
                if (s[0] != s[1]) {
                    out.println("I don't know.");
                } else {
                    out.println(s[0]);
                }
                continue;
            }

            int pi = 0;
            while (p[pi] < minp) {
                pi++;
            }
            Set<Long> ans = new HashSet<Long>();
            while (len[pi] <= d && pi < pn) {
                long P = p[pi];
                BigInteger PP = BigInteger.valueOf(P);

                long A, B;
                if (s[0] == s[1]) {
                    A = 1;
                    B = 0;
                } else {
                    A = (BigInteger.valueOf((s[0] - s[1] + P) % P).modInverse(PP).longValue() * (((s[1] - s[2]) % P + P) % P)) % P;
                    B = (((s[1] - A * s[0]) % P) + P) % P;
                }
                boolean ok = true;
                for (int i = 1; i < k; i++) {
                    if ((A * s[i - 1] + B) % P != s[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans.add((s[k - 1] * A + B) % P);
                    if (ans.size() > 1) {
                        break;
                    }
                }

                pi++;
            }

            if (ans.size() == 1) {
                out.println(ans.iterator().next());
            } else {
                if (ans.size() == 0) {
                    System.err.println("WRONG!");
                }
                out.println("I don't know.");
            }
//            System.err.println(System.currentTimeMillis() - time);
        }

        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().solve();
    }
}
