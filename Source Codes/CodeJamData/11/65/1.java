import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {

    private String solve(Scanner in) {
        int a = in.nextInt();
        int m = in.nextInt();
        int v = in.nextInt();
        double[] p = new double[v + 1];
        p[0] = 0;
        p[v] = 1;
        int[] maxbet = new int[v + 1];
        while (true) {
            double[] pp = new double[v + 1];
            pp[0] = 0;
            pp[v] = 1;
            for (int i = 1; i < v; i++) {
                maxbet[i] = 0;
                for (int j = 1; j <= Math.min(m, i); j++) {
                    int ii = i;
                    int k = j;
                    double ppp = 0.5;
                    double s = 0;
                    while (k <= m) {
                        int iw = ii + k;
                        int il = ii - k;
                        if (iw != i + j) {
                            System.out.println(i + " " + iw + " " + il);
                        }
                        if (iw > v) iw = v;
                        if (il < 0) il = 0;
                        s += p[iw] * ppp;
                        if (s + p[il] * ppp > pp[i] - 1e-8) {
                            maxbet[i] = Math.max(maxbet[i], j);
                        }
                        pp[i] = Math.max(pp[i], s + p[il] * ppp);
                        ppp *= 0.5;
                        ii -= k;
                        k *= 2;
                    }
                }
            }
            boolean ok = true;
            for (int i = 1; i < v; i++) {
                if (Math.abs(p[i] - pp[i]) > 1e-9) ok = false;
            }
            if (ok) break;
            p = pp;
        }
//        System.out.println(Arrays.toString(p));
        return p[a] + " " + maxbet[a];
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new E().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

}