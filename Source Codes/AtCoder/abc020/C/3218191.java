import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.function.IntPredicate;

public class Main {

    static int H;
    static int W;
    static int T;
    static char[][] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        T = sc.nextInt();
        C = new char[H][];
        for (int i = 0; i < H; i++) {
            C[i] = sc.next().toCharArray();
        }

        System.out.println(solve());
    }

    static int[] DH = new int[]{1, 0, -1, 0};
    static int[] DW = new int[]{0, 1, 0, -1};
    static int sh;
    static int sw;
    static int gh;
    static int gw;

    static int solve() {
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h][w] == 'G' ) {
                    gh = h;
                    gw = w;
                } else if( C[h][w] == 'S' ) {
                    sh = h;
                    sw = w;
                }
            }
        }

        return maximize(1, 1_000_000_000, x -> {
            PriorityQueue<State> q = new PriorityQueue<>();
            State[][] dist = new State[H][W];
            dist[sh][sw] = new State(sh, sw, 0, 0, x);
            q.add( dist[sh][sw] );

            while( !q.isEmpty() ) {
                State s = q.poll();
                if( s.compareTo(dist[s.h][s.w]) != 0 ) continue;

                for (int i = 0; i < 4; i++) {
                    int nh = s.h + DH[i];
                    int nw = s.w + DW[i];

                    if( nh < 0 || nh >= H || nw < 0 || nw >= W ) continue;

                    State ns = new State(nh, nw,
                            s.white + (!isBlack(nh, nw) ? 1 : 0),
                            s.black + (isBlack(nh, nw) ? 1 : 0),
                            x);

                    if( dist[nh][nw] == null || ns.compareTo(dist[nh][nw]) < 0 ) {
                        q.add(ns);
                        dist[nh][nw] = ns;
                    }
                }
            }

            State gd = dist[gh][gw];
            return gd.cost <= T;
        });
    }

    static boolean isBlack(int h, int w) {
        return C[h][w] == '#';
    }

    static int maximize(int lo, int hi, IntPredicate p) {
        while(lo < hi) {
            int x = ((hi - lo) >>> 1) + lo;
            if( p.test(x) ) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        return lo - 1;
    }

    static class State implements Comparable<State> {
        int h, w;
        int white, black;
        long cost;

        public State(int h, int w, int white, int black, int x) {
            this.h = h;
            this.w = w;
            this.white = white;
            this.black = black;
            this.cost = (long)x * black + white;
        }

        @Override
        public int compareTo(State o) {
            return Long.compare(cost, o.cost);
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