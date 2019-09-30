import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] cnt = new int[100];
            int n = in.nextInt();
            for (int i = 1; i <= n; i++) {
                int k = i;
                for (int j = 2; j * j <= k; j++) {
                    while (k % j == 0) {
                        cnt[j]++;
                        k /= j;
                    }
                }
                if (k > 1) {
                    cnt[k]++;
                }
            }
            int ans = 0;
            int tmp = 0;
            for (int i = 1; i < 100; i++) {
                for (int j = 1; j < 100; j++) {
                    for (int k = 1; k < 100; k++) {
                        if (i == j || j == k || k == i) continue;
                        if (cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4) {
                            tmp++;
                        }
                    }
                }
            }
            ans += tmp / 2;
            for (int i = 1; i < 100; i++) {
                for (int j = 1; j < 100; j++) {
                    if (i == j) continue;
                    if (cnt[i] >= 14 && cnt[j] >= 4) ans++;
                    if (cnt[i] >= 24 && cnt[j] >= 2) ans++;
                }
            }
            for (int i = 1; i < 100; i++) {
                if (cnt[i] >= 74) ans++;
            }
            out.println(ans);
        }
    }

    public static void main(String argds[]) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
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