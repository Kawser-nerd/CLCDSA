
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class A {

    private int d;
    private int[] s;
    private int left;
    private int right;

    TreeSet<Vertex> candidates;
    TreeSet<Vertex> taken;

    private int solve2() {
        candidates = new TreeSet<Vertex>();
        taken = new TreeSet<Vertex>();
        int n = s.length;
        int[] a = new int[n];
        System.arraycopy(s, 0, a, 0, n);
        Arrays.sort(a);
        left = a[0];
        right = left + d;
        candidates.add(new Vertex(0, s[0]));
        greadyAdd();
        int res = taken.size();
        for (int i = 1; i < n; i++) {
            res = Math.max(res, taken.size());
            left = a[i];
            right = left + d;
            while (taken.size() > 0 && taken.first().s < left) {
                cascadeRemove(taken.first());
            }
            greadyAdd();
        }
        return res;
    }

    private void cascadeRemove(Vertex v) {
//        System.out.println("remove " + v.id);
        taken.remove(v);
        int j = head[v.id];
        while (j >= 0) {
            int y = dst[j];
            Vertex u = new Vertex(y, s[y]);
            if (taken.contains(u)) {
                cascadeRemove(u);
            }
            if (candidates.contains(u)) {
                candidates.remove(u);
            }
            j = nx[j];
        }
    }

    private void greadyAdd() {
        while (candidates.size() > 0 && candidates.first().s <= right) {
            if (candidates.first().s < left) {
                candidates.pollFirst();
            } else {
                Vertex v = candidates.pollFirst();
//                System.out.println("add " + v.id);
                taken.add(v);
                int j = head[v.id];
                while (j >= 0) {
                    int y = dst[j];
                    candidates.add(new Vertex(y, s[y]));
                    j = nx[j];
                }
            }
        }
    }

    class Vertex implements Comparable<Vertex>{
        int id;
        int s;

        public Vertex(int id, int s) {
            this.id = id;
            this.s = s;
        }

        public int compareTo(Vertex o) {
            if (s != o.s) return Integer.compare(s, o.s);
            return Integer.compare(id, o.id);
        }

        @Override
        public boolean equals(Object o) {
            return compareTo((Vertex) o) == 0;
        }
    }

    private int solveTest() throws IOException {
        int n = nextInt();
        d = nextInt();
        s = new int[n];
        int[] m = new int[n];
        s[0] = nextInt();
        int as = nextInt();
        int cs = nextInt();
        int rs = nextInt();
        for (int i = 1; i < n; i++) {
            s[i] = (int) ((1l * s[i - 1] * as + cs) % rs);
        }
        m[0] = nextInt();
        int am = nextInt();
        int cm = nextInt();
        int rm = nextInt();
        for (int i = 1; i < n; i++) {
            m[i] = (int) ((1l * m[i - 1] * am + cm) % rm);
        }

        init(n, n - 1);
        for (int i = 1; i < n; i++) {
            addEdge(m[i] % i, i);
        }

//        System.out.println(Arrays.toString(s));
//        System.out.println(Arrays.toString(m));
        return solve2();
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }

    void init(int n, int m) {
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        Arrays.fill(head, -1);
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
    }


    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int last;




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
        new A().run();
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

}