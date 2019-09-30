package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class TrieSharding {
    final static String PROBLEM_NAME = "trieshard";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int N, M;
    String[] s;

    char[][] c;

    long[][] C;

    final long MOD = 1000000007;

    void update(long[] A, long[] B) {
        if (B[0] > A[0]) return;
        if (B[0] == A[0]) {
            A[1] = (A[1] + B[1]) % MOD;
            return;
        }
        A[0] = B[0];
        A[1] = B[1];
    }

    final int INF = 1000000000;

    long[][][][] memo;

    long[] recurse(int from, int to, int pos, int sets) {
        if (sets > to - from + 1) return new long[] {INF, 0};
        if (from == to) return new long[] {0, 1};

        if (c[from][pos] == c[to][pos]) {
            int edges = (to - from + 1) - sets;
            long[] ans = recurse(from, to, pos+1, sets);
            ans[0] += edges;
            return ans;
        }

        if (memo[from][pos][sets] != null) return memo[from][pos][sets];

        int mid = from;
        while (c[mid][pos] == c[from][pos]) mid++;

        long[][] left = new long[sets+1][];
        long[][] right = new long[sets+1][];

        for (int t=1; t<=sets; t++) {
            int edges = (mid - from) - t;
            left[t] = recurse(from, mid-1, pos+1, t);
            left[t][0] += edges;
            right[t] = recurse(mid, to, pos, t);
        }

        long[] ans = new long[] {INF, 0};

        for (int L=1; L<=sets; L++)
            for (int R=1; R<=sets; R++) {
                if (left[L][0] >= INF/2 || right[R][0] >= INF/2) continue;
                if (L + R < sets) continue;
                long[] comb = new long[] {left[L][0] + right[R][0], left[L][1] * right[R][1] % MOD};
                int common = L + R - sets;
                comb[1] = (comb[1] * C[sets][L]) % MOD;
                comb[1] = (comb[1] * C[L][common]) % MOD;

                update(ans, comb);
            }

        memo[from][pos][sets] = ans;
        return ans;
    }

    void solve(Scanner sc, PrintWriter pw) {
        M = sc.nextInt();
        N = sc.nextInt();

        s = new String[M];
        int maxLen = 0;
        for (int i=0; i<M; i++) {
            s[i] = sc.next();
            maxLen = Math.max(maxLen, s[i].length());
        }

        Arrays.sort(s);

        c = new char[M][maxLen + 1];
        for (int i=0; i<M; i++)
            for (int j=0; j<=maxLen; j++)
                c[i][j] = (j < s[i].length() ? s[i].charAt(j) : (char)0);

        C = new long[N+1][N+1];
        for (int i=0; i<=N; i++) {
            C[i][i] = C[i][0] = 1;
            for (int j=1; j<i; j++) {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
            }
        }

        int sumLen = 0;
        for (String elm : s) sumLen += elm.length();

        memo = new long[M][maxLen+1][N+1][];

        long[] ans = new long[] {INF, 0};
        for (int sets=1; sets<=N; sets++) {
            long[] tmp = recurse(0, M-1, 0, sets);
            tmp[0] -= sets;
            tmp[1] = tmp[1] * C[N][sets] % MOD;
            update(ans, tmp);
        }

        pw.println((sumLen - ans[0]) + " " + ans[1]);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new TrieSharding().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
