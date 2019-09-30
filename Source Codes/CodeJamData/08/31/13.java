
import java.util.Scanner;
import java.util.Arrays;
import java.io.File;
import java.io.PrintWriter;

/**
 * Created by IntelliJ IDEA.
 * User: Fedor
 * Date: Jul 27, 2008
 * Time: 1:04:52 PM
 * To change this template use File | Settings | File Templates.
 */
public class Text {


    public static void main(String[] args) throws Exception {
//n, A, B, C, D, x0, y0 and M

        Scanner in = new Scanner(new File("A-large.in.txt"));
        PrintWriter out = new PrintWriter("text.out");

        int tests = in.nextInt();

        for (int t = 1; t <= tests; t++) {
            long result = 0;

            int p = in.nextInt();
            int k = in.nextInt();
            int n = in.nextInt();
            long[] x = new long[n];

            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
            }
            Arrays.sort(x);

            long u = 1;
            long h = 0;
            for (int i = n-1; i >= 0; i--) {

                if (result < 0 || u * x[i] < 0)
                    throw new IllegalStateException();

                result += u * x[i];
                h++;
                if (h >= k) {
                    h = 0;
                    u++;
                }

            }


            out.println("Case #" + t + ": " + result);


        }


        in.close();
        out.close();


    }

}
