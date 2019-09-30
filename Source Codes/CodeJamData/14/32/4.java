import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by ab on 5/11/14.
 */
public class B {
    private final Scanner in;
    private final PrintWriter out;

    public B(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(new FileReader(new File("B-large.in")));
             PrintWriter out = new PrintWriter("B-large.out")) {
            new B(in, out).solve();
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(-1);
        }
    }


    final long MOD = 1_000_000_007;

    private void solve() {


        int tests = in.nextInt();
        for (int test = 1; test <= tests; ++test) {
            System.out.println(test);

            int n = in.nextInt();
            String[] w = new String[n];
            for (int i = 0; i < w.length; ++i) {
                w[i] = in.next();
            }

            out.println("Case #" + test + ": " + calc(w));
        }
    }

    private long calc(String[] w) {
        int[] cnt = new int['z' - 'a' + 1];
        for (int i = 0; i < w.length; ++i) {
            String s = w[i];
            char a = s.charAt(0);
            char b = s.charAt(s.length() - 1);
            if (a != b) continue;
            for (char c : s.toCharArray()) {
                if (c != a) return 0;
            }
            cnt[a - 'a']++;
            w[i] = null;
        }

        long[] C = new long[w.length];
        Arrays.fill(C, 1);
        for (int i = 0; i < w.length; ++i) {
            String s = w[i];
            if (s == null) continue;
            int a = s.charAt(0) - 'a';
            int b = s.charAt(s.length() - 1) - 'a';

            while (cnt[a] > 0) {
                C[i] = C[i] * cnt[a] % MOD;
                --cnt[a];
            }

            while (cnt[b] > 0) {
                C[i] = C[i] * cnt[b] % MOD;
                --cnt[b];
            }
        }

        int[] H = new int[cnt.length];
        int[] T = new int[cnt.length];

        Arrays.fill(H, -1);
        Arrays.fill(T, -1);

        for (int i = 0; i < w.length; ++i) {
            String s = w[i];
            if (s == null) continue;
            int a = s.charAt(0) - 'a';
            int b = s.charAt(s.length() - 1) - 'a';

            if (a == b) throw new Error();

            if (H[a] != -1) return 0;
            H[a] = i;
            if (T[b] != -1) return 0;
            T[b] = i;
        }

        loop:
        while (true) {
//            System.out.println(Arrays.toString(w));
//            System.out.println(Arrays.toString(C));
            for (int i = 0; i < w.length; ++i) {
                String s = w[i];
                if (s == null) continue;
                int a = s.charAt(0) - 'a';
                int b = s.charAt(s.length() - 1) - 'a';
                if (H[a] != i) throw new Error();

                if (H[b] != -1) {
                    int j = H[b];
                    if (i == j) return 0;
                    C[i] = C[i] * C[j] % MOD;
                    w[i] += w[j];
                    w[j] = null;
                    H[b] = -1;
                    T[b] = -1;
                    T[w[i].charAt(w[i].length() - 1) - 'a'] = i;
                    continue loop;
                }
            }
            break;
        }

        int groups = 0;
        long ans = 1;

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] != 0) {
                ++groups;
                ans = ans * groups % MOD;
                while (cnt[i] > 0) {
                    ans = ans * cnt[i] % MOD;
                    --cnt[i];
                }
                sb.append((char)(i + 'a'));
            }
        }

        for (int i = 0; i < w.length; ++i) {
            String s = w[i];
            if (s == null) continue;
            ++groups;
            ans = ans * C[i] % MOD;
            ans = ans * groups % MOD;
            sb.append(s);
        }

        boolean[] u = new boolean[cnt.length];
        String res = sb.toString();
//        System.out.println(res);
        int p = -1;
        for (int i = 0; i < res.length(); ++i) {
            int c = res.charAt(i) - 'a';
            if (c != p) {
                if (u[c]) return 0;
                u[c] = true;
            }
            p = c;
        }

        return ans;
    }

}
