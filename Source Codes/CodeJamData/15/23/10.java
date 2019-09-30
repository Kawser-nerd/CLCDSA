import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {
    FastScanner in;
    PrintWriter out;

    final static double EPS = 1e-7;

    class Hiker {
        int start;
        int period;

        public Hiker(int start, int period) {
            this.start = start;
            this.period = period;
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {

            int n = in.nextInt();
            ArrayList<Hiker> hal = new ArrayList<Hiker>();
            for (int i = 0; i < n; i++) {
                int d = in.nextInt();
                int hn = in.nextInt();
                int mi = in.nextInt();
                for (int j = 0; j < hn; j++) {
                    hal.add(new Hiker(d, mi + j));
                }
            }
            Hiker[] h = hal.toArray(new Hiker[hal.size()]);
            n = h.length;
            int ans = n;
            for (int mask = 1; mask < (1 << n); mask++) {
                double when = 0;
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0) {
                        double come = (360 - h[j].start) / 360.0 * h[j].period;
                        if (come > when) {
                            when = come;
                        }
                    }
                }

                boolean can = true;
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0) {
                        double where = h[j].start + when / h[j].period * 360.0;
//                        System.out.println(j + " " + where);
                        if (where > 720.0 - EPS || where < 360.0 - EPS) {
                            can = false;
                        }
                    }
                }
//                System.out.println(mask + " " + when + " " + can);
                if (can) {
                    long cnt = 0;
                    for (int j = 0; j < n; j++) {
                        if ((mask & (1 << j)) == 0) {
                            double where = h[j].start + when / h[j].period * 360.0;
//                            System.out.println(j + " " + where);
                            if (where > 720.0 - EPS) {
                                where = (where - 360.0) - (where % 360.0);
                                long isect = Math.round(where / 360.0);
                                cnt += isect;
                            } else if (where < 360.0 + EPS) {
                                cnt++;
                            }
                        }
                    }
//                    System.out.println(mask + " " + cnt);
                    if (cnt < ans) {
                        ans = (int) cnt;
                    }
//                    System.out.println();
                }
            }

            out("Case #%d: %d\n", test, ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-small-2-attempt1.in"));
            out = new PrintWriter(new File("C-small-2-attempt1.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
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