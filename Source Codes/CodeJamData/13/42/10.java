package contest;

import java.util.*;
import java.io.*;

public class ManyPrizes {
    final static String PROBLEM_NAME = "mprizes";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        long P = sc.nextLong();

        long ans1 = -1;
        long sum = 0;
        for (int i=N-1; i>=0; i--) {
            sum += (1L << i);
            if (P <= sum) {
                ans1 = (1L << (N - i)) - 1;
                break;
            }
        }
        if (ans1 == -1) ans1 = (1L << N);

        long ans2 = -1;
        int needWins = 0;
        while ((1L << (N - needWins)) > P) needWins++;
        ans2 = (1L << N) - (1L << needWins) + 1;

        ans1--; ans2--;
        pw.println(ans1+" "+ans2);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ManyPrizes().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
