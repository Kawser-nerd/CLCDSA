package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class Bullseye {
    final static String PROBLEM_NAME = "bullseye";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        BigInteger r = new BigInteger(sc.next());
        BigInteger t = new BigInteger(sc.next());
        BigInteger left = BigInteger.ZERO;
        BigInteger right = BigInteger.valueOf(2000000000);
        while (right.subtract(left).compareTo(BigInteger.ONE) > 0) {
            BigInteger mid = (left.add(right)).divide(BigInteger.valueOf(2));
            BigInteger need = mid.multiply(r.multiply(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(3)));
            need = need.add(BigInteger.valueOf(2).multiply(mid).multiply(mid.add(BigInteger.ONE)));
            if (need.compareTo(t) <= 0) left = mid; else right = mid;
        }
        pw.println(left);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Bullseye().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
