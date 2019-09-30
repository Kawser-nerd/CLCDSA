package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class Enclosure {
    final static String PROBLEM_NAME = "enclosure";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt(), M = sc.nextInt(), K = sc.nextInt();
        if (N>M) {
            int tmp = N; N = M; M = tmp;
        }
        int[][][] cur = new int[N][N][2*N+2*M+1];
        int[][][] next = new int[N][N][2*N+2*M+1];
        for (int i=0; i<N; i++) for (int j=i; j<N; j++) {
            Arrays.fill(cur[i][j], -1);
            cur[i][j][j-i+1] = j-i+1;
        }
        int ans = Integer.MAX_VALUE;
        for (int col=0; col<M; col++) {
            for (int i=0; i<N; i++) for (int j=i; j<N; j++) Arrays.fill(next[i][j], -1);
            for (int i=0; i<N; i++) for (int j=i; j<N; j++) for (int used=0; used<=2*N+2*M; used++) {
                if (cur[i][j][used] == -1) continue;
                if (cur[i][j][used] >= K) ans = Math.min(ans, used);
                for (int ni=i-1; ni<=i+1; ni++)
                    for (int nj=j-1; nj<=j+1; nj++)
                        if (ni >= 0 && ni <= nj && nj < N) {
                            int nused = used - (col == 0 ? 0 : Math.max(0, j-i-1)) + (nj - ni + 1);
                            next[ni][nj][nused] = Math.max(next[ni][nj][nused], cur[i][j][used] + (nj - ni + 1));
                        }
            }
            for (int i=0; i<N; i++) for (int j=i; j<N; j++) System.arraycopy(next[i][j], 0, cur[i][j], 0, next[i][j].length);
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
            new Enclosure().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
