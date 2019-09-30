package gcj;

import java.util.*;
import java.io.*;

public class Descend {
    final static String PROBLEM_NAME = "descend";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    int N, M;
    char[][] map;
    int[] caveX = new int[10];
    int[] caveY = new int[10];
    int[][] id;
    int[] xById;
    int[] yById;

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();
        map = new char[N][M];
        Arrays.fill(caveX, -1);
        for (int i=0; i<N; i++) {
            map[i] = sc.nextLine().toCharArray();
            for (int j=0; j<M; j++) {
                if (map[i][j] >= '0' && map[i][j] <= '9') {
                    caveX[map[i][j] - '0'] = i;
                    caveY[map[i][j] - '0'] = j;
                    map[i][j] = '.';
                }
            }
        }

        id = new int[N][M];
        xById = new int[N*M];
        yById = new int[N*M];
        int pos = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                if (map[i][j] == '.') {
                    id[i][j] = pos;
                    xById[pos] = i;
                    yById[pos] = j;
                    pos++;
                }

        int idCnt = pos;
        for (int i=0; i<10; i++) {
            if (caveX[i] == -1)
                continue;
            long curMask = (1L << id[caveX[i]][caveY[i]]);
            while (true) {
                long nextMask = curMask;
                for (int t=0; t<idCnt; t++)
                    if ((curMask & (1L << t)) != 0) {
                        int x = xById[t];
                        int y = yById[t];
                        if (y+1 < M && map[x][y+1] == '.')
                            nextMask |= (1L << id[x][y+1]);
                        if (y > 0 && map[x][y-1] == '.')
                            nextMask |= (1L << id[x][y-1]);
                        if (x > 0 && map[x-1][y] == '.')
                            nextMask |= (1L << id[x-1][y]);
                    }
                if (nextMask == curMask)
                    break;
                curMask = nextMask;
            }
            pw.print(i + ": " + Long.bitCount(curMask) + " ");
            Set<Long> visited = new HashSet<Long>();
            Queue<Long> q = new LinkedList<Long>();
            q.add(curMask);
            visited.add(curMask);
            long wantMask = (1L << id[caveX[i]][caveY[i]]);
            while (!q.isEmpty() && !visited.contains(wantMask)) {
                curMask = q.poll();

                long nextMask = 0;
                for (int t=0; t < 64; t++)
                    if ((curMask & (1L << t)) != 0) {
                        int x = xById[t];
                        int y = yById[t];
                        if (y+1 < M && map[x][y+1] == '.') y++;
                        nextMask |= (1L << id[x][y]);
                    }
                if (!visited.contains(nextMask)) {
                    visited.add(nextMask);
                    q.add(nextMask);
                }

                nextMask = 0;
                for (int t=0; t < 64; t++)
                    if ((curMask & (1L << t)) != 0) {
                        int x = xById[t];
                        int y = yById[t];
                        if (y > 0 && map[x][y-1] == '.') y--;
                        nextMask |= (1L << id[x][y]);
                    }
                if (!visited.contains(nextMask)) {
                    visited.add(nextMask);
                    q.add(nextMask);
                }

                nextMask = 0;
                for (int t=0; t < 64; t++)
                    if ((curMask & (1L << t)) != 0) {
                        int x = xById[t];
                        int y = yById[t];
                        if (x+1 < N && map[x+1][y] == '.') x++;
                        nextMask |= (1L << id[x][y]);
                    }
                if (!visited.contains(nextMask)) {
                    visited.add(nextMask);
                    q.add(nextMask);
                }
            }
            pw.println(visited.contains(wantMask) ? "Lucky" : "Unlucky");
        }
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.println("Case #" + (caseNum + 1) + ":");
            new Descend().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
