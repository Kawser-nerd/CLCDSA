import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D1 {
    FastScanner in;
    PrintWriter out;

    int norm(int i, int n) {
        int r = i;
        for (int j = 0; j < n; j++) {
            int v = ((i << j) & ((1 << n) - 1)) | (i >> (n - j));
            if (v < r) {
                r = v;
            }
        }
        return r;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);

            String s = in.next();
            int n = s.length();
            int st = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(s.length() - i - 1) == 'X') {
                    st = (st << 1) + 1;
                } else {
                    st = st << 1;
                }
            }
            st = norm(st, n);
            double[] prob = new double[1 << n];
            prob[st] = 1.0;
            double[] ans = new double[1 << n];
            ans[st] = 0;
            for (int i = 0; i < (1 << n) - 1; i++) {
                if (prob[i] != 0) {
                    ans[i] /= prob[i];
                    for (int j = 0; j < n; j++) {
                        int v = ((i << j) & ((1 << n) - 1)) | (i >> (n - j));
                        int t = 0;
                        int u = v;
                        while (u % 2 != 0) {
                            t++;
                            u /= 2;
                        }
                        int nv = v | (1 << t);
                        nv = norm(nv, n);
                        if (nv < i) {
                            throw new AssertionError();
                        }
                        ans[nv] += prob[i] / n * (ans[i] + (n - t));
                        prob[nv] += prob[i] / n;
                    }
                }
            }

//            System.out.println(Arrays.toString(ans));
//            System.out.println(Arrays.toString(prob));

            out("Case #%d: ", test);
            out("%.15f", ans[(1 << n) - 1]);
            out("\n");
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
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

    public static void main(String[] arg) {
        new D1().run();
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