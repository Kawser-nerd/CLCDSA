package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class Lost {
    final static String PROBLEM_NAME = "lost";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    final int INF = 1010000000;

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int P = sc.nextInt();
        int[] u = new int[M];
        int[] v = new int[M];
        int[] a = new int[M];
        int[] b = new int[M];
        int[][] maxPath = new int[N][N];
        for (int i=0; i<N; i++) {
            Arrays.fill(maxPath[i], INF);
            maxPath[i][i] = 0;
        }
        for (int i=0; i<M; i++) {
            u[i] = sc.nextInt();
            v[i] = sc.nextInt();
            u[i]--; v[i]--;
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            maxPath[u[i]][v[i]] = Math.min(maxPath[u[i]][v[i]], b[i]);
        }
        for (int k=0; k<N; k++)
            for (int i=0; i<N; i++)
                for (int j=0; j<N; j++)
                    maxPath[i][j] = Math.min(maxPath[i][j], maxPath[i][k] + maxPath[k][j]);
        int[] pathId = new int[P];
        for (int i=0; i<P; i++) pathId[i] = sc.nextInt() - 1;

        for (int take = P; take >= 1; take--) {
            boolean[] visit = new boolean[N];
            int[] lenTo = new int[N];
            int[] path = new int[take + 1];
            path[0] = 0;
            visit[0] = true;
            lenTo[0] = 0;
            boolean ok = true;
            for (int i=0; i < take; i++) {
                path[i+1] = v[pathId[i]];
                if (visit[path[i+1]]) {
                    ok = false;
                    break;
                }
                visit[path[i+1]] = true;
                lenTo[path[i+1]] = lenTo[path[i]] + a[pathId[i]];
            }
            if (!ok) continue;
            for (int i=0; i < take && ok; i++)
                for (int j=i+1; j <= take && ok; j++)
                    if (lenTo[path[j]] - lenTo[path[i]] > maxPath[path[i]][path[j]]) {
                        ok = false;
                    }
            if (!ok) continue;
            int[] maxEnterTime = new int[N];
            for (int i=0; i<N; i++)
                if (visit[i]) {
                    maxEnterTime[i] = -1;
                } else {
                    maxEnterTime[i] = INF;
                    for (int j=0; j <= take; j++)
                        maxEnterTime[i] = Math.min(maxEnterTime[i], maxPath[path[j]][i] - (lenTo[path[take]] - lenTo[path[j]]));
                }
            int[] bestPath = new int[N];
            boolean[] used = new boolean[N];
            Arrays.fill(used, false);
            Arrays.fill(bestPath, INF);
            bestPath[path[take]] = 0;
            while (true) {
                int minV = -1, minPath = INF;
                for (int i=0; i<N; i++)
                    if (bestPath[i] < minPath && !used[i]) {
                        minV = i;
                        minPath = bestPath[i];
                    }
                if (minV == -1) break;
                used[minV] = true;
                for (int i=0; i<M; i++)
                    if (u[i] == minV && minPath + a[i] <= maxEnterTime[v[i]])
                        bestPath[v[i]] = Math.min(bestPath[v[i]], minPath + a[i]);
            }
            if (!used[1]) continue;
            if (take == P) {
                pw.println("Looks Good To Me");
            } else {
                pw.println(pathId[take] + 1);
            }
            return;
        }
        pw.println(pathId[0] + 1);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Lost().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
