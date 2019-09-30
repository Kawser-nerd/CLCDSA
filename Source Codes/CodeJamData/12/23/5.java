import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Clarge {
    FastScanner in;
    PrintWriter out;

    public void solve(int testNo) throws IOException {
        System.out.println("Solving case " + testNo);
        
        int n = in.nextInt();
        
        Random rnd = new Random(23904241166L);
        
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }

        for (int i = 0; i < n; i++) {
            int j = rnd.nextInt(i + 1);
            long t = a[i]; a[i] = a[j]; a[j] = t;
        }

        int m = 50;
        HashMap<Long, BitSet> c = new HashMap<Long, BitSet>();
        BitSet v = new BitSet(m);
        long sum;
        while (true) {
            sum = 0;
            for (int i = 0; i < m; i++) {
                v.set(i, rnd.nextBoolean());
                if (v.get(i)) {
                    sum += a[i];
                }
            }
            if (c.containsKey(sum) && !v.equals(c.get(sum))) {
                break;
            } else {
                c.put(sum, (BitSet) v.clone());
                if (c.size() % 1000000 == 0) {
                    System.out.println("Cached " + c.size() + " values");
                }
            }
        }
                
        out.println("Case #" + testNo + ": ");
        System.out.println("Case #" + testNo + ": ");
        boolean first = true;
        for (int i = 0; i < n; i++) {
            if (v.get(i)) {
                if (!first) {
                    out.print(" ");
                    System.out.print(" ");
                }
                first = false;
                out.print(a[i]);
                System.out.print(a[i]);
            }
        }
        out.println();
        System.out.println();
        v = c.get(sum);
        first = true;
        for (int i = 0; i < n; i++) {
            if (v.get(i)) {
                if (!first) {
                    out.print(" ");
                    System.out.print(" ");
                }
                first = false;
                out.print(a[i]);
                System.out.print(a[i]);
            }
        }
        out.println();
        System.out.println();
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));

            int testNo = in.nextInt();
            long time = System.currentTimeMillis();
            for (int test = 0; test < testNo; test++) {
                solve(test + 1);
                System.out.println((System.currentTimeMillis() - time) + " passed");
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new Clarge().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}