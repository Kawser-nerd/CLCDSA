import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    class Frac implements Comparable<Frac>{
        long x, y;

        public Frac(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Frac o) {
            return Long.compare(x * o.y, y * o.x);
        }

        @Override
        public String toString() {
            return "Frac{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    int s;


    class Vertex implements Comparable<Vertex>{
        int cntZero;
        int cntOnes;
        List<Vertex> ch;
        Frac res;
        Vertex parent;
        int id = s++;
        boolean alive = true;

        Vertex getParent() {
            return parent.alive ? parent : (parent = parent.getParent());
        }

        Vertex(Vertex p) {
            this.parent = p;
            ch = new ArrayList<>();
        }

        void count() {
            res = new Frac(cntZero, 1);
        }

        @Override
        public int compareTo(Vertex o) {
            int f = -res.compareTo(o.res);
            if (f != 0) {
                return f;
            }
            return Integer.compare(id, o.id);
        }
    }

    long res;

    void go(Vertex parent, int v) {
        if (val[v] == 1) {
            Vertex nv = new Vertex(parent);
            nv.cntOnes++;
            for (int to : g[v]) {
                go(nv, to);
            }
            nv.count();
            res += nv.cntZero;
            pq.add(nv);
        } else {
            parent.cntZero++;
            for (int to : g[v]) {
                go(parent, to);
            }
        }
    }

    int[] val;
    ArrayList<Integer>[] g;



    TreeSet<Vertex> pq = new TreeSet<>();


    void solve() {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            p[i] = in.nextInt() - 1;
            g[p[i]].add(i);
        }
        int cntZero = 0;
        val = new int[n];
        for (int i = 0; i < n; i++) {
            val[i] = in.nextInt();
            if (val[i] == 0) {
                cntZero++;
            }
        }
        Vertex fake = new Vertex(null);
        go(fake, 0);
        cntZero -= fake.cntZero;
        for (Vertex to : fake.ch) {
            pq.add(to);
        }
        while (pq.size() > 0) {
            Vertex v = pq.pollFirst();
            v.alive = false;
            Vertex par = v.getParent();
            if (par != fake) {
                pq.remove(par);
            }
            res += par.cntOnes * 1L* v.cntZero;
            par.cntZero += v.cntZero;
            par.cntOnes += v.cntOnes;
            par.res = new Frac(par.cntZero, par.cntOnes);
            if (par != fake) {
                pq.add(par);
            }
        }
        out.println(res);
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.