import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class C {

    int[][] m = new int[128][128];
    void init() {
        m['1']['1'] = '1';
        m['1']['i'] = 'i';
        m['1']['j'] = 'j';
        m['1']['k'] = 'k';

        m['i']['1'] = 'i';
        m['i']['i'] = -'1';
        m['i']['j'] = 'k';
        m['i']['k'] = -'j';

        m['j']['1'] = 'j';
        m['j']['i'] = -'k';
        m['j']['j'] = -'1';
        m['j']['k'] = 'i';

        m['k']['1'] = 'k';
        m['k']['i'] = 'j';
        m['k']['j'] = -'i';
        m['k']['k'] = -'1';
    }

    int mul(int a, int b) {
        boolean pos = (a^b) >= 0;
        int r = m[abs(a)][abs(b)];
        if (pos) return r;
        return -r;
    }

    void solve(int caseNum) {
        int l = in.nextInt();
        long _x = in.nextLong();
        if (_x>=12) _x = _x%4 + 8;
        int x = (int) _x;
        String s = in.next();

        int once = '1';
        for (int i=0; i<l; i++) {
            once = mul(once, s.charAt(i));
        }
        int all = '1';
        for (int i=0; i<x; i++) {
            all = mul(all, once);
        }

        if (all != -'1') {
            out.println("NO");
            return;
        }

        boolean[] suffix = new boolean[l*x];
        boolean done = false;
        int tail = '1';
        for (int i=l*x-1; i>=0; i--) {
            int p = i%l;
            tail = mul(s.charAt(p), tail);
            if (done || tail == 'k') {
                done = true;
                suffix[i] = true;
            }
        }
        int head = '1';
        for (int i=0; i<l*min(4, x); i++) {
            int p = i%l;
            head = mul(head, s.charAt(p));
            if (head == 'i' && suffix[i]) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public C() throws Exception {
        init();
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new C();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
