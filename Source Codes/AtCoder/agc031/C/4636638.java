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
        CDifferBy1Bit solver = new CDifferBy1Bit();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDifferBy1Bit {

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();

            if (Integer.bitCount(a ^ b) % 2 == 0) {
                out.println("NO");
                return;
            }

            int[] num = new int[1 << n];
            doit(a, b, n - 1, 0, (1 << n) - 1, num, new int[1 << n]);
            out.println("YES");
            for (int i = 0; i < 1 << n; i++) {
                out.print(num[i]);
                out.print(' ');
            }
        }

        private void doit(int a, int b, int bit, int l, int r, int[] num, int[] temp) {
            assert Integer.bitCount(a ^ b) % 2 == 1;
            if (bit == 0) {
                num[l] = a;
                num[r] = b;
                return;
            }
            if ((a & (1 << bit)) != (b & (1 << bit))) {
                doit(a, a ^ 1, bit - 1, l, (l + r) / 2, num, temp);
                doit((a ^ 1) ^ (1 << bit), b, bit - 1, (l + r) / 2 + 1, r, num, temp);
            } else {
                doit(a, b, bit - 1, l, (l + r) / 2, temp, num);
                num[l] = temp[l];
                int pos = (l + r) / 2 + 2;
                for (int i = l + 1; i <= (l + r) / 2; i++) {
                    num[pos++] = temp[i];
                }
                doit(a ^ (1 << bit), temp[l + 1] ^ (1 << bit), bit - 1, l + 1, (l + r) / 2 + 1, num, temp);
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