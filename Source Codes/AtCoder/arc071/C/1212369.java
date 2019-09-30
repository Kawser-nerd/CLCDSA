import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.nextString();
            String t = in.nextString();
            int q = in.nextInt();
            int[] a = new int[q];
            int[] b = new int[q];
            int[] c = new int[q];
            int[] d = new int[q];
            for (int i = 0; i < q; i++) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt() - 1;
                c[i] = in.nextInt() - 1;
                d[i] = in.nextInt() - 1;
            }

            int n = s.length();
            int m = t.length();

            int[] sumS = new int[n + 1];
            for (int i = 0; i < n; i++) {
                sumS[i + 1] = s.charAt(i) == 'A' ? 1 : 2;
            }
            for (int i = 0; i < n; i++) {
                sumS[i + 1] += sumS[i];
            }

            int[] sumT = new int[m + 1];
            for (int i = 0; i < m; i++) {
                sumT[i + 1] = t.charAt(i) == 'A' ? 1 : 2;
            }
            for (int i = 0; i < m; i++) {
                sumT[i + 1] += sumT[i];
            }

            for (int i = 0; i < q; i++) {
                int x = sumS[b[i] + 1] - sumS[a[i]];
                int y = sumT[d[i] + 1] - sumT[c[i]];

                out.println(x % 3 == y % 3 ? "YES" : "NO");
            }
        }

    }

    static class InputReader {
        private BufferedReader in;
        private StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}