import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int c = in.nextInt();
        int d = in.nextInt();
        int[] x = new int[1000000];
        int n = 0;
        for (int i = 0; i < c; i++) {
            int p = in.nextInt();
            int v = in.nextInt();
            for (int j = 0; j < v; j++) {
                x[n++] = p;
            }
        }
        Arrays.sort(x, 0, n);
        double l = 0;
        double r = 1e20;
        while (true) {
            double m = (l + r) * .5;
            if (m == l || m == r) break;
            double ll = -1e20;
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                ll = ll + d;
                if (x[i] + m < ll) {
                    ok = false;
                } else {
                    ll = Math.max(ll, x[i] - m);
                }
            }
            if (ok) {
                r = m;
            } else {
                l = m;
            }
        }
        return "" + (l);
    }
}