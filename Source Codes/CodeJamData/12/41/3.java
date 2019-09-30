import java.io.*;
import java.util.StringTokenizer;

class A {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Running test " + test);
            int n = in.nextInt();
            long[] d = new long[n];
            long[] l = new long[n];
            for (int i = 0; i < n; i++) {
                d[i] = in.nextInt();
                l[i] = in.nextInt();
            }
            long D = in.nextInt();

            long[] max = new long[n];
            max[0] = d[0];
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (d[i] - d[j] <= max[j]) {
                        long x = d[i] - d[j];
                        if (l[i] < x) {
                            x = l[i];
                        }
                        if (x > max[i]) {
                            max[i] = x;
                        }
                    }
                }
            }
            
            boolean can = false;
            for (int i = 0; i < n; i++) {
                if (d[i] + max[i] >= D) {
                    can = true;
                }
            }
            
            out("Case #%d: %s\n", test, (can ? "YES" : "NO"));
        }
    }
    
    void out(String s, Object... x) {
        out.printf(s, x);
        System.out.printf(s, x);
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

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
        new A().run();
    }
}