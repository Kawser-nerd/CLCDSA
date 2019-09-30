package contest;
import java.util.*;
import java.io.*;
import java.math.*;

public class DataPacking {
    final static String PROBLEM_NAME = "dpack";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] sz = new int[N];
        for (int i=0; i<N; i++) sz[i] = sc.nextInt();

        Arrays.sort(sz);

        int ans = N;
        for (int t=0; 2*t<=N; t++) {
            boolean ok = true;
            for (int i=0, j=2*t-1; i<j; i++, j--)
                if (sz[i] + sz[j] > X) ok = false;
            if (ok) ans = Math.min(ans, N-t);
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
            new DataPacking().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
