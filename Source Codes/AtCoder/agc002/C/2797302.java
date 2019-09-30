import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int L;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);

        N = sc.nextInt();
        L = sc.nextInt();
        A = sc.nextIntArray(N);

        PrintWriter pw = new PrintWriter(System.out);
        Answer answer = solve();
        if( answer != null ) {
            pw.println("Possible");
            for (Integer each : answer.values) {
                pw.println(each);
            }
        } else {
            pw.println("Impossible");
        }
        pw.flush();
    }

    static Answer solve() {
        int safe = -1;
        for (int i = 1; i <= N-1; i++) {
            if( A[i-1] + A[i] >= L ) {
                safe = i;
                break;
            }
        }
        if( safe == -1 ) return null;

        List<Integer> values = new ArrayList<>(N-1);

        for (int i = 1; i < safe; i++) {
            values.add(i);
        }
        for (int i = N-1; i > safe ; i--) {
            values.add(i);
        }
        values.add(safe);

        return new Answer(values);
    }

    static class Answer {
        List<Integer> values;

        public Answer(List<Integer> values) {
            this.values = values;
        }
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