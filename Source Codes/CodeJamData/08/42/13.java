import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

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
        int a = in.nextInt();

        boolean[] q = new boolean[n * m + 1];
        int[] xx = new int[n * m + 1];
        int[] yy = new int[n * m + 1];

        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= m; y++) {
                int z = (x * y);
                q[z] = true;
                xx[z] = x;
                yy[z] = y;
            }
        }

        for (int i = 0; i <= (n * m - a); i++) {
            if (q[i] && q[i + a]) {
                return "0 0 " + xx[i] + " " + yy[i + a] + " " + xx[i + a] + " " + yy[i];
            }
        }

        return "IMPOSSIBLE";
    }
}
