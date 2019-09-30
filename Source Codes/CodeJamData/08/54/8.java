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

    private Object solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int r = in.nextInt();
        boolean [][] a = new boolean[n][m];
        for (int i = 0; i < r; i++) {
            a[in.nextInt() - 1][in.nextInt() - 1] = true;
        }

        int[][] d = new int[n][m];
        d[0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) if (!a[i][j]) {
                if (i > 1) {
                    d[i][j] += d[i - 2][j - 1];
                }
                if (j > 1) {
                    d[i][j] += d[i - 1][j - 2];
                }
                d[i][j] %= 10007;
            }
        }

        return d[n - 1][m - 1];
    }
}
