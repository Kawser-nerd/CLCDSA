import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * ZZZ to be documented :TODO:
 *
 * @author Pavel Mavrin
 * @id {Id}
 */
public class A {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new A().solve());
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }

        Arrays.sort(a);
        Arrays.sort(b);

        long s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i] * 1L * b[n - i - 1];
        }

        return "" + s;
    }
}