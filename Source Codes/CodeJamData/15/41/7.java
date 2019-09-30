import java.util.*;
import java.io.*;
import java.math.*;

public class Pegman {
    final static String PROBLEM_NAME = "pegman";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int R = sc.nextInt();
        int C = sc.nextInt();
        char[][] map = new char[R][];
        for (int i=0; i<R; i++) {
            map[i] = sc.next().toCharArray();
        }

        final int[] dr = new int[] {1, -1, 0, 0};
        final int[] dc = new int[] {0, 0, -1, 1};
        int ans = 0;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (map[i][j] == '.') {
                    continue;
                }
                int[] nghCnt = new int[4];
                for (int d = 0; d < 4; d++) {
                    int ii = i + dr[d];
                    int jj = j + dc[d];
                    while (ii >= 0 && ii < R && jj >= 0 && jj < C) {
                        if (map[ii][jj] != '.') {
                            nghCnt[d]++;
                        }
                        ii += dr[d];
                        jj += dc[d];
                    }
                }
                if (nghCnt[0] + nghCnt[1] + nghCnt[2] + nghCnt[3] == 0) {
                    pw.println("IMPOSSIBLE");
                    return;
                }
                int ourD;
                if (map[i][j] == 'v') {
                    ourD = 0;
                } else if (map[i][j] == '^') {
                    ourD = 1;
                } else if (map[i][j] == '<') {
                    ourD = 2;
                } else {
                    ourD = 3;
                }
                if (nghCnt[ourD] == 0) {
                    ans++;
                }
            }
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
            new Pegman().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
