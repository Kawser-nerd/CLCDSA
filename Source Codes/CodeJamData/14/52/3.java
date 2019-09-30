package contest;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class LastHit {
    final static String PROBLEM_NAME = "lasthit";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int P, Q, N;
    int[] H, G;

    int[][][][][] memo;

    int rec(int who, int chooseFree, int pos, int HP, int free) {
        if (pos == N) return free == 0 ? 0 : -500000000;

        if (memo[who][chooseFree][pos][HP][free] != -1000000000) return memo[who][chooseFree][pos][HP][free];

        int ans = -1000000000;

        if (who == 0) {
            if (chooseFree > 0) {
                if (free > 0) {
                    if (HP > P) {
                        ans = Math.max(ans, rec(who, chooseFree, pos, HP-P, free-1));
                    } else {
                        ans = Math.max(ans, rec(who, chooseFree, pos+1, pos == N-1 ? -1 : H[pos+1], free-1) + G[pos]);
                    }
                }
                if (chooseFree == 1) {
                    ans = Math.max(ans, rec(0, 0, pos, HP, free));
                } else {
                    ans = Math.max(ans, rec(1, 0, pos, HP, free));
                }
            } else {
                ans = Math.max(ans, rec(1-who, 0, pos, HP, free));
                if (HP > P) {
                    ans = Math.max(ans, rec(1-who, 0, pos, HP-P, free));
                } else {
                    ans = Math.max(ans, rec(who, 2, pos+1, pos == N-1 ? -1 : H[pos+1], free) + G[pos]);
                }
                if (free + 1 < 5*N+5) ans = Math.max(ans, rec(1-who, 0, pos, HP, free+1));
            }
        } else {
            if (HP > Q) {
                ans = rec(1-who, 0, pos, HP-Q, free);
            } else {
                ans = rec(1-who, 1, pos+1, pos == N-1 ? -1 : H[pos+1], free);
            }
        }

        memo[who][chooseFree][pos][HP][free] = ans;
        return ans;
    }

    void solve(Scanner sc, PrintWriter pw) {
        P = sc.nextInt();
        Q = sc.nextInt();
        N = sc.nextInt();
        H = new int[N];
        G = new int[N];
        for (int i=0; i<N; i++) {
            H[i] = sc.nextInt();
            G[i] = sc.nextInt();
        }
        memo = new int[2][3][N+1][201][5*N+5];
        for (int i=0; i<memo.length; i++) {
            for (int j=0; j<memo[i].length; j++) {
                for (int k=0; k<memo[i][j].length; k++) {
                    for (int l=0; l<memo[i][j][k].length; l++) {
                        Arrays.fill(memo[i][j][k][l], -1000000000);
                    }
                }
            }
        }
        pw.println(rec(0, 0, 0, H[0], 0));
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new LastHit().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
