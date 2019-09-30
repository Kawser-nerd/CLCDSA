import java.io.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ARAMEasy {
    final static String PROBLEM_NAME = "ARAMEasy";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int R = sc.nextInt();
        int G = sc.nextInt();

        double[] P = new double[N];
        for (int i=0; i<N; i++) {
            P[i] = Double.parseDouble(sc.next());
        }

        Arrays.sort(P);

        int MAX = 2000;

        double[][] F = new double[R*G+1][MAX+1];

        for (int st=0; st<=R*G; st++) F[st][0] = 0;

        for (int left = 1; left <= MAX; left++) {
            for (int st=0; st<=R*G; st++) {
                double ans = 0.0;
                for (int i=0; i<N; i++) {
                    double what = P[i] + F[Math.min(st+1, R*G)][left-1];
                    if (st >= G) {
                        what = Math.max(what, F[st - G][left]);
                    }
                    ans += what;
                }
                F[st][left] = ans / N;
            }
        }

        double ans = F[1][MAX] - F[0][MAX];

        double tmp = 0;
        for (double value : P) tmp += value;
        tmp /= N;

        pw.println(tmp + ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ARAMEasy().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
