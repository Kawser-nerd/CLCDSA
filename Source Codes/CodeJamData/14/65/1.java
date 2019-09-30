import java.io.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class AllergyTesting {
    final static String PROBLEM_NAME = "allergy";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        long N = sc.nextLong();
        int A = sc.nextInt(), B = sc.nextInt();

        long[] maxN = new long[1000000];
        for (int i = 0; i < Math.min(A, B); i++) {
            maxN[i] = 1;
            if (maxN[i] >= N) {
                pw.println(i);
                return;
            }
        }
        for (int i = Math.min(A, B); i <= Math.max(A, B); i++) {
            maxN[i] = maxN[i - Math.min(A, B)] + 1;
            if (maxN[i] >= N) {
                pw.println(i);
                return;
            }
        }
        for (int i = Math.max(A, B) + 1; ; i++) {
            maxN[i] = (i >= A ? maxN[i - A] : 0) + (i >= B ? maxN[i - B] : 0);
            if (maxN[i] >= N) {
                pw.println(i);
                return;
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
            new AllergyTesting().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
