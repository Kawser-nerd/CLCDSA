import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    long sum(long r, long cnt) {
        BigInteger rr = BigInteger.valueOf(r);
        BigInteger cc = BigInteger.valueOf(cnt);
        BigInteger pi = BigInteger.ONE;
        BigInteger two = BigInteger.valueOf(2);
        BigInteger tmp1 = BigInteger.valueOf(cnt + 1).multiply(pi);
        BigInteger tmp2 = two.multiply(rr).add(BigInteger.ONE);
        BigInteger tmp3 = two.multiply(cc).add(tmp2);
        BigInteger res = tmp1.multiply(tmp3);
        BigInteger max = BigInteger.valueOf(Long.MAX_VALUE);
        if (res.compareTo(max) >= 0)
            return Long.MAX_VALUE;
        return res.longValue();
    }
    
    void solve() throws IOException {
        long R = in.nextLong();
        long t = in.nextLong();
        long l = 0, r = (long) 1e18 + 1000;
        while (r - l > 1) {
            long m = (l + r) / 2;
            long ss = sum(R, m);
            if (ss <= t) {
                l = m;
            } else {
                r = m;
            }
        }
        out.println(l + 1);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
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
        new A().run();
    }
}