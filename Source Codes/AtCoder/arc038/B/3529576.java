import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int H, W;
    static char[][] S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        S = new char[H][];
        for (int i = 0; i < H; i++) {
            S[i] = sc.next().toCharArray();
        }

        System.out.println(solve() ? "First" : "Second");
    }

    static int[] DH = {0, 1, 1};
    static int[] DW = {1, 0, 1};

    static boolean solve() {
        for (Cord c : bfs()) {
            S[c.h][c.w] = winLose(c.h, c.w) ? 'W' : 'L';
        }
//        for (int i = 0; i < H; i++) {
//            System.out.println( Arrays.toString(S[i]) );
//        }
        return S[0][0] == 'W';
    }

    static List<Cord> bfs() {
        PriorityQueue<Cord> q = new PriorityQueue<>();
        List<Cord> result = new ArrayList<>();
        Set<Cord> done = new HashSet<>();
        Cord first = new Cord(0, 0);
        q.add(first);
        done.add(first);
        result.add(first);

        while( !q.isEmpty() ) {
            Cord c = q.poll();

            for (int i = 0; i < 3; i++) {
                int nh = c.h + DH[i];
                int nw = c.w + DW[i];
                Cord n = new Cord(nh, nw);
                if( inRange(nh, nw) && S[nh][nw] == '.' && !done.contains(n)) {
                    q.add(n);
                    result.add(n);
                    done.add(n);
                }
            }
        }

        Collections.reverse(result);
        return result;
    }

    static boolean winLose(int h, int w) {
        for (int i = 0; i < 3; i++) {
            int nh = h + DH[i];
            int nw = w + DW[i];

//            if( inRange(nh, nw) && S[nh][nw] == '.' ) {
//                throw new RuntimeException("wtf: " + h + " " + w + " " + nh + " " + nw);
//            }

            if( inRange(nh, nw) && S[nh][nw] == 'L' ) return true;
        }
        return false;
    }

    static boolean inRange(int h, int w) {
        return 0 <= h && h < H && 0 <= w && w < W;
    }

    static class Cord implements Comparable<Cord> {
        int h, w;

        public Cord(int h, int w) {
            this.h = h;
            this.w = w;
        }

        @Override
        public int compareTo(Cord o) {
            return Integer.compare(h+w, o.h + o.w);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Cord cord = (Cord) o;
            return h == cord.h &&
                    w == cord.w;
        }

        @Override
        public int hashCode() {
            return Objects.hash(h, w);
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