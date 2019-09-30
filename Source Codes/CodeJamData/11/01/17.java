import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
public class A_small {

    public static void main(String[] args) throws Exception {
        new A_small();
    }

    public A_small() throws Exception {
        line = br.readLine();
        st = new StringTokenizer(line); 
        int caseCount = Integer.parseInt(st.nextToken());
        for (int caseNum = 1; caseNum <= caseCount; caseNum++) {
            String ans = null;

            line = br.readLine();
            st = new StringTokenizer(line);

            int n = Integer.parseInt(st.nextToken());

            int o = 1;
            int oLast = 0;
            int b = 1;
            int bLast = 0;

            int r = 0;
            for (int i=0;i<n;i++) {
                char who = st.nextToken().charAt(0);
                int target = Integer.parseInt(st.nextToken());
                if (who=='O') {
                    int wait = r-oLast;
                    r += max(0, abs(target-o)-wait)+1;
                    o = target;
                    oLast = r;
                } else {
                    int wait = r-bLast;
                    r += max(0, abs(target-b)-wait)+1;
                    b = target;
                    bLast = r;
                }
                // debug(o,b,r);
            }
            // debug("---");

            
            ans = r+"";

            buf.append(String.format("Case #%d: %s\n", caseNum, ans));
        }

        System.out.print(buf);
    }

    // {{{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line;
    StringTokenizer st;
    StringBuilder buf = new StringBuilder();

    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    } 
    // }}}
}
