
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Ae {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A.in"));
        PrintWriter out = new PrintWriter(new File("A.out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new Ae().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int l = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(in.next(), 2);
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(in.next(), 2);
        }
        int res = l + 1;
        Arrays.sort(a);
        for (int m = 0; m < (1 << l); m++) {
            for (int i = 0; i < n; i++) {
                b[i] ^= m;
            }
            Arrays.sort(b);
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res = Math.min(res, Integer.bitCount(m));
            }
            for (int i = 0; i < n; i++) {
                b[i] ^= m;
            }
        }
       return res > l ? "NOT POSSIBLE" : ("" + res);
    }
}