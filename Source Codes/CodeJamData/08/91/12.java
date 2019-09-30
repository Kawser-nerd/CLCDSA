import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class A {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("a.in"));
        out = new PrintWriter("a.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new A().solve());
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        int[] c = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        n++;
        int[] pa = getSort(a);
        int[] pb = getSort(b);
//        int[] pc = getSort(c);
        boolean[] za = new boolean[n];
        boolean[] zb = new boolean[n];
        boolean[] zc = new boolean[n];
        int res = 0;
        for (int cc = 0; cc <= 10000; cc++) {
            int aa = 0;
            int bb = 10000 - aa - cc;
            if (bb < 0) continue;
            int s = 0;
            for (int i = 0; i < n; i++) {
                za[i] = (a[i] <= aa);
                zb[i] = (b[i] <= bb);
                zc[i] = (c[i] <= cc);
                if (za[i] && zb[i] && zc[i]) s++;
            }
            if (s > res) res = s;
            int j = n - 1;
            for (int i = 0; i < n; i++) {
                if (!za[pa[i]]) {
                    aa = a[pa[i]];
                    bb = 10000 - aa - cc;
                    if (bb < 0) break;
                    za[pa[i]] = true;
                    if (zb[pa[i]] && zc[pa[i]]) {
                        s++;
                    }
                     while (b[pb[j]] > bb) {
                        zb[pb[j]] = false;
                        if (za[pb[j]] && zc[pb[j]]) {
                            s--;
                        }
                        j--;
                        if (j < 0) {
                            System.out.println("");
                        }
                    }
                    if (s > res) res = s;
                }
            }
        }
        return res - 1;
    }

    private int[] getSort(final int[] a) {
        final Integer[] pp = new Integer[a.length];
        for (int i = 0; i < a.length; i++) pp[i] = i;
        Arrays.sort(pp, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return a[o1] - a[o2];
            }
        });
        int[] res = new int[a.length];
        for (int i = 0; i < a.length; i++) res[i] = pp[i];
        return res;
    }
}
