package contest;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class PartElf {
    final static String PROBLEM_NAME = "PartElf";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    long gcd(long P, long Q) {
        while (P>0 && Q>0)
            if (P>Q) P %= Q; else Q %= P;
        return P+Q;
    }

    void solve(Scanner sc, PrintWriter pw) {
        String s = sc.next();
        String[] items = s.split("/");
        long P = Long.parseLong(items[0]);
        long Q = Long.parseLong(items[1]);
        long G = gcd(P, Q);
        P /= G;
        Q /= G;

        if ((Q & (Q - 1)) != 0) {
            pw.println("impossible");
            return;
        }

        int ans = 0;
        while (P < Q) {
            P *= 2;
            ans++;
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
            new PartElf().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
