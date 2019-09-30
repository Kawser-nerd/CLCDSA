package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class ErdosSzekeres {
    final static String PROBLEM_NAME = "erdos";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        for (int i=0; i<N; i++) {
            A[i] = sc.nextInt();
        }
        for (int i=0; i<N; i++) B[i] = sc.nextInt();

        boolean[][] less = new boolean[N][N];

        for (int i=0; i<N; i++) for (int j=i+1; j<N; j++)
            if (A[i] >= A[j]) less[j][i] = true;

        for (int i=0; i<N; i++) if (A[i] > 1) {
            int j = i-1;
            while (A[j] != A[i]-1) j--;
            less[j][i] = true;
        }

        for (int i=0; i<N; i++) for (int j=i+1; j<N; j++)
            if (B[i] <= B[j]) less[i][j] = true;

        for (int i=0; i<N; i++) if (B[i] > 1) {
            int j = i+1;
            while (B[j] != B[i] - 1) j++;
            less[j][i] = true;
        }

        int[] deg = new int[N];
        for (int i=0; i<N; i++) for (int j=0; j<N; j++) if (less[i][j]) deg[j]++;

        int[] ans = new int[N];
        for (int i=0; i<N; i++) {
            int pp = 0;
            while (deg[pp] != 0) pp++;
            ans[pp] = i;
            for (int j=0; j<N; j++)
                if (less[pp][j]) deg[j]--;
            deg[pp]--;
        }

        for (int i=0; i<N; i++) pw.print(" " + (ans[i]+1));
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ":");
            new ErdosSzekeres().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
