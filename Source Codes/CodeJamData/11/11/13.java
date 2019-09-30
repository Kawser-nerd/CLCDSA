import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class freecell {

    public static void main(final String... argv) throws Exception {

        final Scanner in = new Scanner(new File("freecell.in"));
        final PrintWriter pw = new PrintWriter("freecell.out");

        final int testsCnt = in.nextInt();

        for (int caseNum = 1; caseNum <= testsCnt; ++caseNum) {
            long n = in.nextLong();
            int p = in.nextInt();
            int g = in.nextInt();

            int r = -1;
            boolean ok = false;
            for (int d = 1; d <= Math.min(10000, n); ++d) {
                if (d * p % 100 == 0) {
                    ok = true;
                    r = d;
                }
            }

            if (g == 100 && p < 100) {
                ok = false;
            }
            if (g == 0 && p > 0) {
                ok = false;
            }

            pw.printf("Case #%d: %s%n", caseNum, ok ? "Possible" : "Broken");
        }
        pw.close();
        in.close();
    }
}
