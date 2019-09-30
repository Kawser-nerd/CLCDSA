import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
public class C_small {

    public static void main(String[] args) throws Exception {
        new C_small();
    }

    public C_small() throws Exception {
        line = br.readLine();
        st = new StringTokenizer(line); 
        int caseCount = Integer.parseInt(st.nextToken());
        for (int caseNum = 1; caseNum <= caseCount; caseNum++) {
            String ans = null;

            int N = Integer.parseInt(br.readLine());
            int total = 0;
            int xor = 0;
            int min = 1<<30;
            line = br.readLine();
            st = new StringTokenizer(line);
            for (int i=0;i<N;i++) {
                int v = Integer.parseInt(st.nextToken());
                xor ^= v;
                total += v;
                min = min(min, v);
            }

            if (xor!=0)
                ans = "NO";
            else {
                ans = total-min+"";
            }

            

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
