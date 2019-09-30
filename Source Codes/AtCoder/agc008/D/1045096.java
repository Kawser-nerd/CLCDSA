import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            final int n = in.nextInt();
            final int N = n * n;
            final int[] res = new int[N + 1];
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                res[a] = i + 1;
            }
            if (!(enoughSpaceLeft(res, n) && enoughSpaceRight(res, n))) {
                out.println("No");
                return;
            }

            List<Integer> order = new ArrayList<>();
            for (int i = 1; i<=N; ++i) {
                if (res[i] > 0) order.add(res[i]);
            }

            int pos = 0;
            int cnt = order.get(pos) - 1;
            for (int i =1 ; i <=N; ++i) {
                if (res[i] > 0) continue;
                while (cnt == 0) {
                    pos++;
                    if (pos >= n) break;
                    cnt = order.get(pos) - 1;
                }
                if (cnt == 0) break;
                res[i] = order.get(pos);
                cnt--;
            }

            pos = 0;
            cnt = n - order.get(pos);
            for (int i = 1; i <= N; ++i) {
                if (res[i] > 0) continue;
                while (cnt == 0) {
                    pos++;
                    if (pos >= n) break;
                    cnt = n - order.get(pos);
                }
                if (cnt == 0) break;
                res[i] = order.get(pos);
                cnt--;
            }

            out.println("Yes");
            for (int i = 1; i <= N; ++i) {
                if (i > 1) out.print(" ");
                out.print(res[i]);
            }
            out.println();

        }

        private boolean enoughSpaceRight(int[] res, int n) {
            int sum = 0;
            int N = n * n;
            for (int i = N; i > 0; --i) {
                if (res[i] > 0) sum += n - res[i] + 1;
                if ((N - i + 1) < sum) return false;
            }
            return true;
        }

        private boolean enoughSpaceLeft(int[] res, int n) {
            int sum = 0;
            int N = n * n;
            for (int i = 1; i <= N; ++i) {
                if (res[i] > 0) sum += res[i];
                if (i < sum) return false;
            }
            return true;
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