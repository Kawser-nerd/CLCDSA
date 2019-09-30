import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.util.logging.FileHandler;

/**
 * Created with IntelliJ IDEA.
 * User: Roma
 * Date: 01.06.13
 * Time: 18:06
 * To change this template use File | Settings | File Templates.
 */
public class Main {
    static class Pair {
        int x, y;
        boolean go;
        Pair(int x1, int y1, boolean go1) {
            x = x1;
            y = y1;
            go = go1;
        }
    }
    static class CustomComparator implements Comparator<Pair> {
        public int compare(Pair p1, Pair p2) {
            if (p1.x != p2.x) {
                return Integer.compare(p1.x, p2.x);
            }
            if (p1.go != p2.go) {
                return Integer.compare(p1.go?1:0, p2.go?1:0);
            }
            return 0;
        }
    }
    static BigInteger calc(int len, int n) {
        return (BigInteger.valueOf(n).multiply(BigInteger.valueOf(len))).subtract(BigInteger.valueOf(len).multiply(BigInteger.valueOf(len + 1)).divide(BigInteger.valueOf(2)));
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int T = sc.nextInt();
        for (int ti = 1; ti <= T; ti++) {
            pw.printf("Case #%d: ", ti);
            int n = sc.nextInt();
            int m = sc.nextInt();
            ArrayList<Pair> ls = new ArrayList<Pair>();
            BigInteger sum1 = BigInteger.ZERO;
            BigInteger sum2 = BigInteger.ZERO;
            for (int i = 0; i < m; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int z = sc.nextInt();
                ls.add(new Pair(x, z, false));
                ls.add(new Pair(y, z, true));
                sum1 = sum1.add(calc(y - x, n).multiply(BigInteger.valueOf(z)));
            }
            Collections.sort(ls, new CustomComparator());
            Stack<Pair> st = new Stack<Pair>();
            for (int i = 0; i < ls.size(); i++) {
                Pair tk = ls.get(i);
                if (tk.go == false) {
                    st.add(tk);
                } else {
                    int sz = tk.y;
                    while (sz > 0) {
                        Pair top = st.pop();
                        int mn = Math.min(sz, top.y);
                        sz -= mn;
                        top.y -= mn;
                        sum2 = sum2.add(calc(tk.x - top.x, n).multiply(BigInteger.valueOf(mn)));
                        if (top.y > 0) {
                            st.add(top);
                        }
                    }
                }
            }
            pw.println(sum1.subtract(sum2));
        }
        sc.close();
        pw.close();
    }
}
