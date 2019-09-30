import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    static class Rec {
        public final int type;
        public final long count;

        Rec(long count, int type) {
            this.type = type;
            this.count = count;
        }
    }

    public void run(Scanner in, PrintWriter out, int nCase) {
        int n = in.nextInt();
        int m = in.nextInt();
        Rec[] l = new Rec[n];
        Rec[] r = new Rec[m];
        for (int i = 0; i < n; ++i) {
            l[i] = new Rec(in.nextLong(), in.nextInt() - 1);
        }
        for (int i = 0; i < m; ++i) {
            r[i] = new Rec(in.nextLong(), in.nextInt() - 1);
        }
        long[] ltc = new long[100];
        long[] rtc = new long[100];
        long[][] ans = new long[n + 1][m + 1];
        long theMax = 0;
        for (int li = 0; li < n; ++li) {
            for (int ri = 0; ri < m; ++ri) {
                if (li == 0 && ri == 0 || li > 0 && ri > 0 && l[li - 1].type == r[ri - 1].type) {
                    for (int lj = li + 1; lj <= n; ++lj) {
                        Rec cl = l[lj - 1];
                        ltc[cl.type] += cl.count;
                        for (int rj = ri + 1; rj <= m; ++rj) {
                            Rec cr = r[rj - 1];
                            rtc[cr.type] += cr.count;
                            if (cl.type == cr.type) {
                                ans[lj][rj] = Math.max(ans[lj][rj], ans[li][ri] + Math.min(ltc[cl.type], rtc[cr.type]));
                                theMax = Math.max(theMax, ans[lj][rj]);
                            }
                        }
                        for (int rj = ri + 1; rj <= m; ++rj) {
                            rtc[r[rj - 1].type] -= r[rj - 1].count;
                        }
                    }
                    for (int lj = li + 1; lj <= n; ++lj) {
                        ltc[l[lj - 1].type] -= l[lj - 1].count;
                    }
                }
            }
        }
        out.printf("Case #%d: %d%n", nCase, theMax);
    }

    public static void main(String[] args) throws FileNotFoundException {
        String filename = C.class.getSimpleName().toLowerCase();

        Scanner in = new Scanner(new File(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");

        int nCases = in.nextInt();

        for (int i = 1; i <= nCases; ++i) {
            new C().run(in, out, i);
        }

        out.close();
        in.close();
    }
}
