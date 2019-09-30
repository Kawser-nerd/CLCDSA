import java.io.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class CheckerboardMatrix {
    final static String PROBLEM_NAME = "checker";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int count(char[][] A) {
        int N = A.length/2;

        int cnt0 = 0, cnt1 = 0;

        int[] what = new int[2*N];

        for (int i=0; i<2*N; i++) {
            boolean isZero = true, isOne = true;
            for (int j=0; j<2*N; j++) {
                if (A[i][j] != A[0][j]) isZero = false;
                if (A[i][j] == A[0][j]) isOne = false;
            }

            if (!isZero && !isOne) return 1000000;
            if (isZero) cnt0++; else cnt1++;

            what[i] = isZero ? 0 : 1;
        }

        if (cnt0 != cnt1) {
            return 1000000;
        }

        int res = 0;
        for (int i=0; i<2*N; i+=2)
            if (what[i] == 0) res++;

        if (res > N - res) res = N - res;
        return res;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        char[][] A = new char[2*N][];
        for (int i=0; i<2*N; i++) {
            A[i] = sc.next().toCharArray();
        }

        int ans = count(A);

        for (int i=0; i<2*N; i++) {
            for (int j=i+1; j<2*N; j++) {
                char tmp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = tmp;
            }
        }

        ans += count(A);

        pw.println(ans >= 1000000 ? "IMPOSSIBLE" : ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new CheckerboardMatrix().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
