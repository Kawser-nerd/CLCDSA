import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextIntArray(N);

        List<Pair> ans = solve();
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(ans.size());
        for (Pair an : ans) {
            pw.println(an.x + " " + an.y);
        }

//        for (Pair p : ans) {
//            A[p.y-1] += A[p.x-1];
//        }
//        System.out.println(Arrays.toString(A));

        pw.flush();
    }

    static List<Pair> solve() {
        int max = 0;
        int maxIndex = -1;

        for (int i = 0; i < N; i++) {
            int abs = Math.abs(A[i]);

            if( abs > max ) {
                maxIndex = i;
                max = abs;
            }
        }

        if( max == 0 ) return Collections.emptyList();

        List<Pair> ans = new ArrayList<>();
        if( A[maxIndex] > 0 ) {
            for (int i = 0; i < N; i++) {
                ans.add( Pair.of(maxIndex, i) );
            }
            for (int i = 0; i < N-1; i++) {
                ans.add( Pair.of(i, i+1) );
            }

        } else {
            for (int i = 0; i < N; i++) {
                ans.add( Pair.of(maxIndex, i) );
            }
            for (int i = N-1; i > 0; i--) {
                ans.add( Pair.of(i, i-1) );
            }
        }
        return ans;
    }

    static class Pair {

        public static Pair of(int xi, int yi) {
            return new Pair(xi+1, yi+1);
        }

        // x?y???
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
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