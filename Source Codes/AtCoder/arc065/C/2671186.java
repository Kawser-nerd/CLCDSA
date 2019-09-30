import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Objects;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    String __DEBUG_FILE_NAME__ = "src/E4";

    FastScanner in;
    PrintWriter out;

    private final Comparator<State> X_COMP = (s1, s2) -> s1.x != s2.x ? Long.compare(s1.x, s2.x) : Long.compare(s1.y, s2.y);
    private final Comparator<State> Y_COMP = (s1, s2) -> s1.y != s2.y ? Long.compare(s1.y, s2.y) : Long.compare(s1.x, s2.x);

    class State {
        final int id;
        final long x, y;

        State(long x, long y) {
            this(-1, x, y);
        }

        public State(int id, long x, long y) {
            this.id = id;
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            State state = (State) o;
            return x == state.x &&
                    y == state.y;
        }

        @Override
        public int hashCode() {
            return (int)((x * 2e9 + y) % 1000000007);
        }

        @Override
        public String toString() {
            return "State{" +
                    "id=" + id +
                    ", x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    public void solve() {
        int N = in.nextInt();
        int a = in.nextInt() - 1, b = in.nextInt() - 1;
        long[] x = new long[N];
        long[] y = new long[N];
        for (int i = 0; i < N; i++) {
            int _x = in.nextInt(), _y = in.nextInt();
            x[i] = _x + _y;
            y[i] = _x - _y;
        }
        long d = Math.max(Math.abs(x[a] - x[b]), Math.abs(y[a] - y[b]));

        List<Integer> list = new ArrayList<>();
        TreeSet<State> tsX = new TreeSet<>(X_COMP);
        TreeSet<State> tsY = new TreeSet<>(Y_COMP);
        for (int i = 0; i < N; i++) {
            tsX.add(new State(i, x[i], y[i]));
            tsY.add(new State(i, x[i], y[i]));
        }
        dfs(new State(a, x[a], y[a]), list, tsX, tsY, d);

        int M = list.size();
        State[] xs = new State[M+2];
        State[] ys = new State[M+2];
        Set<State> hash = new HashSet<>();
        for (int i = 0; i < M; i++) {
            int u = list.get(i);
            xs[i] = new State(x[u], y[u]);
            ys[i] = new State(x[u], y[u]);
            hash.add(new State(x[u], y[u]));
        }
        xs[M] = new State(Long.MAX_VALUE, Long.MAX_VALUE);
        ys[M] = new State(Long.MAX_VALUE, Long.MAX_VALUE);
        xs[M+1] = new State(Long.MIN_VALUE, Long.MIN_VALUE);
        ys[M+1] = new State(Long.MIN_VALUE, Long.MIN_VALUE);
        Arrays.sort(xs, X_COMP);
        Arrays.sort(ys, Y_COMP);

        long res = 0;
        for (int u : list) {
            res += lowerBound(xs, new State(x[u] + d, y[u] + d), X_COMP) - lowerBound(xs, new State(x[u] + d, y[u] - d - 1),  X_COMP);
            res += lowerBound(xs, new State(x[u] - d, y[u] + d), X_COMP) - lowerBound(xs, new State(x[u] - d, y[u] - d - 1),  X_COMP);
            res += lowerBound(ys, new State(x[u] + d, y[u] + d), Y_COMP) - lowerBound(ys, new State(x[u] - d - 1, y[u] + d), Y_COMP);
            res += lowerBound(ys, new State(x[u] + d, y[u] - d), Y_COMP) - lowerBound(ys, new State(x[u] - d - 1, y[u] - d), Y_COMP);
            if (hash.contains(new State(x[u] - d, y[u] - d))) res--;
            if (hash.contains(new State(x[u] + d, y[u] - d))) res--;
            if (hash.contains(new State(x[u] - d, y[u] + d))) res--;
            if (hash.contains(new State(x[u] + d, y[u] + d))) res--;
        }
        res /= 2;
        System.out.println(res);
    }

    private long lowerBound(State[] s, State key, Comparator<State> comp) {
        int lo = 0, hi = s.length;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (comp.compare(s[mid], key) <= 0)
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }

    private void dfs(State current, List<Integer> list, TreeSet<State> tsX, TreeSet<State> tsY, long d) {
        Set<State> candidates = new HashSet<>();

        State leftUp = new State(current.x - d, current.y - d);
        State leftBottom = new State(current.x - d, current.y + d);
        State rightUp = new State(current.x + d, current.y - d);
        State rightBottom = new State(current.x + d, current.y + d);

        candidates.addAll(enumerate(leftUp, leftBottom, tsX));
        candidates.addAll(enumerate(rightUp, rightBottom, tsX));
        candidates.addAll(enumerate(leftUp, rightUp, tsY));
        candidates.addAll(enumerate(leftBottom, rightBottom, tsY));

        for (final State candidate : candidates) {
            tsX.remove(candidate);
            tsY.remove(candidate);
        }

        for (final State candidate : candidates) {
            list.add(candidate.id);
            dfs(candidate, list, tsX, tsY, d);
        }
    }

    private List<State> enumerate(State start, State end, TreeSet<State> ts) {
        List<State> res = new ArrayList<>();
        State current = ts.ceiling(start);
        while (current != null && ts.comparator().compare(current, end) <= 0) {
            res.add(current);
            current = ts.higher(current);
        }
        return res;
    }

    public void run() {
        if (__FILE_DEBUG_FLAG__ == __t__) {
            try {
                is = new FileInputStream(__DEBUG_FILE_NAME__);
            } catch (FileNotFoundException e) {
                // TODO ??????? catch ????
                e.printStackTrace();
            }
            System.out.println("FILE_INPUT!");
        } else {
            is = System.in;
        }
        in = new FastScanner(is);
        out = new PrintWriter(System.out);

        solve();
    }

    public static void main(final String[] args) {
        new Main().run();
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            // stream = new FileInputStream(new File("dec.in"));

        }

        int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
                array[i] = nextInt();

            return array;
        }

        int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextIntArray(m);
            }
            return map;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
                array[i] = nextLong();

            return array;
        }

        long[][] nextLongMap(int n, int m) {
            long[][] map = new long[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextLongArray(m);
            }
            return map;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++)
                array[i] = nextDouble();

            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextDoubleArray(m);
            }
            return map;
        }

        String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++)
                array[i] = next();

            return array;
        }

        String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }
    }
}