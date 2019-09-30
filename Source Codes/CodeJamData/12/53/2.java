import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
    FastScanner in;
    PrintWriter out;

    class Food implements Comparable<Food> {
        long p;
        long s;
        long ds;

        Food(long p, long s) {
            this.p = p;
            this.s = s;
        }

        public int compareTo(Food o) {
            if (p < o.p) {
                return -1;
            }
            if (p > o.p) {
                return 1;
            }
            if (s < o.s) {
                return -1;
            }
            if (s > o.s) {
                return 1;
            }
            return 0;
        }
    }
    
    long m;
    long f;
    Food[] a;
    int n;
    
    long eval(long d) {
        long haveM = m - d * f;
        long oneM = haveM / d;
        long left = haveM - oneM * d;
        long days = 0;
        for (int i = 0; i < n; i++) {
            long b = oneM / a[i].p;
            if (b > a[i].s - days) {
                b = a[i].s - days;
            }
            if (b < 0) {
                b = 0;
            }
            days += b;
            oneM -= b * a[i].p;
        }
        left += oneM * d;
        long xDays = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].s > days) {
                xDays = left / a[i].p;
                left -= xDays * a[i].p;
                break;
            }
        }
        long have = days * d + xDays;
        return have;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);

            m = in.nextLong();
            f = in.nextLong();
            n = in.nextInt();
            a = new Food[n];
            for (int i = 0; i < n; i++) {
                a[i] = new Food(in.nextLong(), in.nextLong() + 1);
            }
            
            Arrays.sort(a);
            
            int prev = 0;
            long best = 0;
            
            long L = 1;
            long R = m / f;
            while (L + 10 < R) {
                long x1 = (L * 2 + R) / 3;  
                long x2 = (L + R * 2) / 3;
                
                long v1 = eval(x1);
                long v2 = eval(x2);
                if (v1 >= v2) {
                    R = x2;
                } else {
                    L = x1;
                }
            }
            
            for (long v = L; v <= R; v++) {
                long val = eval(v);
                if (val > best) {
                    best = val;
                }
            }

            out("Case #%d: %d\n", test, best);
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
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

    public static void main(String[] arg) {
        new C().run();
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