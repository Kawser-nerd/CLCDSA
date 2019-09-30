import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.stream.Stream;

public class PonyExpress {

    static int N, Q;
    static double[] E, S;
    static double[][] D;

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner cin = new Scanner(new File("C-small-attempt0.in"));
//        PrintStream cout = new PrintStream("C-small-attempt0.out");
        Scanner cin = new Scanner(new File("C-large.in"));
        PrintStream cout = new PrintStream("C-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;


            N = cin.nextInt();
            Q = cin.nextInt();
            E = new double[N];
            S = new double[N];
            for (int i = 0; i < N; i++) {
                E[i] = cin.nextInt();
                S[i] = cin.nextInt();
            }
            D = new double[N][N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    D[i][j] = cin.nextInt();
                }

            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    if (k == i) continue;
                    if (D[i][k] < 0) continue;
                    for (int j = 0; j < N; j++) {
                        if (j == i || j == k) continue;
                        if (D[k][j] < 0) continue;
                        if (D[i][j] < 0 || D[i][j] > D[i][k] + D[k][j]) {
                            D[i][j] = D[i][k] + D[k][j];
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == j) continue;
                    if (D[i][j] < 0) continue;
                    if (D[i][j] > E[i]) {
                        D[i][j] = -1;
                    } else {
                        D[i][j] /= S[i];
                    }
                }
            }
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    if (k == i) continue;
                    if (D[i][k] < 0) continue;
                    for (int j = 0; j < N; j++) {
                        if (j == i || j == k) continue;
                        if (D[k][j] < 0) continue;
                        if (D[i][j] < 0 || D[i][j] > D[i][k] + D[k][j]) {
                            D[i][j] = D[i][k] + D[k][j];
                        }
                    }
                }
            }

            StringJoiner joiner = new StringJoiner(" ");
            for (int i = 0; i < Q; i++) {
                int u = cin.nextInt() - 1;
                int v = cin.nextInt() - 1;
                joiner.add(String.format("%.10f", D[u][v]));
            }
            cout.printf("Case #%d: %s%n", _case, joiner.toString());
        }

        cin.close();
        cout.close();
    }
}
