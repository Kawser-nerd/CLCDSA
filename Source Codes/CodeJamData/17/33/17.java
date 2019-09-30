import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Eldar on 4/7/2017.
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("output.txt"));
//        PrintWriter out = new PrintWriter(System.out);

        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = in.nextInt();
            int k = in.nextInt();

            double budget = in.nextDouble();
            double[] p = new double[n];
            for(int i = 0; i < n; i++) {
                p[i] = in.nextDouble();
            }

            out.println("Case #" + t + ": " + calc(p, budget));
        }
        out.close();
    }

    static double calc(double[] p, double budget) {
        double ans = 1.0;
        int n = p.length;
        Arrays.sort(p);
        for(int i = 0; i < n - 1; i++) {
            double d = p[i + 1] - p[i];
            double need = d * (i + 1);
            if (budget < need) {
                double minP = p[i] + budget / (i + 1);
                for(int j = 0; j <= i; j++) {
                    ans *= minP;
                }
                for(int j = i + 1; j < n; j++) {
                    ans *= p[j];
                }
                return ans;
            }
            budget -= need;
        }
        double minP = p[n - 1] + budget / n;
        return Math.pow(minP, n);
    }

}
