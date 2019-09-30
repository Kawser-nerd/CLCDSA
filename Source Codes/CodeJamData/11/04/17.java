import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
public class D_small {

    public static void main(String[] args) throws Exception {
        new D_small();
    }

    public D_small() throws Exception {
        line = br.readLine();
        st = new StringTokenizer(line); 
        int caseCount = Integer.parseInt(st.nextToken());
        for (int caseNum = 1; caseNum <= caseCount; caseNum++) {
            String ans = null;

            int N = Integer.parseInt(br.readLine());

            line = br.readLine();
            st = new StringTokenizer(line);

            int miss = 0;
            for (int i=1;i<=N;i++) {
                int v = Integer.parseInt(st.nextToken());
                if (v!=i)
                    miss++;
            }

            if (miss<2)
                ans = "0";
            else 
                ans = miss+"";

            

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
