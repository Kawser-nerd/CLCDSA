import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int R, C, N;
    static Pair[] P;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        N = sc.nextInt();

        P = new Pair[N];
        for (int i = 0; i < N; i++) {
            P[i] = new Pair(new Cord(sc.nextInt(), sc.nextInt(), i), new Cord(sc.nextInt(), sc.nextInt(), i) );
        }

        System.out.println(solve() ? "YES" : "NO");
    }

    static class Pair {
        Cord a;
        Cord b;

        public Pair(Cord a, Cord b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Cord implements Comparable<Cord> {
        int x, y, i;

        public Cord(int x, int y, int i) {
            this.x = x;
            this.y = y;
            this.i = i;
        }

        public String toString() {
            return "(" + x + "," + y + "," + i + ")";
        }

        @Override
        public int compareTo(Cord c) {
            int t = type();
            int ct = c.type();
            if( t != ct ) {
                return Integer.compare(t, ct);
            }

            if( t == 1 ) {
                return Integer.compare(y, c.y);
            } else if( t == 2 ) {
                return Integer.compare(x, c.x);
            } else if( t == 3 ) {
                return Integer.compare(c.y, y);
            } else {
                return Integer.compare(c.x, x);
            }
        }

        int type() {
            if( x == 0 ) {
                return 1;
            } else if ( y == C ) {
                return 2;
            } else if( x == R ) {
                return 3;
            } else if( y == 0 ) {
                return 4;
            } else {
                throw new RuntimeException("wtf : " + x + " " + y);
            }
        }

        public boolean isOnEdge() {
            return x == 0 || y == 0 || x == R || y == C;
        }
    }

    static boolean solve() {
        List<Cord> onEdges = new ArrayList<>();
        for (Pair pair : P) {
            if( pair.a.isOnEdge() && pair.b.isOnEdge() ) {
                onEdges.add(pair.a);
                onEdges.add(pair.b);
            }
        }

        onEdges.sort(Comparator.naturalOrder());

        // System.out.println( onEdges );

        Set<Integer> set = new HashSet<>();
        LinkedList<Cord> stack = new LinkedList<>();

        for (Cord c : onEdges) {
            if( !set.contains(c.i) ) {
                stack.addFirst(c);
                set.add(c.i);
            } else {
                Cord inStack = stack.removeFirst();
                if( inStack.i != c.i ) return false;
            }
        }
        return true;
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