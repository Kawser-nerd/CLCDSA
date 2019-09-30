import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemE {
    final static String PROBLEM_NAME = "problem_E";
    final static String WORK_DIR = "C:\\GCJ\\" + PROBLEM_NAME + "\\";

    final int MOD = 10007;

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i=0; i<N; i++) A[i] = sc.nextInt();

        int[] fact = new int[N+1];
        fact[0] = 1;
        for (int i=1; i<=N; i++) fact[i] = (fact[i-1] * i) % MOD;

        int ans = 0;

        for (int last=0; last<N; last++) {
            int[][][] cur = new int[N+1][N+1][2];
            cur[0][0][0] = 1;
            for (int pos=0; pos<N; pos++) if (pos != last) {
                int[][][] next = new int[N+1][N+1][2];
                for (int lastPos = 0; lastPos <= N; lastPos++)
                    for (int howMany = 0; howMany <= N; howMany++)
                        for (int okFlag = 0; okFlag < 2; okFlag++) {
                            if (cur[lastPos][howMany][okFlag] == 0) continue;
                            next[lastPos][howMany][okFlag] += cur[lastPos][howMany][okFlag];
                            if (next[lastPos][howMany][okFlag] >= MOD) next[lastPos][howMany][okFlag] -= MOD;

                            int lastValue = (lastPos == 0 ? Integer.MAX_VALUE : A[lastPos - 1]);
                            if (lastValue >= A[pos]) {
                                int newFlag = okFlag;
                                if (pos < last && A[pos] < A[last] || pos > last && A[last] < A[pos]) newFlag = 1;
                                next[pos + 1][howMany + 1][newFlag] += cur[lastPos][howMany][okFlag];
                                if (next[pos + 1][howMany + 1][newFlag] >= MOD) next[pos + 1][howMany + 1][newFlag] -= MOD;
                            }
                        }

                for (int i=0; i <= N; i++) for (int j=0; j<=N; j++) for (int k=0; k<2; k++) cur[i][j][k] = next[i][j][k];
            }

            for (int lastPos = 0; lastPos <= N; lastPos++)
                for (int howMany = 0; howMany <= N; howMany++)
                    if (cur[lastPos][howMany][1] > 0) {
                        int free = N - howMany - 1;
                        ans += fact[free] * cur[lastPos][howMany][1];
                        ans %= MOD;
                    }
        }

        boolean sorted = true;
        for (int i=0; i+1<N; i++) if (A[i] < A[i+1]) sorted = false;
        if (sorted) ans++;

        pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemE().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
