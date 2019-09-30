import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    double[][] gen2(int n) {
        double[][] pr = new double[n][n];
        double[][] pr2 = new double[n][n];
        // number I on place J
        for (int i = 0; i < n; i++)
            pr[i][i] = 1.0;
        for (int i = 0; i < n; i++) {
            System.err.println(i);
            for (int j = 0; j < n; j++)
                Arrays.fill(pr2[j], 0);
            for (int curPos = 0; curPos < n; curPos++) {
                for (int curValue = 0; curValue < n; curValue++) {
                    pr2[curValue][i] += pr[curValue][curPos] / n;
                    if (curPos == i) {
                        for (int j = 0; j < n; j++)
                            if (j != curPos)
                                pr2[curValue][j] += pr[curValue][curPos] / n;
                    } else {
                        pr2[curValue][curPos] += pr[curValue][curPos] * (n - 1)
                                / n;
                    }
                }
            }
            double[][] tmp = pr;
            pr = pr2;
            pr2 = tmp;
        }
        return pr;
    }

    class Perm implements Comparable<Perm> {
        int[] a;
        boolean good;
        boolean guess;
        double prob;
        int id;

        Perm(int[] a, boolean good, double[][] pr, int id) {
            this.a = (int[]) a.clone();
            this.good = good;
            int n = a.length;
            for (int i = 0; i < n; i++) {
                prob += pr[a[i]][i];
            }
            this.id = id;
        }

        @Override
        public int compareTo(Perm o) {
            return Double.compare(prob, o.prob);
        }

    }

    void solve() throws IOException {
        int t = in.nextInt();
        int n = in.nextInt();
        double[][] pr = gen2(n);
        ArrayList<Perm> arr = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            int[] a = new int[n];
            for (int j = 0; j < n; j++)
                a[j] = in.nextInt();
            arr.add(new Perm(a, true, pr, i));
            if (i != t - 1)
                n = in.nextInt();
        }
        Collections.sort(arr);
        boolean[] good = new boolean[arr.size()];
        for (int i = 0; i < arr.size() / 2; i++) {
            good[arr.get(i).id] = true;
        }
        for (int i = 0; i < good.length; i++) {
            out.println("Case #" + (i + 1) + ": " + (good[i] ? "GOOD" : "BAD"));
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            solve();

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