import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class CruiseControl {

    static int N, D;
    static double[] K, S, L;


    public static void main(String[] args) throws FileNotFoundException {
//        Scanner cin = new Scanner(new File("A-small-attempt0.in"));
//        PrintStream cout = new PrintStream("A-small-attempt0.out");
        Scanner cin = new Scanner(new File("A-large.in"));
        PrintStream cout = new PrintStream("A-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;

            D = cin.nextInt();
            N = cin.nextInt();
            S = new double[N];
            K = new double[N];
            L = new double[N];

            for (int i = 0; i < N; i++) {
                K[i] = cin.nextDouble();
                S[i] = cin.nextDouble();
                L[i] = (D - K[i]) / S[i];
            }

            double max = 0;
            for (double s : L)
                max = Math.max(max, s);

            double ans = D / max;
            cout.printf("Case #%d: %.10f%n", _case, ans);
        }

        cin.close();
        cout.close();
    }
}
