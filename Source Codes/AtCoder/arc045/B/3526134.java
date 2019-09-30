import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] S, T;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        S = new int[M];
        T = new int[M];
        for (int i = 0; i < M; i++) {
            S[i] = sc.nextInt() - 1;
            T[i] = sc.nextInt() - 1;
        }

        List<Integer> ans = solve();
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(ans.size());
        for (Integer i : ans) {
            pw.println(i);
        }
        pw.flush();
    }

    static List<Integer> solve() {
        // imos
        int[] imos = new int[N+1];
        for (int i = 0; i < M; i++) {
            imos[S[i]]++;
            imos[T[i]+1]--;
        }
        for (int i = 1; i < N + 1; i++) {
            imos[i] += imos[i-1];
        }

        // 2???????????
        int[] C = new int[N+1];
        C[0] = 0;
        for (int i = 1; i < N+1; i++) {
            C[i] = C[i-1] + (imos[i-1] > 1 ? 1 : 0);
        }

        // ????2????ok
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int s = S[i];
            int t = T[i];

            if( C[t+1] - C[s] == t - s + 1 ) {
                ans.add(i+1);
            }
        }
        return ans;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}