package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class TicketSwapping {
    final static String PROBLEM_NAME = "tswap";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    final long MOD = 1000002013;

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        long[] enterCnt = new long[N];
        long[] exitCnt = new long[N];
        long[] save = new long[N];
        save[0] = 0;
        for (int i=1; i<N; i++) save[i] = save[i-1] + (i-1);

        long origSave = 0;
        for (int i=0; i<M; i++) {
            int st = sc.nextInt(), fn = sc.nextInt();
            st--; fn--;
            long cnt = sc.nextLong();
            origSave += save[fn - st] * (cnt % MOD);
            origSave %= MOD;
            enterCnt[st] += cnt;
            exitCnt[fn] += cnt;
        }

        long[] numCards = new long[N];
        long bestSave = 0;
        for (int i=0; i <N; i++) {
            numCards[0] += enterCnt[i];

            for (int len=0; len<N; len++) {
                long cnt = Math.min(numCards[len], exitCnt[i]);
                bestSave += save[len] * (cnt % MOD);
                bestSave %= MOD;
                numCards[len] -= cnt;
                exitCnt[i] -= cnt;
            }

            for (int j=N-1; j>0; j--) numCards[j] = numCards[j-1];
            numCards[0] = 0;
        }

        long diff = (bestSave - origSave) % MOD;
        System.out.println(bestSave + " " + origSave);
        diff = (diff + MOD) % MOD;
        pw.println(diff);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new TicketSwapping().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
