import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M;
    static int X0, A, P;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        X0 = sc.nextInt();
        A = sc.nextInt();
        P = sc.nextInt();

        System.out.println(solve());
    }

    static long solve() {
        if( A % P == 0 ) {
            if( X0 >= P ) {
                // X0, X0%P, X0%P...
                // ????????
                return 2 * (N-1);

            } else {
                // ????(X0)
                return 0;
            }
        }

        int x = X0;
        Student[] S = new Student[N*M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int idx = i*M+j;
                S[idx] = new Student(i, j, x);
                x = (x + A) % P;
            }
        }
        Arrays.sort(S, Comparator.comparingInt(s -> s.x));

        long ans = 0;
        for (int i = 0; i < N; i++) {

            int start = i * M;
            Arrays.sort(S, start, start+M, Comparator.comparingInt(s -> s.j));

            for (int j = 0; j < M; j++) {
                ans += Math.abs(S[start+j].i - i);
                ans += Math.abs(S[start+j].j - j);
            }
        }
        return ans;
    }

    static class Student {
        int i, j; // ????
        int x; // ??

        public Student(int i, int j, int x) {
            this.i = i;
            this.j = j;
            this.x = x;
        }
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