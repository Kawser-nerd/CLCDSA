import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("ratatouille.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("ratatouille.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Ratatouille solver = new Ratatouille();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Ratatouille {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int p = in.nextInt();
            int[] r = new int[n];
            for (int i = 0; i < n; i++) {
                r[i] = in.nextInt();
            }
            int[][] q = new int[n][p];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < p; j++) {
                    q[i][j] = in.nextInt();
                }
                Arrays.sort(q[i]);
            }
            int[] start = new int[n];
            int kits = 0;
            while (true) {
                boolean noMore = false;
                for (int i = 0; i < n; i++) {
                    if (start[i] == p) {
                        noMore = true;
                    }
                }
                if (noMore) {
                    break;
                }
                int makeServings = 0;
                for (int i = 0; i < n; i++) {
                    int minServings = servings(r[i], q[i][start[i]])[0];
                    makeServings = Math.max(makeServings, minServings);
                }
                boolean cantMake = false;
                for (int i = 0; i < n; i++) {
                    int maxServings = servings(r[i], q[i][start[i]])[1];
                    if (maxServings < makeServings) {
                        start[i]++;
                        cantMake = true;
                    }
                }
                if (cantMake) {
                    continue;
                }
                kits++;
                for (int i = 0; i < n; i++) {
                    start[i]++;
                }
            }
            out.println("Case #" + testNumber + ": " + kits);
        }

        int[] servings(int rat, int q) {
            int maxServings = q * 10 / (rat * 9);
            int minServings = (q * 10 + rat * 11 - 1) / (rat * 11);
            return new int[]{minServings, maxServings};
        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

