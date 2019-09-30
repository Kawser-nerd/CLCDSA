package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class Willow {
    final static String PROBLEM_NAME = "willow";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int N;
    int[] C = new int[N];

    class Edge {
        int from, to;
        Edge next;
        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    Edge[] adj;
    int[][] dst;

    int[][][][][][] memo;

    void addEdge(int from, int to) {
        Edge e = new Edge(from, to);
        e.next = adj[from];
        adj[from] = e;
    }

    boolean onPath(int from, int to, Edge e) {
        return dst[from][to] == dst[from][e.from] + 1 + dst[e.to][to] ||
                dst[from][to] == dst[from][e.to] + 1 + dst[e.from][to];
    }

    boolean onPath(int from, int to, int v) {
       return dst[from][to] == dst[from][v] + dst[v][to];
    }

    int solve(int who, int skips, int fromH, int toH, int fromS, int toS) {
        if (skips == 2) return 0;
        if (memo[who][skips][fromH][toH][fromS][toS] != -1000000000) return memo[who][skips][fromH][toH][fromS][toS];
        int ans = -1000000000;
        if (who == 0) {
            Edge e = adj[toH];
            int canCnt = 0;
            while (e != null) {
                if (!onPath(fromH, toH, e) && !onPath(fromS, toS, e)) {
                    ans = Math.max(ans, (onPath(fromS, toS, e.to) ? 0 : C[e.to]) - solve(1-who, 0, fromH, e.to, fromS, toS));
                    canCnt++;
                }
                e = e.next;
            }
            if (canCnt == 0) {
                ans = Math.max(ans, - solve(1-who, skips+1, fromH, toH, fromS, toS));
            }
        } else {
            Edge e = adj[toS];
            int canCnt = 0;
            while (e != null) {
                if (!onPath(fromH, toH, e) && !onPath(fromS, toS, e)) {
                    ans = Math.max(ans, (onPath(fromH, toH, e.to) ? 0 : C[e.to]) - solve(1-who, 0, fromH, toH, fromS, e.to));
                    canCnt++;
                }
                e = e.next;
            }
            if (canCnt == 0) {
                ans = Math.max(ans, - solve(1-who, skips+1, fromH, toH, fromS, toS));
            }
        }
        memo[who][skips][fromH][toH][fromS][toS] = ans;
        return ans;
    }

    void solve(Scanner sc, PrintWriter pw) {
        N = sc.nextInt();
        C = new int[N];
        for (int i=0; i<N; i++) {
            C[i] = sc.nextInt();
        }
        adj = new Edge[N];
        dst = new int[N][N];
        for (int i=0; i<N; i++) {
            Arrays.fill(dst[i], 1000000);
            dst[i][i] = 0;
        }
        for (int i=0; i<N-1; i++) {
            int from = i;
            int to = sc.nextInt()-1;
            addEdge(from, to);
            addEdge(to, from);
            dst[from][to] = dst[to][from] = 1;
        }

        for (int k=0; k<N; k++) {
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    dst[i][j] = Math.min(dst[i][j], dst[i][k] + dst[k][j]);
                }
            }
        }

        memo = new int[2][3][N][N][N][N];
        for (int i=0; i<memo.length; i++) {
            for (int j=0; j<memo[i].length; j++) {
                for (int k=0; k<memo[i][j].length; k++) {
                    for (int l=0; l<memo[i][j][k].length; l++) {
                        for (int t=0; t<memo[i][j][k][l].length; t++) {
                            Arrays.fill(memo[i][j][k][l][t], -1000000000);
                        }
                    }
                }
            }
        }
        int bestHannah = -1000000000;
        for (int i=0; i<N; i++) {
            int bestSherine = -1000000000;
            for (int j=0; j<N; j++) {
                bestSherine = Math.max(bestSherine, (j != i ? C[j] : 0) -solve(0, 0, i, i, j, j));
            }
            bestHannah = Math.max(bestHannah, C[i]-bestSherine);
        }

        pw.println(bestHannah);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Willow().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
