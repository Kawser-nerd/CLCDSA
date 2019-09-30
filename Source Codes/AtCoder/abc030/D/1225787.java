import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int a = in.nextInt() - 1;
            String k = in.nextString();
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                b[i] = in.nextInt() - 1;
            }

            int now = a;
            if (k.length() <= 6) {
                int m = Integer.parseInt(k);
                for (int i = 0; i < m; i++) {
                    now = b[now];
                }

                out.println(now + 1);
                return;
            }

            int[] prevVisit = new int[n];
            Arrays.fill(prevVisit, -1);

            int cnt = 0;
            int s;
            while (true) {
                prevVisit[now] = cnt;
                cnt++;

                now = b[now];
                if (prevVisit[now] != -1) {
                    s = cnt - prevVisit[now];
                    break;
                }
            }

            BigInteger biK = new BigInteger(k);
            biK = biK.subtract(new BigInteger(String.valueOf(cnt)));
            biK = biK.mod(new BigInteger(String.valueOf(s)));

            int m = Integer.parseInt(biK.toString());
            for (int i = 0; i < m; i++) {
                now = b[now];
            }

            out.println(now + 1);
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

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