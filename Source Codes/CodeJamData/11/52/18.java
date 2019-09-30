import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class B {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    public void solveOne(String prefix) throws IOException {
        int n = nextInt();
        int[] count = new int[10000];
        for (int i = 0; i < n; ++i) {
            count[nextInt() - 1]++;
        }
        int ans = Integer.MAX_VALUE;
        ArrayDeque<Integer> q = new ArrayDeque<Integer>();
        for (int i = 0; i < count.length; ++i) {
            ArrayDeque<Integer> nq = new ArrayDeque<Integer>();
            while (count[i] > 0 && !q.isEmpty()) {
                nq.addLast(q.removeFirst() + 1);
                --count[i];
            }
            while (!q.isEmpty()) {
                ans = Math.min(ans, q.pollLast());
            }
            while (count[i] > 0) {
                nq.addFirst(1);
                --count[i];
            }
            q = nq;
        }
        while (!q.isEmpty()) {
            ans = Math.min(ans, q.pollLast());
        }
        out.println(prefix + (n == 0 ? 0 : ans));
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(B.class.getSimpleName() + ".in"));
        out = new PrintWriter(B.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }
}
