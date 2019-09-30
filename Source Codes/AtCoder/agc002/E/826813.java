import java.io.OutputStream;
import java.io.IOException;
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
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            for (int i = 0; i < n - 1 - i; ++i) {
                int j = n - 1 - i;
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            boolean[] inverted = new boolean[n];
            for (int i = n - 2; i >= 0; --i) if (a[i] == a[i + 1]) inverted[i] = !inverted[i + 1];
            int row = 0;
            int col = 0;
            while (true) {
                ++row;
                ++col;
                if (col >= a.length || row >= a[col]) break;
            }
            --row;
            --col;
            if (row == a[col] - 1) {
                if (inverted[col]) {
                    out.println("First");
                } else {
                    out.println("Second");
                }
            } else {
                if ((col + 1 < a.length && row == a[col + 1] - 1 && !inverted[col + 1]) || (a[col] - row) % 2 == 0) {
                    out.println("First");
                } else {
                    out.println("Second");
                }
            }
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