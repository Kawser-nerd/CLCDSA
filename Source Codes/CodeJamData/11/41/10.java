
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class a {
    private static class W implements Comparable<W> {
        public int l;
        public int w;
        public W(int l, int w){this.l = l; this.w = w;}
        public int compareTo(W o) {
            return w - o.w;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int T = sc.nextInt();
        for (int c = 1; c <= T; ++c) {
            int x = sc.nextInt();
            double s = sc.nextInt();
            double r = sc.nextInt();
            int t = sc.nextInt();
            int n = sc.nextInt();

            W[] ws = new W[n + 1];

            int sum = 0;

            for (int i = 0; i < n; ++i) {
                int b = sc.nextInt();
                int e = sc.nextInt();
                int w = sc.nextInt();

                ws[i] = new W(e - b, w);

                sum += e - b;
            }

            ws[n] = new W(x - sum, 0);

            Arrays.sort(ws);

            double time = 0;
            double remaining_running = t;

            for (int i = 0; i <= n; ++i) {
                W w = ws[i];
                if (remaining_running > 0) {
                    double tt = w.l / (w.w + r);
                    if (tt < remaining_running) {
                        //.System.out.println("run all: " + w.l + " " + w.w);
                        remaining_running -= tt;
                        time += tt;
                    } else {
                        //.System.out.println("run some: " + w.l + " " + w.w);
                        time += remaining_running;
                        time += (w.l - (w.w + r) * remaining_running) / (w.w + s);
                        remaining_running = 0;
                    }
                } else {
                    //.System.out.println("run none: " + w.l + " " + w.w);
                    time += w.l / (w.w + s);
                }
            }

            System.out.format("Case #%d: %.6f%n", c, time);
        }

    }
}
