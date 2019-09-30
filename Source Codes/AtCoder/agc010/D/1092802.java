import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            if (firstWins(a)) {
                out.println("First");
            } else {
                out.println("Second");
            }
        }

        private boolean firstWins(int[] a) {
            long s = 0;
            for (int b : a) s += b - 1;
            if (s % 2 != 0) {
                return true;
            }
            int oddPos = -1;
            for (int i = 0; i < a.length; ++i) {
                if (a[i] % 2 != 0) {
                    if (oddPos >= 0) return false;
                    oddPos = i;
                }
            }
            if (oddPos < 0) throw new RuntimeException();
            if (a[oddPos] == 1) return false;
            --a[oddPos];
            int g = 0;
            for (int x : a) g = gcd(g, x);
            if (g == 1) throw new RuntimeException();
            for (int i = 0; i < a.length; ++i) {
                a[i] /= g;
            }
            return !firstWins(a);
        }

        private int gcd(int a, int b) {
            while (b > 0) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}