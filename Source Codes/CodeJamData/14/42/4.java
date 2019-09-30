package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class UpAndDown {
    final static String PROBLEM_NAME = "updown";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i=0; i<N; i++) A[i] = sc.nextInt();
        int[] B = A.clone();
        Arrays.sort(B);
        for (int i=0; i<N; i++) A[i] = Arrays.binarySearch(B, A[i]);

        int[] payLeft = new int[N];
        int[] payRight = new int[N];

        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++)
                if (A[j] > A[i]) payLeft[A[i]]++;
            for (int j=i+1; j<N; j++)
                if (A[j] > A[i]) payRight[A[i]]++;
        }

        int[][] dp = new int[N][N];
        final int INF = 1000000000;
        for (int i=0; i<N; i++) Arrays.fill(dp[i], 1000000000);
        dp[N-1][N-1] = 0;
        for (int mx = N-1; mx > 0; mx--) {
            for (int mx2 = mx; mx2 < N; mx2++) {
                if (dp[mx][mx2] != INF) {
                    dp[mx][mx-1] = Math.min(dp[mx][mx-1], dp[mx][mx2] + payRight[mx-1]);
                    dp[mx-1][mx2] = Math.min(dp[mx-1][mx2], dp[mx][mx2] + payLeft[mx-1]);
                }
                if (dp[mx2][mx] != INF) {
                    dp[mx-1][mx] = Math.min(dp[mx-1][mx], dp[mx2][mx] + payLeft[mx-1]);
                    dp[mx2][mx-1] = Math.min(dp[mx2][mx-1], dp[mx2][mx] + payRight[mx-1]);
                }
            }
        }

        int ans = INF;
        for (int i=0; i<N; i++) {
            ans = Math.min(ans, dp[i][0]);
            ans = Math.min(ans, dp[0][i]);
        }

        pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new UpAndDown().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
