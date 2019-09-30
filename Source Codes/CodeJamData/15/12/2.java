import java.util.*;
import java.io.*;
import java.math.*;

public class Haircut {
    final static String PROBLEM_NAME = "haircut";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int B = sc.nextInt();
        long N = sc.nextLong();
        int[] T = new int[B];
        for (int i = 0; i < B; i++) {
            T[i] = sc.nextInt();
        }

        long L = 0, R = 1000000000000000L;
        while (R - L > 1) {
            long mid = (L + R) / 2;
            long servedBefore = 0;
            for (int i = 0; i < B; i++) {
                servedBefore += (mid - 1) / T[i] + 1;
            }
            if (servedBefore < N) {
                L = mid;
            } else {
                R = mid;
            }
        }

        long when = L;
        for (int i = 0; i < B; i++) {
            N -= (when - 1) / T[i] + 1;
        }
        for (int i = 0; i < B; i++) {
            if (when % T[i] == 0) {
                N--;
                if (N == 0) {
                    pw.println(i + 1);
                    return;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Haircut().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
