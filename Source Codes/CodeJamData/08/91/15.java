import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

public class A {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter("a.out");

        int t = in.nextInt();


        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            Inf[] is = new Inf[n];
            Set<Integer> as = new HashSet<Integer>();
            Set<Integer> bs = new HashSet<Integer>();
            Set<Integer> cs = new HashSet<Integer>();
            for (int j = 0; j < n; j++) {
                is[j] = new Inf();
                is[j].a = in.nextInt();
                is[j].b = in.nextInt();
                is[j].c = in.nextInt();
                as.add(is[j].a); bs.add(is[j].b); cs.add(is[j].c);

            }

            boolean[] w = new boolean[n];
            int rmax = 0;
            while (true) {
                int ma = 0, mb = 0, mc = 0;
                int r = 0;
                for (int j = 0; j < is.length; j++) {
                    if (w[j]) {
                        r ++;
                        Inf inf = is[j];
                        ma = Math.max(ma, inf.a);
                        mb = Math.max(mb, inf.b);
                        mc = Math.max(mc, inf.c);
                    }
                }
                if (ma + mb + mc <= 10000 && r > rmax) {
                    rmax = r;
                }

                int k = 0;
                while (k < n && w[k]) {
                    w[k] = false;
                    k++;
                }
                if (k >= n) break;
                w[k] = true;
            }

            out.println("Case #" + i + ": " + rmax);
/*
            int[] aa = new int[as.size()];
            int[] bb = new int[bs.size()];
            int[] cc = new int[cs.size()];
            int k;
            k = 0; for (Integer x : as) aa[k++] = x;
            k = 0; for (Integer x : bs) bb[k++] = x;
            k = 0; for (Integer x : cs) cc[k++] = x;
            Arrays.sort(aa);
            Arrays.sort(bb);
            Arrays.sort(cc);

            int[][] ab = new int[aa.length][bb.length];
            int[][] bc = new int[aa.length][bb.length];
            int[][] ac = new int[aa.length][bb.length];
            for (Inf inf : is) {
                for (int c = inf.c; c <= 10000; c++) {
                    ab[inf.a][inf.b] = 0;
                }
            }
*/
        }

        in.close();
        out.close();
    }

    private static class Inf {
        int a,b,c;


    }
}