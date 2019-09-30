import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    void solve(int caseNum) {
        int n = in.nextInt();
        int[] arr = IntStream.range(0, n)
            .map(i -> in.nextInt())
            .toArray();
        int ans = IntStream.range(1, 1001)
            .map(i -> Arrays.stream(arr).map(e -> (e-1)/i).sum()+i)
            .min().getAsInt();
        out.println(ans);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new B();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
