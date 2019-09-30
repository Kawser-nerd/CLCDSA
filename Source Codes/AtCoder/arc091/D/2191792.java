import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author palayutm
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            long ans = 0;
            for (int i = 0; i < n; i++) {
                long A = in.nextInt(), B = in.nextInt();
                if (A >= B) {
                    while (true) {
                        if (A < B) {
                            break;
                        }
                        long x = A / B + 1;
                        long low = 0, high = A / x;
                        while (low <= high) {
                            long mid = (low + high) / 2;
                            if ((A - mid * x) / B + 1 == x) low = mid + 1;
                            else high = mid - 1;
                        }
                        //out.println(low + " high");
                        A -= high * x;
                        //out.println(A + " B");
                        if (A % B == 0) {
                            ans ^= (A / B);
                            break;
                        }
                        A = (A - x);
                        //out.println(A + " A");
                /*long x = A / B + 1;
                A = B * x + (A % x);
                if (A % B == 0) {
                    ans ^= (A / B);
                    break;
                }
                A -= (x);*/
                    }
                }
                //out.println(ans);
            }
            if (ans != 0) {
                out.println("Takahashi");
            } else {
                out.println("Aoki");
            }

        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream out) {
            super(out);
        }

        public OutputWriter(Writer out) {
            super(out);
        }

        public void close() {
            super.close();
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