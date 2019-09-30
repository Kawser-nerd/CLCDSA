import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemA {
    final static String PROBLEM_NAME = "problem_A";
    final static String WORK_DIR = "C:\\GCJ\\" + PROBLEM_NAME + "\\";

    long X, N;
    int C;
    long[] s, e, t;

    long ans = 0;

    long numEven(long A, long B) {
        A++; B--;
        if (A%2 != 0) A++;
        if (B%2 != 0) B--;
        if (A > B) return 0;
        return (B - A) / 2 + 1;
    }

    void test(long ID) {
        List<Long> block = new ArrayList<Long>();
        for (int i=0; i < C; i++) {
            long travelTime = e[i] - s[i];
            if (travelTime < 0) travelTime += N;
            long startID = mod(s[i] + t[i]);

            long meet = ID - startID;
            if (meet < 0) meet += N;
            if (meet <= 2 * travelTime) {
                block.add(2 * t[i] + meet);
            }
            if (meet + N <= 2 * travelTime) {
                block.add(2 * t[i] + meet + N);
            }
        }
        block.add(-1L);
        block.add(2*X+1);
        Collections.sort(block);
        for (int i=0; i + 1 < block.size(); i++) ans = Math.max(ans, numEven(block.get(i), block.get(i+1)));
    }

    long mod(long X) {
        return (X % N + N) % N;
    }

    void solve(Scanner sc, PrintWriter pw) {
        C = sc.nextInt();
        X = sc.nextLong();
        N = sc.nextLong();
        s = new long[C];
        e = new long[C];
        t = new long[C];
        for (int i=0; i<C; i++) {
            s[i] = sc.nextLong() - 1;
            e[i] = sc.nextLong() - 1;
            t[i] = sc.nextLong();
        }

        /*char[][] c = new char[(int)N][(int)(2*X+1)];
        for (int i=0; i<c.length; i++) Arrays.fill(c[i], '.');
        for (int i=0; i<C; i++) {
            int startID = (int)(mod(s[i] + t[i]));
            long travelTime = e[i] - s[i];
            if (travelTime < 0) travelTime += N;

            for (int j=0; j <= 2 * travelTime; j++)
                c[(int)mod(startID+j)][(int)(2*t[i]+j)] = '#';
        }

        for (int i=0; i<c.length; i++) System.out.println(new String(c[i]));
        System.out.println();*/

        for (int i=0; i<C; i++) {
            long startID = mod(s[i] + t[i]);
            long travelTime = e[i] - s[i];
            if (travelTime < 0) travelTime += N;
            long finishTime = t[i] + travelTime;
            long finishID = mod(e[i] + finishTime);
            for (int delta = -1; delta <= 1; delta++) {
                test(mod(startID + delta));
                test(mod(finishID + delta));
            }
        }

        test(0);

        pw.println(Math.max(0, ans - 1));
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemA().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
