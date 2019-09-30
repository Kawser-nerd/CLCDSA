import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int R, G, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        R = fc.nextInt();
        G = fc.nextInt();
        B = fc.nextInt();
        System.out.println(solve());
    }

    static int solve() {
        // G??????? -> ??????R, B???????
        // G????????R, B????????????????????
        //   ?????G????[460, -460]??????(???)
        //   R, B?300, 300????R?50???????? B?450???????????
        int ans = Integer.MAX_VALUE;
        for (int gl = -500; gl <= 500; gl++) {
            // G = [gl, gr]
            int gr = gl + G - 1;
            int gp = calc(gl, gr, 0);
            int rp = calcR(gl);
            int bp = calcB(gr);

            ans = Math.min(gp + rp + bp, ans);
        }
        return ans;
    }

    static int calcR(int gl) {
        // ??????
        int l = -100 - R/2;
        int r = -100 + (R-1)/2;

        if( gl <= r ) {
            int push = r - gl + 1;
            l -= push;
            r -= push;
        }

        return calc(l, r, -100);
    }

    static int calcB(int gr) {
        int l = 100 - (B-1)/2;
        int r = 100 + B/2;

        if( gr >= l ) {
            int push = gr - l + 1;
            l += push;
            r += push;
        }

        return calc(l, r, 100);
    }

    static int calc(int l, int r, int z) {
        if( r < z ) {
            return calc(l-z, r-z);

        } else if( l > z ) {
            return calc(l-z, r-z);

        } else {
            return calc(l-z, 0) + calc(z-r, 0);
        }
    }

    // l?r???????????
    static int calc(int l, int r) {
        int add = Math.abs(l + r);
        int sub = Math.abs(r - l);

        if( sub % 2 == 0 ) {
            return (add / 2) * (sub+1);
        } else {
            return add * ((sub + 1) / 2);
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