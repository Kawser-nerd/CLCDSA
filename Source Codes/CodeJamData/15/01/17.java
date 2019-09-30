import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    void solve(int caseNum) {
        int n = in.nextInt();
        String s = in.next();
        int p = 0;
        int r = 0;
        for (int i=0; i<=n; i++) {
            int t = max(i-p, 0);
            r += t;
            p += t + s.charAt(i) - '0';
        }
        out.println(r);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public A() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new A();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
