import java.util.*;
import java.io.*;

class D {
    FastScanner in;
    PrintWriter out;
    
    class State {
        long[] mask;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (!Arrays.equals(mask, state.mask)) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return mask != null ? Arrays.hashCode(mask) : 0;
        }

        State(boolean[][] b) {
            mask = new long[R];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (b[i][j]) {
                        mask[i] |= 1L << j; 
                    }
                }
            }
        }

        State(long[] mask) {
            this.mask = mask;
        }
        
        State(int x, int y) {
            mask = new long[R];
            mask[x] = 1L << y;
        }

        State up() {
            long[] nm = new long[R];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if ((mask[i] & (1L << j)) != 0) {
                        if (a[i - 1][j]) {
                            nm[i - 1] |= (1L << j);
                        }
                        if (!a[i + 1][j]) {
                            nm[i] |= (1L << j);
                        }
                    }
                }
            }
            return new State(nm);
        }

        State left() {
            long[] nm = new long[R];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if ((mask[i] & (1L << j)) != 0) {
                        if (a[i][j - 1]) {
                            nm[i] |= (1L << (j - 1));
                        }
                        if (!a[i][j + 1]) {
                            nm[i] |= (1L << j);
                        }
                    }
                }
            }
            return new State(nm);
        }
        
        State right() {
            long[] nm = new long[R];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if ((mask[i] & (1L << j)) != 0) {
                        if (a[i][j + 1]) {
                            nm[i] |= (1L << (j + 1));
                        }
                        if (!a[i][j - 1]) {
                            nm[i] |= (1L << j);
                        }
                    }
                }
            }
            return new State(nm);
        }
    }
    
    int R;
    int C;
    
    boolean[][] a;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Running test " + test);

            R = in.nextInt();
            C = in.nextInt();

            a = new boolean[R][C];
            int[] r = new int[10];
            int[] c = new int[10];
            Arrays.fill(r, -1);
            for (int i = 0; i < R; i++) {
                String s = in.next();
                for (int j = 0; j < C; j++) {
                    a[i][j] = s.charAt(j) != '#';
                    if ('0' <= s.charAt(j) && s.charAt(j) <= '9') {
                        int v = s.charAt(j) - '0';
                        r[v] = i;
                        c[v] = j;
                    }
                }
            }

            out("Case #%d:\n", test);
            for (int cave = 0; cave < 10; cave++) {
                if (r[cave] != -1) {
                    boolean[][] b = new boolean[R][C];
                    b[r[cave]][c[cave]] = true;
                    boolean ch = true;
                    int cnt = 1;
                    while (ch) {
                        ch = false;
                        for (int i = 0; i < R; i++) {
                            for (int j = 0; j < C; j++) {
                                if (b[i][j] && i > 0 && a[i - 1][j] && !b[i - 1][j]) {
                                    b[i - 1][j] = true;
                                    cnt++;
                                    ch = true;
                                }
                                if (b[i][j] && j > 0 && a[i][j - 1] && !b[i][j - 1]) {
                                    b[i][j - 1] = true;
                                    cnt++;
                                    ch = true;
                                }
                                if (b[i][j] && j < C - 1 && a[i][j + 1] && !b[i][j + 1]) {
                                    b[i][j + 1] = true;
                                    cnt++;
                                    ch = true;
                                }
                            }
                        }
                    }
                    
                    State target = new State(b);
                    
                    State s = new State(r[cave], c[cave]);
                    ArrayDeque<State> q = new ArrayDeque<State>();
                    HashSet<State> vis = new HashSet<State>();
                    q.add(s);
                    vis.add(s);
                    boolean ok = false;
                    while (!q.isEmpty()) {
                        State cur = q.pollFirst();
                        State next;

                        next = cur.up();
                        if (next.equals(target)) {
                            ok = true;
                            break;
                        }
                        if (!vis.contains(next)) {
                            vis.add(next);
                            q.add(next);
                        }
                        next = cur.left();
                        if (next.equals(target)) {
                            ok = true;
                            break;
                        }
                        if (!vis.contains(next)) {
                            vis.add(next);
                            q.add(next);
                        }
                        next = cur.right();
                        if (next.equals(target)) {
                            ok = true;
                            break;
                        }
                        if (!vis.contains(next)) {
                            vis.add(next);
                            q.add(next);
                        }
                    }
                    
                    out("%d: %d %s\n", cave, cnt, ok ? "Lucky" : "Unlucky");
                }
            }
            
        }
    }
    
    void out(String s, Object... x) {
        out.printf(s, x);
        System.out.printf(s, x);
    }

    public void run() {
        try {
            in = new FastScanner(new File("D-small-attempt0.in"));
            out = new PrintWriter(new File("D-small-attempt0.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new D().run();
    }
}