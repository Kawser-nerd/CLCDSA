import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class RollerCoasterScheduling {

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner cin = new Scanner(new File("B-small-attempt0.in"));
//        PrintStream cout = new PrintStream("B-small-attempt0.out");
        Scanner cin = new Scanner(new File("B-large.in"));
        PrintStream cout = new PrintStream("B-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;

            int N = cin.nextInt();
            int C = cin.nextInt();
            int M = cin.nextInt();
            int[][] a = new int[C + 1][N + 1];
            for (int i = 0; i < M; i++) {
                int p = cin.nextInt();
                int b = cin.nextInt();
                a[b][p]++;
            }

            int totalTrains = 0;
            for (int i = 1; i <= C; i++) {
                int sum = 0;
                for (int j = 1; j <= N; j++)
                    sum += a[i][j];
                totalTrains = Math.max(totalTrains, sum);
            }
            int prefixColSum = 0;
            for (int j = 1; j <= N; j++) {
                for (int i = 1; i <= C; i++)
                    prefixColSum += a[i][j];
                totalTrains = Math.max(totalTrains, (prefixColSum + j - 1) / j);
            }

            int promotion = 0;
            for (int j = N; j >= 1; j--) {
                int sum = 0;
                for (int i = 1; i <= C; i++)
                    sum += a[i][j];
                int extra = Math.max(0, sum - totalTrains);
                promotion += extra;
            }

            String ans = "" + totalTrains + " " + promotion;
            cout.printf("Case #%d: %s%n", _case, ans);
        }

        cin.close();
        cout.close();
    }
}
