import java.io.*;
import java.util.*;

public class C {
    PrintWriter out;
    Scanner in;
    String testCase = "c2";

    public static void main(String[] args) throws Exception {
        new C().solve();
    }

    int INF = 1000000000;

    int P, Q;
    int[] a;
    int[][] mem;

    int findMax(int left, int right) {
        if (mem[left][right] != INF) {
            return mem[left][right];
        }

        int ans = INF;
        for (int i = left + 1; i < right; ++i) {
            int newSol = a[right] - a[left] - 2 + findMax(left, i) + findMax(i, right);
            ans = Math.min(ans, newSol);
        }

        if (ans == INF) {
            ans = 0;
        }

        mem[left][right] = ans;
        return ans;
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream(testCase + ".out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(testCase + ".in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");

            P = in.nextInt();
            Q = in.nextInt();
            a = new int[Q + 2];
            a[0] = 0;
            for (int i = 0; i < Q; ++i) {
                a[i + 1] = in.nextInt();
            }
            a[Q + 1] = P + 1;

            Arrays.sort(a);
            mem = new int[Q + 2][Q + 2];
            for (int i = 0; i <= Q + 1; ++i) {
                for (int j = 0; j <= Q + 1; ++j) {
                    mem[i][j] = INF;
                }
            }

            out.println(findMax(0, Q + 1));
        }

        out.close();
    }
}
