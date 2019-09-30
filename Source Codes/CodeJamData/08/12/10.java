import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class B {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new B().solve());
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        boolean[][] a = new boolean[m][n];
        int[] q = new int[m];
        int[] w = new int[m];
        Arrays.fill(w, -1);
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            for (int j = 0; j < t; j++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt();
                if (y == 0) {
                    a[i][x] = true;
                    q[i]++;
                } else {
                    w[i] = x;
                }
            }
        }
        boolean[] e = new boolean[n];
        while (true) {
            boolean ok = true;
            for (int i = 0; i < m; i++) {
                if (q[i] == 0) {
                    if (w[i] == -1) {
                        return "IMPOSSIBLE";
                    } else if (!e[w[i]]) {
                        ok = false;
                        e[w[i]] = true;
                        for (int j = 0; j < m; j++) {
                            if (a[j][w[i]]) q[j]--;
                        }
                    }
                }
            }
            if (ok) break;
        }
        String res = "";
        for (int i = 0; i < n; i++) {
            if (i > 0) res += " ";
            res += e[i] ? 1 : 0;
        }
        return res;
    }
}