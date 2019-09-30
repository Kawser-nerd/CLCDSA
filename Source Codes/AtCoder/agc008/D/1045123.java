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
            boolean[] check = new boolean[N + 1];
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                res[a] = i + 1;
                check[a] = true;
            }
            int sum = 0;
            for (int i = 1; i <= N; ++i) {
                if (res[i] > 0)
                    sum += res[i];
                if (i < sum) {
                    out.println("No");
                    return;
                }
            }
 
            sum = 0;
            for (int i = N; i > 0; --i) {
                if (res[i] > 0)
                    sum += n - res[i];
                if ((N - i + 1) < sum) {
                    out.println("No");
                    return;
                }
            }
 
            List<Integer> order = new ArrayList<>();
            for (int i = 1; i<=N; ++i) {
                if (res[i] > 0) order.add(res[i]);
            }
            int pos = 0;
            int cnt = order.get(0) - 1;
            outerloop:
            for (int i =1 ; i <=N; ++i) {
                if (res[i] > 0) continue;
                while (cnt == 0) {
                    pos++;
                    if (pos >= order.size()) break outerloop;
                    cnt = order.get(pos) - 1;
                }
                res[i] = order.get(pos);
                cnt--;
            }
 
            pos = order.size() - 1;
            cnt = n - order.get(order.size() - 1);
            outerloop1:
            for (int i = N; i > 0; --i) {
                if (res[i] > 0) continue;
                while (cnt == 0) {
                    pos--;
                    if (pos < 0) break outerloop1;
                    cnt = n - order.get(pos);
                }
                res[i] = order.get(pos);
                cnt--;
            }
            int[] freq = new int[n + 1];
            for (int i = 1; i <= N; ++i) {
//                if (res[i] == 0) call();
                freq[res[i]]++;
                if (!check[i]) continue;
                if (freq[res[i]] != res[i]) {
                    out.println("No");
                    return;
                }
 
            }
 
            out.println("Yes");
            for (int i = 1; i <= N; ++i) {
                if (i > 1) out.print(" ");
                out.print(res[i]);
            }
            out.println();
 
        }
 
        private void call() {
            throw new RuntimeException();
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