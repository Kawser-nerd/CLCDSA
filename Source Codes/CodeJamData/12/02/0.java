package gcj;

import java.util.*;
import java.io.*;

public class DancingWithGoogle {
    final static String PROBLEM_NAME = "dance";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static int[][] maxBest = new int[31][2];

    static void preprocess() {
        for (int i=0; i<=30; i++)
            Arrays.fill(maxBest[i], -1);

        for (int A=0; A<=10; A++)
            for (int B=A; B<=10 && B<=A+2; B++)
                for (int C=B; C<=10 && C<=A+2; C++) {
                    int tot = A+B+C, sur = (C - A == 2 ? 1 : 0);
                    maxBest[tot][sur] = Math.max(maxBest[tot][sur], C);
                }
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int S = sc.nextInt();
        int p = sc.nextInt();
        int[] tot = new int[N];
        for (int i=0; i<N; i++)
            tot[i] = sc.nextInt();

        int[][] dp = new int[N+1][N+1];
        for (int i=0; i<=N; i++)
            Arrays.fill(dp[i], -100000);
        dp[0][0] = 0;

        for (int pos=0; pos<N; pos++)
            for (int sur=0; sur <= pos; sur++)
                for (int nSur=0; nSur < 2; nSur++)
                    if (maxBest[tot[pos]][nSur] >= 0)
                        dp[pos+1][sur+nSur] = Math.max(dp[pos+1][sur+nSur], dp[pos][sur] + (maxBest[tot[pos]][nSur] >= p ? 1 : 0));

        pw.println(dp[N][S]);
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new DancingWithGoogle().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
