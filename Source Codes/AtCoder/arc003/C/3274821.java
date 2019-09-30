import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.function.DoublePredicate;

public class Main {

    static int H, W;
    static String[] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        C = new String[H];
        for (int h = 0; h < H; h++) {
            String s = sc.next();
            C[h] = s;
        }
        System.out.println(solve());
    }

    static int[] DH = {1, 0, -1, 0};
    static int[] DW = {0, 1, 0, -1};
    static int sh, sw;
    static int gh, gw;
    static double[] decay;
    static IntDeque q;
    static int[][] visitTime;

    static String solve() {
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h].charAt(w) == 'g' ) {
                    gh = h;
                    gw = w;
                } else if(C[h].charAt(w) == 's') {
                    sh = h;
                    sw = w;
                }
            }
        }

        decay = new double[H*W + 100];
        decay[0] = 1.0;
        for (int i = 1; i < decay.length; i++) {
            decay[i] = decay[i-1] * 0.99;
        }
        q = new IntDeque(H*W + 100);
        visitTime = new int[H][W];

        if( !canReachWithLimit(-1) ) return "-1";

        double ans = maximaize_d(0.0, 10.0, Main::canReachWithLimit);
        return BigDecimal.valueOf(ans).toPlainString();
    }

    static double maximaize_d(double lo, double hi, DoublePredicate p) {
        int time = 0;
        while(time++ < 35) {
            double x = (hi + lo) / 2;
            if( p.test(x) ) {
                lo = x;
            } else {
                hi = x;
            }
        }
        return lo;
    }

    static int hw(int h, int w) {
        return h * 1000 + w;
    }

    static int h(int hw) {
        return hw / 1000;
    }

    static int w(int hw) {
        return hw % 1000;
    }

    static boolean canReachWithLimit(double lightLimit) {
        q.clear();
        for (int[] arr : visitTime) {
            Arrays.fill(arr, -1);
        }

        visitTime[sh][sw] = 0;
        q.add( hw(sh, sw) );

        while ( !q.isEmpty() ) {
            int hw = q.poll();
            int h = h(hw);
            int w = w(hw);

            for (int i = 0; i < 4; i++) {
                int nh = h + DH[i];
                int nw = w + DW[i];

                if( nh < 0 || H <= nh || nw < 0 || W <= nw ) continue;
                if( C[nh].charAt(nw) == '#' ) continue;

                if( C[nh].charAt(nw) == 'g' ) {
                    return true; // reach

                } else {
                    if( visitTime[nh][nw] != -1 ) continue;

                    int nt = visitTime[h][w] + 1;
                    double nextLight = (C[nh].charAt(nw)-'0') * decay[nt];
                    if( nextLight < lightLimit ) continue;

                    visitTime[nh][nw] = nt;
                    q.add( hw(nh, nw) );
                }
            }
        }
        return false;
    }

    static class IntDeque {
        int[] queue;
        int in;
        int out;
        IntDeque(int n) {
            queue = new int[n];
            in = 0;
            out = 0;
        }

        int poll() {
            return queue[out++];
        }

        void add(int value) {
            queue[in++] = value;
        }

        boolean isEmpty() {
            return in == out;
        }

        void clear() {
            in = 0;
            out = 0;
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