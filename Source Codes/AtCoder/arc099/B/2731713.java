import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    int sum(int n) {
        return n < 10 ? n : (n % 10 + sum(n / 10));
    }

    void solve() {
        long nines = 0;
        long pow10 = 1;
        TreeSet<Long> ts = new TreeSet<>();
        for (int cntNines = 0; cntNines < 16; cntNines++) {
            for (int left = 1; ;left++) {
                long A = left * pow10 + nines;
                int B = sum(left) + cntNines * 9;
                long C = (left + 1) * pow10 + nines;
                int D = sum(left + 1) + cntNines * 9;
                if (A * D <= C * B) {
                    ts.add(Long.parseLong(Integer.toString(left) + (nines == 0 ? "" : Long.toString(nines))));
                } else {
                    break;
                }
            }
            nines = nines* 10 + 9;
            pow10 *= 10;
        }
        int n = in.nextInt();
        for (long z : ts) {
            out.println(z);
            if (--n == 0) {
                break;
            }
        }
    }

    void solve123() {
        final int MAX = 10000000;
        double[] f = new double[MAX];
        for (int n = 1; n < MAX; n++) {
            f[n] = n / (double) sum(n);
        }
        double curMin = Double.MAX_VALUE;
        for (int i = MAX - 1; i >= 0; i--) {
            if (f[i] <= curMin + 1e-9) {
                if (i < 1000000) {
                    System.err.println(i);
                }
            }
            curMin = Math.min(curMin, f[i]);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("Main23.in"));
            out = new PrintWriter(new File("Main23.out"));

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
}