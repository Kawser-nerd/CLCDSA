
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {

    private int n;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(D.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(D.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        String s = in.next();
        int z = 0;
        n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'X') {
                z += (1 << i);
            }
        }
        res = new double[1 << n];
        return "" + calc(z);
    }

    double[] res;

    private double calc(int z) {
        if (res[z] > 0) return res[z];
        if (z == (1 << n) - 1) return 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int c = n;
            while (((z >> j) & 1) == 1) {
                j = (j + 1) % n;
                c--;
            }
            res[z] += c + calc(z + (1 << j));
        }
        res[z] /= n;
        return res[z];
    }
}