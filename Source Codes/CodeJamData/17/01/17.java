package rayker.gcj2017;

import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class Solver {
    public void solve(InputReader in, PrintWriter out) {
        int nTests = in.nextInt();
        for (int t = 1; t <= nTests; t++) {
            String v = in.next();
            int k = in.nextInt();
            print(t, out, find(v, k));
        }
    }

    private long find(String line, int k) {
        Boolean[] b = line.chars()
                .mapToObj(c -> c == '+')
                .toArray(Boolean[]::new);

        int count = 0;
        for (int i = 0; i < b.length; i++) {
            if (b[i]) continue;
            count++;
            for (int j = 0; j < k; j++) {
                if (i + j >= b.length) return -1;
                b[i + j] = !b[i + j];
            }
        }

        return count;
    }

    private void print(int t, PrintWriter out, long v) {
        if (v == -1) {
            out.printf("Case #%d: IMPOSSIBLE%n", t);
        } else {
            out.printf("Case #%d: %d%n", t, v);
        }
    }
}
