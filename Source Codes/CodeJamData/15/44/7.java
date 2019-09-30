import java.util.*;
import java.io.*;
import java.math.*;

public class DrumDecorator {
    final static String PROBLEM_NAME = "drum";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int R, C;
    int[][] map;

    boolean test(int i, int j) {
        int cEq = 0;
        if (i>0 && map[i-1][j] == map[i][j]) {
            cEq++;
        }
        if (i+1<R && map[i+1][j] == map[i][j]) {
            cEq++;
        }
        if (map[i][j] == map[i][(j+1)%C]) {
            cEq++;
        }
        if (map[i][j] == map[i][(j+C-1)%C]) {
            cEq++;
        }
        return (cEq == map[i][j]);
    }

    HashSet<String> sols = new HashSet<String>();

    void go(int x, int y) {
        if (x == R) {
            boolean ok = true;
            for (int i=0; i<R && ok; i++) {
                for (int j=0; j<C && ok; j++) {
                    if (!test(i, j)) {
                        ok = false;
                    }
                }
            }
            if (!ok) {
                return;
            }
            String[] cols = new String[C];
            for (int j=0; j<C; j++) {
                cols[j] = "";
                for (int i=0; i<R; i++) {
                    cols[j] += ""+map[i][j];
                }
            }
            String best = "";
            for (int j=0; j<C; j++) {
                best += cols[j];
            }
            for (int jj=1; jj<C; jj++) {
                String tmp = "";
                for (int j=0; j<C; j++) {
                    tmp += cols[(j+jj)%C];
                }
                if (tmp.compareTo(best) < 0) {
                    best = tmp;
                }
            }
            if (!sols.contains(best)) {
                for (int i=0; i<R; i++) {
                    for (int j=0; j<C; j++) {
                        System.out.print(map[i][j]);
                    }
                    System.out.println();
                }
                System.out.println();
            }
            sols.add(best);
            return;
        }
        if (y == C) {
            go(x+1, 0);
            return;
        }
        for (map[x][y] = 1; map[x][y] <= 3; map[x][y]++) {
            if (x>0 && !test(x-1, y)) {
                continue;
            }
            go(x, y+1);
        }
    }

    int gcd(int a, int b) {
        while (a>0 && b>0) {
            if (a>b) a%=b; else b%=a;
        }
        return a+b;
    }

    int lcm(int a, int b) {
        return a*b/gcd(a,b);
    }

    final int MOD = 1000000007;

    long pow(long x, long y) {
        if (y == 1) {
            return x;
        }
        long res = pow(x, y/2);
        res = (res*res)%MOD;
        if (y%2==1) res = (res*x)%MOD;
        return res;
    }

    long inv(long x) {
        return pow(x, MOD-2);
    }

    void solve(Scanner sc, PrintWriter pw) {
        R = sc.nextInt();
        C = sc.nextInt();

        long[][][] dp = new long[R+1][5][32];

        final int[] h = new int[] {2, 1, 2, 2, 3};
        final int[] mod = new int[] {1, 1, 6, 3, 4};
        final boolean[][] match = new boolean[][] {
                {false, true, true, true, true},
                {true, false, false, false, false},
                {true, false, false, false, false},
                {true, false, false, false, false},
                {true, false, false, false, false}
        };

        for (int i=0; i<5; i++) {
            if (h[i] <= R && C % mod[i] == 0) {
                dp[h[i]][i][1<<i]= mod[i];
            }
        }

        for (int r = 1; r < R; r++) {
            for (int t = 0; t < 5; t++) {
                for (int mask=0; mask < 32; mask++) {
                    for (int nt = 0; nt < 5; nt++) {
                        if (match[t][nt] && r + h[nt] <= R && C % mod[nt] == 0) {
                            dp[r + h[nt]][nt][mask | (1<<nt)] += mod[nt] * dp[r][t][mask];
                            dp[r + h[nt]][nt][mask | (1<<nt)] %= MOD;
                        }
                    }
                }
            }
        }

        long ans = 0;
        for (int t = 0; t < 5; t++) {
            for (int mask = 0; mask < 32; mask++) {
                int cycle = 1;
                for (int i=0; i<5; i++) {
                    if ((mask &(1<<i)) != 0) {
                        cycle = lcm(cycle, mod[i]);
                    }
                }
                if (dp[R][t][mask] > 0) {
                    ans += dp[R][t][mask] * inv(cycle);
                    ans %= MOD;
                }
            }
        }

        pw.println(ans);

        /*map = new int[R][C];

        sols.clear();

        go(0, 0);

        pw.println(sols.size());*/
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new DrumDecorator().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
