import com.sun.javaws.jnl.XMLFormat;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class C {
    FastScanner in;
    PrintWriter out;
    
    boolean doIt(int L, int R, int level, int[] x, long[] h) {
        if (L >= R) {
            return true;
        }
        if (x[L] > R) {
            return false;
        }
        if (x[L] == R) {
            h[L] = h[R] - level * (R - L);
            return doIt(L + 1, R, level + 1, x, h);
        }
        
        return doIt(x[L], R, level, x, h) && doIt(L, x[L], level, x, h);
    }
    
    final long MAX = 1000000000;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Running test " + test);

            int n = in.nextInt();
            int[] x = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                x[i] = in.nextInt() - 1;
            }

            long[] h = new long[n];
            h[n - 1] = MAX;
            boolean ok = doIt(0, n - 1, 1, x, h);

            if (ok && !check(h, x)) {
                System.out.println(Arrays.toString(x));
                System.out.println(Arrays.toString(h));
                System.out.println("ERROR!");
//                System.exit(1);
            }

            String s = "";
            for (int i = 0; i < n; i++) {
                s = s + " " + h[i];
            }

            if (ok) {
                out("Case #%d:%s\n", test, s);
            } else {
                out("Case #%d: Impossible\n", test);
            }
        }
    }
    
    boolean check(long[] h, int[] x) {
        int n = x.length;
        for (int i = 0; i < n - 1; i++) {
            if (x[i] <= i) {
                return false;
            }
            for (int j = i + 1; j < x[i]; j++) {
                if ((h[j] - h[i]) * (x[i] - i) >= (h[x[i]] - h[i]) * (j - i)) {
                    System.out.println(i + " " + x[i] + " " + j);
                    return false;
                }
            }
            for (int j = x[i] + 1; j < n; j++) {
                if ((h[j] - h[i]) * (x[i] - i) > (h[x[i]] - h[i]) * (j - i)) {
                    System.out.println(i + " " + x[i] + " " + j);
                    return false;
                }
            }
        }
        return true;
    }
    
    void out(String s, Object... x) {
        out.printf(s, x);
        System.out.printf(s, x);
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));

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
        new C().run();
    }
}