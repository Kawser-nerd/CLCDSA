package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class WheelEasy {
    final static String PROBLEM_NAME = "wheel1";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        String s = sc.next();
        int N = s.length();
        double[] dp = new double[1<<N];
        dp[(1<<N)-1] = 0.0;
        for (int mask=(1<<N)-2; mask>=0; mask--) {
            double ans = 0.0;
            for (int pos=0; pos<N; pos++) {
                int pp = pos, wait = 0;
                while ((mask & (1<<pp)) != 0) {
                    pp = (pp+1)%N;
                    wait++;
                }
                int nmask = mask | (1<<pp);
                ans += dp[nmask] + (N - wait);
            }
            dp[mask] = ans / N;
        }
        int mask = 0;
        for (int i=0; i<N; i++)
            if (s.charAt(i) == 'X')
                mask |= (1<<i);
        pw.println(dp[mask]);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new WheelEasy().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
