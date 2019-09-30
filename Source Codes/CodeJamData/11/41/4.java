import java.io.*;
import java.util.*;

public class A_as implements Runnable {
    class S implements Comparable<S> {
        int s;
        int t;
        int w;

        S(int s, int t, int w) {
            this.s = s;
            this.t = t;
            this.w = w;
        }

        public int compareTo(S o) {
            return w - o.w;
        }
    }
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int x = in.nextInt();
            int s = in.nextInt();
            int r = in.nextInt();
            double t = in.nextInt();
            int n = in.nextInt();
            ArrayList<S> segs = new ArrayList<S>();
            int last = 0;
            for (int i = 0; i < n; i++) {
                int fr = in.nextInt();
                int to = in.nextInt();
                int w = in.nextInt();
                if (fr > last) {
                    segs.add(new S(last, fr, 0));
                }
                segs.add(new S(fr, to, w));
                last = to;
            }
            if (last < x) {
                segs.add(new S(last, x, 0));
            }

            Collections.sort(segs);
            double ans = 0;
            for (int i = 0; i < segs.size(); i++) {
                S seg = segs.get(i);
                double len = seg.t - seg.s;
                double rt = Math.min(t, len / (seg.w + r));
                t -= rt;
                ans += rt;
                len -= rt * (seg.w + r);
                ans += len / (seg.w + s);
            }

            out.printf("Case #" + test + ": %.10f\n", ans);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new A_as()).start();
    }
}