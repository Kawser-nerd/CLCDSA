
import java.io.*;
import java.util.*;

public class C {

    private int solveTest() throws IOException {
        int n = nextInt();
        String[][] ss = new String[n][];
        Map<String, Integer> words = new HashMap<String, Integer>();
        int wn = 0;
        for (int i = 0; i < n; i++) {
            ss[i] = br.readLine().split(" ");
            for (String s : ss[i]) {
                if (!words.containsKey(s)) {
                    words.put(s, wn++);
                }
            }
        }
        init(wn * 2 + 2, 1);
        for (int i = 0; i < n; i++) {
            if (i < 2) {
                for (int j = 0; j < ss[i].length; j++) {
                    int x = words.get(ss[i][j]);
                    if (i == 0) addEdge(wn * 2, x, 1000000000);
                    if (i == 1) addEdge(x + wn, wn * 2 + 1, 1000000000);
                }
            } else {
                for (int j = 0; j < ss[i].length; j++) {
                    for (int k = 0; k < ss[i].length; k++) {
                        int x = words.get(ss[i][j]);
                        int y = words.get(ss[i][k]);
                        addEdge(x + wn, y, 1000000000);
                    }
                }
            }
        }
        for (int i = 0; i < wn; i++) {
            addEdge(i, i + wn, 1);
        }
        int res = (int) maxFlow(wn * 2, wn * 2 + 1);
        return res;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        src = new int[m];
        cp = new int[m];
        fl = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
    }

    void addEdge(int x, int y, int capacity) {
        if (last == nx.length) {
            int size = nx.length * 2;
            nx = setSize(nx, size);
            dst = setSize(dst, size);
            src = setSize(src, size);
            cp = setSize(cp, size);
            fl = setSize(fl, size);
        }
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        cp[last] = capacity;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        cp[last] = 0;
        head[y] = last;
        last++;
    }

    private int[] setSize(int[] x, int size) {
        int[] xx = new int[size];
        System.arraycopy(x, 0, xx, 0, x.length);
        return xx;
    }

    long maxFlow(int s, int t) {
        long res = 0;
        while (true) {
            Arrays.fill(z, false);
            int f = dfs(s, t, Integer.MAX_VALUE);
            if (f > 0) {
                res += f;
            } else {
                break;
            }
        }
        return res;
    }

    private int dfs(int x, int t, int f) {
        if (f == 0) return 0;
        if (x == t) return f;
        if (z[x]) return 0;
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (!z[y] && fl[j] < cp[j]) {
                int res = dfs(y, t, Math.min(f, cp[j] - fl[j]));
                if (res > 0) {
                    fl[j] += res;
                    fl[j ^ 1] -= res;
                    return res;
                }
            }
            j = nx[j];
        }
        return 0;
    }

    private static final long INF = Long.MAX_VALUE;

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] cp;
    int[] fl;
    boolean[] z;
    int last;



}