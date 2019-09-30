import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class D {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new D().solve());
        }
        out.close();
    }

    int k;
    String s;
    int[] p;
    boolean[] z;
    int res;

    private Object solve() {
        k = in.nextInt();
        s = in.next();
        p = new int[k];
        z = new boolean[k];
        res = s.length() + 1;
        bt(0);
        return "" + res;
    }

    private void bt(int i) {
        if (i == k) {
            char pc = '.';
            int r = 0;
            for (int j = 0; j < s.length() / k; j++) {
                for (int t = 0; t < k; t++) {
                    char c = s.charAt(j * k + p[t]);
                    if (c != pc) {
                        pc = c;
                        r++;
                    }
                }
            }
            res = Math.min(res, r);
        } else {
            for (p[i] = 0; p[i] < k; p[i]++) if (!z[p[i]]) {
                z[p[i]] = true;
                bt(i + 1);
                z[p[i]] = false;
            }
        }
    }
}