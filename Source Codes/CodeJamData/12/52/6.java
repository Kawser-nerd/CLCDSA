package gcj;

import com.sun.org.apache.xerces.internal.impl.xs.opti.DefaultXMLDocumentHandler;

import java.util.*;
import java.io.*;

public class Havannah {
    final static String PROBLEM_NAME = "havannah";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    int S, M;
    int[] x, y;

    Set<String> have;

    int[][] id;
    boolean[][] white;
    int idCnt;

    int[] p;
    int[] rank;
    boolean[] reach;

    int findSet(int x) {
        if (p[x] != x)
            p[x] = findSet(p[x]);
        return p[x];
    }

    int nonReach = 0;

    void union(int a, int b) {
        if (!reach[a] && !reach[b]) {
            nonReach--;
        } else if (!reach[a] && reach[b]) {
            reach[a] = true;
            nonReach--;
        } else if (!reach[b] && reach[a]) {
            reach[b] = true;
            nonReach--;
        }
        if (rank[a] < rank[b]) {
            p[a] = b;
        } else {
            p[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        S = sc.nextInt();
        M = sc.nextInt();
        System.out.println(S+" "+M);

        x = new int[M];
        y = new int[M];
        for (int i=0; i<M; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        final int[] dx = new int[] {0,1,1,0,-1,-1};
        final int[] dy = new int[] {1,0,1,-1,0,-1};

        have = new HashSet<String>();
        String[] Q = new String[M];
        int minBridge = M, minFork = M;

        for (int mv=0; mv<M; mv++) {
            have.add(x[mv]+" "+y[mv]);
            Set<String> inQ = new HashSet<String>();

            int qBeg = 0, qEnd = 0;
            int cornerMask = 0, edgeMask = 0;

            Q[qBeg] = x[mv]+" "+y[mv];
            inQ.add(Q[qBeg++]);

            while (qEnd < qBeg) {
                String cur = Q[qEnd++];

                int x = Integer.parseInt(cur.split(" ")[0]);
                int y = Integer.parseInt(cur.split(" ")[1]);

                if (x==1 && y==1) cornerMask |= 1;
                if (x==1 && y==S) cornerMask |= 2;
                if (x==S && y==2*S-1) cornerMask |= 4;
                if (x==2*S-1 && y==2*S-1) cornerMask |= 8;
                if (x==2*S-1 && y==S) cornerMask |= 16;
                if (x==S && y==1) cornerMask |= 32;

                if (x==1 && y>1 && y<S) edgeMask |= 1;
                if (y-x == S-1 && x>1 && x<S) edgeMask |= 2;
                if (y==2*S-1 && x>S && x<2*S-1) edgeMask |= 4;
                if (x==2*S-1 && y>S && y<2*S-1) edgeMask |= 8;
                if (x-y == S-1 && y>1 && y<S) edgeMask |= 16;
                if (y==1 && x>1 && x<S) edgeMask |= 32;

                for (int t=0; t<6; t++) {
                    String want = (x+dx[t])+" "+(y+dy[t]);
                    if (have.contains(want) && !inQ.contains(want)) {
                        Q[qBeg] = want;
                        inQ.add(Q[qBeg++]);
                    }
                }
            }

            if (minBridge == M && Integer.bitCount(cornerMask) >= 2)
                minBridge = mv;

            if (minFork == M && Integer.bitCount(edgeMask) >= 3)
                minFork = mv;

            if (minBridge<M && minFork<M) break;
        }

        int minRing = M;

        white = new boolean[2*S][2*S];

        id = new int[2*S][2*S];
        for (int i=0; i<2*S; i++)
            Arrays.fill(id[i], -1);

        idCnt = 0;
        for (int x=1; x<=2*S-1; x++) {
            int minY = (x <= S ? 1 : x-S+1);
            int maxY = (x <= S ? S+x-1 : 2*S-1);
            for (int y=minY; y<=maxY; y++)
                id[x][y] = idCnt++;
        }

        nonReach = 0;

        white = new boolean[2*S][2*S];

        for (int mv=0; mv < M; mv ++) {
            p = new int[idCnt];
            rank = new int[idCnt];
            reach = new boolean[idCnt];

            white[x[mv]][y[mv]] = true;

            nonReach = 0;

            for (int x=1; x<=2*S-1; x++) {
                int minY = (x <= S ? 1 : x-S+1);
                int maxY = (x <= S ? S+x-1 : 2*S-1);
                for (int y=minY; y<=maxY; y++) {
                    p[id[x][y]] = id[x][y];
                    reach[id[x][y]] = (x==1 || x==2*S-1 || y==1 || y==2*S-1 || x-y==S-1 || y-x==S-1);
                    if (white[x][y]) reach[id[x][y]] = true;
                    if (!reach[id[x][y]]) nonReach++;
                }
            }

            for (int x=1; x<=2*S-1; x++) {
                int minY = (x <= S ? 1 : x-S+1);
                int maxY = (x <= S ? S+x-1 : 2*S-1);
                for (int y=minY; y<=maxY; y++) {
                    if (white[x][y]) continue;
                    int A = id[x][y];
                    for (int t=0; t<6; t++) {
                        int xx = x + dx[t];
                        int yy = y + dy[t];
                        if (xx>=0 && xx<2*S && yy>=0 && yy<2*S && id[xx][yy] != -1 ) {
                            if (white[xx][yy]) continue;
                            int B = id[xx][yy];
                            if (findSet(A) != findSet(B))
                                union(findSet(A), findSet(B));
                        }
                    }
                }
            }

            if (nonReach > 0) {
                minRing = mv;
                break;
            }
        }

//        for (int i=0; i<M; i++)
//            white[x[i]][y[i]] = true;
//
//        for (int x=1; x<=2*S-1; x++) {
//            int minY = (x <= S ? 1 : x-S+1);
//            int maxY = (x <= S ? S+x-1 : 2*S-1);
//            for (int y=minY; y<=maxY; y++) {
//                p[id[x][y]] = id[x][y];
//                reach[id[x][y]] = (x==1 || x==2*S-1 || y==1 || y==2*S-1 || x-y==S-1 || y-x==S-1);
//                if (white[x][y]) reach[id[x][y]] = true;
//                if (!reach[id[x][y]]) nonReach++;
//            }
//        }
//
//        for (int x=1; x<=2*S-1; x++) {
//            int minY = (x <= S ? 1 : x-S+1);
//            int maxY = (x <= S ? S+x-1 : 2*S-1);
//            for (int y=minY; y<=maxY; y++) {
//                if (white[x][y]) continue;
//                int A = id[x][y];
//                for (int t=0; t<6; t++) {
//                    int xx = x + dx[t];
//                    int yy = y + dy[t];
//                    if (xx>=0 && xx<2*S && yy>=0 && yy<2*S && id[xx][yy] != -1 ) {
//                        if (white[xx][yy]) continue;
//                        int B = id[xx][yy];
//                        if (findSet(A) != findSet(B))
//                            union(findSet(A), findSet(B));
//                    }
//                }
//            }
//        }
//
//        for (int i=M-1; i>=0; i--) {
//            if (nonReach > 0)
//                minRing = i;
//
//            white[x[i]][y[i]] = false;
//            reach[id[x[i]][y[i]]] = false;
//            nonReach++;
//            int A = id[x[i]][y[i]];
//
//            for (int t=0; t<6; t++) {
//                int xx = x[i] + dx[t];
//                int yy = y[i] + dy[t];
//                if (xx>=0 && xx<2*S && yy>=0 && yy<2*S && id[xx][yy] != -1 ) {
//                    if (white[xx][yy]) continue;
//                    int B = id[xx][yy];
//                    if (findSet(A) != findSet(B))
//                        union(findSet(A), findSet(B));
//                }
//            }
//        }

        int when = Math.min(Math.min(minBridge, minFork), minRing);

        if (when == M) {
            pw.println("none");
            return;
        }

        if (minBridge==when && minFork>when && minRing>when)
            pw.println("bridge in move " + (when+1));

        if (minBridge>when && minFork==when && minRing>when)
            pw.println("fork in move " + (when+1));

        if (minBridge>when && minFork>when && minRing==when)
            pw.println("ring in move " + (when+1));

        if (minBridge==when && minFork==when && minRing>when)
            pw.println("bridge-fork in move " + (when+1));

        if (minBridge==when && minFork>when && minRing==when)
            pw.println("bridge-ring in move " + (when+1));

        if (minBridge>when && minFork==when && minRing==when)
            pw.println("fork-ring in move " + (when+1));

        if (minBridge==when && minFork==when && minRing==when)
            pw.println("bridge-fork-ring in move " + (when+1));
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Havannah().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
