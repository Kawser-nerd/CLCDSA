package gcj;

import java.util.*;
import java.io.*;

public class MountainView {
    final static String PROBLEM_NAME = "mview";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {

    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] vis = new int[N-1];
        for (int i=0; i<N-1; i++)
            vis[i] = sc.nextInt() - 1;

        long[] h = new long[N];

        while (true) {
            boolean upd = false;
            for (int i=0; i<N-1; i++) {
                int j = vis[i];
                long minH = 0;
                for (int k=i+1; k<j; k++)
                    minH = Math.max(minH, (h[k] - h[i]) * (long)(j - i) / (long)(k - i) + h[i] + 1);
                for (int k=j+1; k<N; k++)
                    minH = Math.max(minH, ((h[k] - h[i]) * (long)(j - i) + k - i - 1) / (long)(k - i) + h[i]);
                if (minH > 1000000000) {
                    pw.println("Impossible");
                    return;
                }
                if (minH > h[j]) {
                    h[j] = minH;
                    upd = true;
                }
            }
            if (!upd) break;
        }

        for (int i=0; i < N; i++) {
            pw.print(h[i]);
            if (i+1<N) pw.print(" ");
        }
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new MountainView().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
