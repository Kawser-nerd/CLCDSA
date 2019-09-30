import java.io.*;
import java.util.StringTokenizer;
import java.util.function.LongBinaryOperator;

public class Main {

    static int K;
    static int M;
    static long[] A;
    static long[] C;

    static LongBinaryOperator AND = (a, b) -> a & b;
    static LongBinaryOperator XOR = (a, b) -> a ^ b;
    static long ONE = (long)Math.pow(2, 32) - 1;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        K = sc.nextInt();
        M = sc.nextInt();
        A = sc.nextLongArray(K);
        C = sc.nextLongArray(K);

        System.out.println( solve() );
    }

    static long solve() {
        if( M <= K ) return A[M-1];

        LongMat mat = new LongMat(K, K);
        for (int i = 0; i < K - 1; i++) {
            mat.set(i+1, i, ONE);
        }
        for (int i = 0; i < K; i++) {
            mat.set(i, K-1, C[K-i-1]);
        }

        int APP = M - K;
        int bits = Long.toBinaryString(APP).length();
        LongMat[] MAT = new LongMat[bits];
        MAT[0] = mat;
        for (int i = 1; i < bits; i++) {
            MAT[i] = LongMat.dot(MAT[i-1], MAT[i-1], AND, XOR);
        }

        LongMat vec = new LongMat(A, false); // yoko
        for (int b = 0; b < bits; b++) {
            if( (APP & 1L << b) > 0 ) {
                vec = LongMat.dot(vec, MAT[b], AND, XOR);
            }
        }
        return vec.get(0, K-1);
    }

    static class LongMat {

        final long[][] mat;

        LongMat(int r, int c) {
            mat = new long[r][c];
        }

        LongMat(long[][] mat) {
            this.mat = mat;
        }

        LongMat(long[] vec, boolean tate) {
            if( tate ) {
                mat = new long[vec.length][1];
                for (int i = 0; i < vec.length; i++) {
                    mat[i][0] = vec[i];
                }

            } else {
                mat = new long[1][vec.length];
                System.arraycopy(vec, 0, mat[0], 0, vec.length);
            }
        }

        static LongMat dot(LongMat a, LongMat b) {
            return dot(a, b, (i, j) -> i*j, (i, j) -> i+j);
        }

        static LongMat dot(LongMat a, LongMat b, LongBinaryOperator mul, LongBinaryOperator add) {
            long[][] ret = new long[a.row()][b.col()];

            for (int r = 0; r < a.row(); r++) {
                for (int c = 0; c < b.col(); c++) {
                    long sum = 0;
                    for (int i = 0; i < b.row(); i++) {
                        sum = add.applyAsLong(sum, mul.applyAsLong(a.get(r, i), b.get(i, c)));
                    }
                    ret[r][c] = sum;
                }
            }
            return new LongMat(ret);
        }

        void set(int r, int c, long n) {
            mat[r][c] = n;
        }

        long get(int r, int c) {
            try {
                return mat[r][c];
            } catch( ArrayIndexOutOfBoundsException e ) {
                throw new RuntimeException("wrong index : r=" + r + " c=" + c + " row=" + row() + " col=" + col());
            }
        }

        int row() {
            return mat.length;
        }

        int col() {
            return mat[0].length;
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