import java.io.*;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] P;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        P = sc.nextIntArray(N);

        PrintWriter pw = new PrintWriter(System.out);
        Answer ans = solve();

        StringJoiner j = new StringJoiner(" ");
        for (int a : ans.a) {
            j.add(String.valueOf(a));
        }
        pw.println(j.toString());

        StringJoiner k = new StringJoiner(" ");
        for (int b : ans.b) {
            k.add(String.valueOf(b));
        }
        pw.println(k.toString());
        pw.flush();
    }

    static class Answer {
        int[] a;
        int[] b;

        public Answer(int[] a, int[] b) {
            this.a = a;
            this.b = b;
        }
    }

    static Answer solve() {
        int[] amos = new int[N];
        int[] bmos = new int[N];
        for (int i = 0; i < N; i++) {
            int p = P[i];
            if( p != N ) {
                // index = p-1
                // index+1 = p
                amos[p] = N - i;
            }
            if( p != 1 ) {
                // index = p-1
                // index-1 = p-2
                bmos[p-2] = N - i;
            }
        }

        int[] a = new int[N];
        int a_rui = 0;
        for (int i = 0; i < N; i++) {
            a_rui += amos[i];
            a[i] = (i+1) + a_rui;
        }

        int[] b = new int[N];
        int b_rui = 0;
        for (int i = N-1; i >= 0; i--) {
            b_rui += bmos[i];
            b[i] = N-i + b_rui;
        }

        return new Answer(a, b);
    }

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

        double nextDouble() {
            return Double.parseDouble(next());
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