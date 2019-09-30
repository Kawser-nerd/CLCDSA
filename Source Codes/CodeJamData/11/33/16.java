import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class R1CC {

    /**
     * Google Code Jam Round 1C 2011 Problem A. Square Tiles
     * 
     * @author dkorduban
     */
    public static void main(String[] args) {
        try {
            new R1CC().solve();
        } catch (Exception e) {
            e.printStackTrace();
            throw new IllegalStateException();
        }

    }

    private void solve() throws FileNotFoundException {
        // Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("C-small-attempt0.in"));
        // PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter("C-small-attempt0.out");
        int testCount = in.nextInt();
        for (int test = 1; test <= testCount; ++test) {
            System.err.println("test = " + test);
            int n = in.nextInt();
            int l = in.nextInt();
            int h = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < a.length; i++) {
                a[i] = in.nextLong();
            }
            int ans = -1;
            for (int i = l; i <= h; ++i) {
                boolean bad = false;
                for (int j = 0; j < n; ++j) {
                    if (!((a[j] % i == 0) || (i % a[j] == 0))) {
                        bad = true;
                        break;
                    }
                }
                if (!bad) {
                    ans = i;
                    break;
                }
            }
            out.printf("Case #%d: ", test);
            if (ans == -1) {
                out.println("NO");
            } else {
                out.println(ans);
            }

        }
        out.flush();
    }

}
