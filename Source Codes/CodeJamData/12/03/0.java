package gcj;

import java.util.*;
import java.io.*;

public class RecycledNumbers {
    final static String PROBLEM_NAME = "rnum";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int A = sc.nextInt();
        int B = sc.nextInt();
        int res = 0;
        for (int n=A; n <= B; n++) {
            String s = "" + n;
            Set<Integer> cand = new HashSet<Integer>();
            for (int st=1; st < s.length(); st++) {
                String ss = s.substring(st) + s.substring(0, st);
                int m = Integer.parseInt(ss);
                if (n < m && m >= A && m <= B)
                    cand.add(m);
            }
            res += cand.size();
        }
        pw.println(res);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new RecycledNumbers().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
