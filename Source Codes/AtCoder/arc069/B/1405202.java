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
 *
 * @author toshif
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private int n;
        private char[] cs;

        public void solve(int testNumber, MyReader in, PrintWriter out) {
            n = in.nextInt();
            String s = in.next();
            cs = s.toCharArray();

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    int[] a = new int[n];
                    a[0] = i;
                    a[1] = j;
                    if (cal(a)) {
                        for (int k = 0; k < n; k++) {
                            if (a[k] == 1) {
                                out.print("S");
                            } else {
                                out.print("W");
                            }
                        }
                        out.println();
                        return;
                    }
                }
            }

            out.println(-1);
        }

        boolean cal(int[] a) {
            // 1 : s , 0, w
            for (int i = 2; i < n; i++) {
                if (cs[i - 1] == 'o') {
                    if (a[i - 1] == 1) {
                        a[i] = a[i - 2];
                    } else {
                        a[i] = a[i - 2] ^ 1;
                    }
                } else {
                    if (a[i - 1] == 1) {
                        a[i] = a[i - 2] ^ 1;
                    } else {
                        a[i] = a[i - 2];
                    }
                }
            }

            // check 0
            if (a[0] == 1) {
                if (cs[0] == 'o') {
                    if (a[1] != a[n - 1]) return false;
                }
                if (cs[0] == 'x') {
                    if (a[1] == a[n - 1]) return false;
                }
            } else {
                if (cs[0] == 'o') {
                    if (a[1] == a[n - 1]) return false;
                }
                if (cs[0] == 'x') {
                    if (a[1] != a[n - 1]) return false;
                }
            }

            // check n-1
            if (cs[n - 1] == 'o') {
                if (a[n - 1] == 1) {
                    return a[n - 2] == a[0];
                } else {
                    return a[n - 2] != a[0];
                }
            } else {
                if (a[n - 1] == 1) {
                    return a[n - 2] != a[0];
                } else {
                    return a[n - 2] == a[0];
                }
            }
        }

    }

    static class MyReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public MyReader(InputStream stream) {
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