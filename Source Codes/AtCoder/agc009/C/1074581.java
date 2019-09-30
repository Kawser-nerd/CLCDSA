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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final long INF = (long) 3e18;
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long a = in.nextLong();
            long b = in.nextLong();
            long[] s = new long[n + 4];
            for (int i = 0; i < n; ++i) {
                s[i + 2] = in.nextLong();
            }
            s[0] = -INF;
            s[1] = -INF;
            s[n + 2] = INF;
            s[n + 3] = INF;
            int[] waysA = new int[s.length];
            int[] waysB = new int[s.length];
            int[] psumA = new int[s.length + 1];
            int[] psumB = new int[s.length + 1];
            waysA[1] = 1;
            psumA[2] = 1;
            int canTakeBs = -1;
            int canTakeAs = -1;
            int ptrA = -1;
            int ptrB = -1;
            for (int i = 2; i < s.length; ++i) {
                if (s[i - 1] - s[i - 2] >= b) {
                    ++canTakeBs;
                } else {
                    canTakeBs = 0;
                }
                while (s[i] - s[ptrA + 1] >= a) {
                    ++ptrA;
                }
                int leftB = Math.max(1, i - 1 - ptrA);
                int rightB = canTakeBs + 1;
                if (leftB <= rightB) {
                    waysA[i] = psumB[i - leftB + 1] - psumB[i - rightB];
                    if (waysA[i] < 0) waysA[i] += MODULO;
                }
                if (s[i - 1] - s[i - 2] >= a) {
                    ++canTakeAs;
                } else {
                    canTakeAs = 0;
                }
                while (s[i] - s[ptrB + 1] >= b) {
                    ++ptrB;
                }
                int leftA = Math.max(1, i - 1 - ptrB);
                int rightA = canTakeAs + 1;
                if (leftA <= rightA) {
                    waysB[i] = psumA[i - leftA + 1] - psumA[i - rightA];
                    if (waysB[i] < 0) waysB[i] += MODULO;
                }
                psumA[i + 1] = psumA[i] + waysA[i];
                if (psumA[i + 1] >= MODULO) psumA[i + 1] -= MODULO;
                psumB[i + 1] = psumB[i] + waysB[i];
                if (psumB[i + 1] >= MODULO) psumB[i + 1] -= MODULO;
            }
            out.println(waysA[s.length - 1]);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}