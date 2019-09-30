package gcj;

import java.util.*;
import java.io.*;

public class Swinging {
    final static String PROBLEM_NAME = "swing";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] dist = new int[N];
        int[] len = new int[N];
        for (int i=0; i<N; i++) {
            dist[i] = sc.nextInt();
            len[i] = sc.nextInt();
        }
        int D = sc.nextInt();
        int[] maxH = new int[N];
        Arrays.fill(maxH, -1);
        maxH[0] = dist[0];
        for (int i=0; i<N; i++) {
            if (maxH[i] == -1) continue;
            if (D - dist[i] <= maxH[i]) {
                pw.println("YES");
                return;
            }
            for (int j=i+1; j<N; j++)
                if (dist[j] - dist[i] <= maxH[i])
                    maxH[j] = Math.max(maxH[j], Math.min(len[j], dist[j] - dist[i]));
        }
        pw.println("NO");
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Swinging().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
