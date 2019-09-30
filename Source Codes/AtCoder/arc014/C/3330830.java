import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static String S;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        S = fc.next();
        System.out.println(solve());
    }

    static int solve() {
        State s = new Zero();
        for (int i = 0; i < N; i++) {
            s = s.next(S.charAt(i));
        }
        return s.num();
    }

    interface State {
        State next(char c);

        int num();
    }

    static class Zero implements State {
        @Override
        public State next(char c) {
            return new One(c);
        }

        @Override
        public int num() {
            return 0;
        }
    }

    static class One implements State {

        final char c;

        public One(char c) {
            this.c = c;
        }

        @Override
        public State next(char c) {
            if( this.c == c ) {
                return new Zero();
            } else {
                return new Two(this.c, c);
            }
        }

        @Override
        public int num() {
            return 1;
        }
    }

    static class Two implements State {

        char c1, c2;

        public Two(char c1, char c2) {
            this.c1 = c1;
            this.c2 = c2;
        }

        @Override
        public State next(char c) {
            if( c1 == c ) {
                return new One(c2);
            } else if( c2 == c ) {
                return new One(c1);
            } else {
                return new Three();
            }
        }

        @Override
        public int num() {
            return 2;
        }
    }

    static class Three implements State {
        @Override
        public State next(char c) {
            if( c == 'R' ) {
                return new Two('G', 'B');
            } else if( c == 'G' ) {
                return new Two('R', 'B');
            } else if( c == 'B' ){
                return new Two('R', 'G');
            } else {
                throw new IllegalArgumentException("wtf : " + c);
            }
        }

        @Override
        public int num() {
            return 3;
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