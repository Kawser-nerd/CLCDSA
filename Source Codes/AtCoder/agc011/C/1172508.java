import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    int n, m;
    List<Integer>[] edge;
    int[] ok;

    void solve() {
        try (Scanner in = new Scanner(System.in)) {
            n = in.nextInt();
            m = in.nextInt();
            edge = new List[n];
            for (int i = 0; i < n; ++i) {
                edge[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                edge[u].add(v);
                edge[v].add(u);
            }
            ok = new int[n];
            Arrays.fill(ok, -1);
            long c1 = 0, c2 = 0, c3 = 0;
            for (int i = 0; i < n; ++i) {
                if (ok[i] != -1) continue;
                Pair x = dfs(i, 0);
                if (x.c == 1) ++c1;
                else if (!x.b) ++c2;
                else ++c3;
            }
            System.out.println(c1 * c1 + 2 * c1 * (n - c1) + 2 * c2 * c2 + 2 * c2 * c3 + c3 * c3);
        }
    }

    Pair dfs(int p, int b) {
        ok[p] = b;
        Pair x = new Pair(1, false);
        for (int n : edge[p]) {
            if (ok[n] == -1) {
                Pair t = dfs(n, 1 - b);
                x.c += t.c;
                x.b |= t.b;
            } else {
                x.b |= b == ok[n];
            }
        }
        return x;
    }

    class Pair {
        int c;
        boolean b;

        Pair(int c, boolean b) {
            this.c = c;
            this.b = b;
        }
    }

    void tr(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.