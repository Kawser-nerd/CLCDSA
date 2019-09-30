import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class D {

    boolean solve(int caseNum) {
        int x = in.nextInt();
        int r = in.nextInt();
        int c = in.nextInt();
        int max = max(r, c);
        int min = min(r, c);

        if (x >= 7) return false;
        if (r*c % x != 0) return false;
        if (x > max) return false;
        if (x > min*2) return false;
        if (x < min*2-1) return true;
        if (x <= 2) return true;

        if (x == 3) {
            if (min != 2) {
                debug("x == 3 && min != 2");
            }
            return true;
        }

        if (x == 4) {
            if (min != 2) {
                debug("x == 4 && min != 2");
            }
            return false;
        }

        if (x==5) {
            if (min != 3) {
                debug("x == 5 && min != 3");
            }
            return max > 5;
        }

        if (x==6) {
            if (min != 3) {
                debug("x == 6 && min != 3");
            }
            return false;
        }

        debug("never reach");
        return true;

    }

    // {{{
    Scanner in = new Scanner(System.in);
    public D() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            if (solve(caseNum)) {
                out.println("GABRIEL");
            } else {
                out.println("RICHARD");
            }
        }
    }
    public static void main(String[] args) throws Exception {
        new D();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
