import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static long K;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        K = sc.nextLong();

        long[] array = solve();
        StringJoiner j = new StringJoiner(" ");
        for (long each : array) {
            j.add(String.valueOf(each));
        }
        System.out.println( array.length );
        System.out.println( j.toString() );
    }

    static long[] solve() {
        long[] answer = new long[50];

        long d = K / 50;
        int r = (int)(K % 50);

        Arrays.fill(answer, d + 49);

        for (int i = 0; i < r; i++) {
            answer[i] ++;
        }
        for (int i = r; i < 50; i++) {
            answer[i] -= r;
        }
        return answer;
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