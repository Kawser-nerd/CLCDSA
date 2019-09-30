import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    ArrayList<Integer> cur = new ArrayList<>();
    double best = 0;
    int[] ans;

    void go(int n, int m, int[] values) {
        if (cur.size() == n) {
            HashMap<Integer, Integer> hm = new HashMap<>();
            for (int st = 0; st < 1 << n; st++) {
                int mul = 1;
                for (int i = 0; i < n; i++)
                    if (((1 << i) & st) != 0)
                        mul *= cur.get(i);
                Integer xx = hm.get(mul);
                if (xx == null)
                    xx = 0;
                xx++;
                hm.put(mul, xx);
            }
            double res = 1;
            for (int i = 0; i < values.length; i++) {
                Integer tmp = hm.get(values[i]);
                if (tmp == null)
                    tmp = 0;
                res *= tmp;
            }
            if (res >= best) {
                best = res;
                for (int i = 0; i < n; i++)
                    ans[i] = cur.get(i);
            }
        } else {
            for (int next = 2; next <= m; next++) {
                cur.add(next);
                go(n, m, values);
                cur.remove(cur.size() - 1);
            }
        }
    }

    void solve() throws IOException {
        int r = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        for (int tt = 0; tt < r; tt++) {
            int[] val = new int[k];
            for (int i = 0; i < k; i++)
                val[i] = in.nextInt();
            best = -1;
            ans = new int[n];
            go(n, m, val);
            for (int i = 0; i < n; i++)
                out.print(ans[i]);
            out.println();
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.println("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

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
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}