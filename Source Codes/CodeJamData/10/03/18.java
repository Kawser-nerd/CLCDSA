import java.util.Arrays;
import java.util.Scanner;

public class ThemePark {
    private long solve(int R, int K, int[] g) {
        long[] G = new long[g.length];
        int[] next = new int[g.length];
        int i = 0;
        int j = 0;
        while (G[i] == 0) {
            long sum = g[i];
            for (j = (i + 1) % g.length; j != i && (sum + g[j]) <= K; j = (j + 1) % g.length)
                sum += g[j];
            G[i] = sum;
            next[i] = j;
            i = j;
        }

        // detect a loop
        boolean[] m = new boolean[g.length];
        Arrays.fill(m, false);
        int p = 0;
        long start = 0;
        int sr = 0;
        while (!m[p]) {
            start += G[p];
            m[p] = true;
            sr++;
            p = next[p];
        }

        int q = p;
        long rsum = 0;
        int rr = 0;
        Arrays.fill(m, false);
        while (!m[q]) {
            rsum += G[q];
            m[q] = true;
            rr++;
            q = next[q];
        }

        if (R <= sr) {
            long res = 0;
            sr = 0;
            p = 0;
            while (sr < R) {
                res += G[p];
                sr++;
                p = next[p];
            }
            return res;
        } else {
            long res = start;
            R -= sr;
            res += (R / rr) * rsum;
            int left = R % rr;
            for (i = 0; i < left; ++i) {
                res += G[p];
                p = next[p];
            }

            return res;
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int count = s.nextInt();
        ThemePark instance = new ThemePark();
        for (int i = 0; i < count; ++i) {
            int r = s.nextInt();
            int k = s.nextInt();
            int n = s.nextInt();
            int[] g = new int[n];
            for (int j = 0; j < n; ++j)
                g[j] = s.nextInt();
            System.out.println("Case #" + (i + 1) + ": " + instance.solve(r, k, g));
        }
    }
}
