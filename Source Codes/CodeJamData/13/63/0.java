import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemC {
    final static String PROBLEM_NAME = "problem_C";
    final static String WORK_DIR = "C:\\GCJ\\" + PROBLEM_NAME + "\\";

    int N;
    long[] x, y;
    boolean solved = false;

    void tryItDouble(PrintWriter pw, double dx, double dy) throws Exception {
        double A1 = dy, B1 = -dx;
        double A2 = dx, B2 = dy;

        double[] sign1 = new double[4*N];
        double[] sign2 = new double[4*N];
        for (int i=0; i<4*N; i++) {
            sign1[i] = A1 * x[i] + B1 * y[i];
            sign2[i] = A2 * x[i] + B2 * y[i];
        }

        Arrays.sort(sign1);
        Arrays.sort(sign2);

        if (sign1[2*N-1] == sign1[2*N]) return;
        if (sign2[2*N-1] == sign2[2*N]) return;

        double sign1Mid = (sign1[2*N-1] + sign1[2*N]) / 2.0;
        double sign2Mid = (sign2[2*N-1] + sign2[2*N]) / 2.0;

        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i=0; i<4*N; i++) {
            double s1 = A1 * x[i] + B1 * y[i];
            double s2 = A2 * x[i] + B2 * y[i];
            if (s1 < sign1Mid && s2 < sign2Mid) cnt1++;
            if (s1 < sign1Mid && s2 > sign2Mid) cnt2++;
            if (s1 > sign1Mid && s2 < sign2Mid) cnt3++;
            if (s1 > sign1Mid && s2 > sign2Mid) cnt4++;
        }

        if (cnt1 == N && cnt2 == N && cnt3 == N && cnt4 == N) {
            double yy = (sign2Mid * A1 - sign1Mid * A2) / (A1 * B2 - A2 * B1);
            double xx = (sign2Mid * B1 - sign1Mid * B2) / (A2 * B1 - A1 * B2);
            System.out.println("floating point case");
            System.out.println(A1 * xx + B1 * yy - sign1Mid);
            System.out.println(A2 * xx + B2 * yy - sign2Mid);
            pw.println(String.format("%.9f %.9f %.9f %.9f", xx, yy, xx + dx, yy + dy));
            solved = true;
        }
    }

    void tryItLong(PrintWriter pw, long dx, long dy) throws Exception {
        long A1 = dy, B1 = -dx;
        long A2 = dx, B2 = dy;

        long[] sign1 = new long[4*N];
        long[] sign2 = new long[4*N];
        for (int i=0; i<4*N; i++) {
            sign1[i] = A1 * x[i] + B1 * y[i];
            sign2[i] = A2 * x[i] + B2 * y[i];
        }

        Arrays.sort(sign1);
        Arrays.sort(sign2);

        if (sign1[2*N-1] == sign1[2*N]) return;
        if (sign2[2*N-1] == sign2[2*N]) return;

        double sign1Mid = (sign1[2*N-1] + sign1[2*N]) / 2.0;
        double sign2Mid = (sign2[2*N-1] + sign2[2*N]) / 2.0;

        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i=0; i<4*N; i++) {
            long s1 = A1 * x[i] + B1 * y[i];
            long s2 = A2 * x[i] + B2 * y[i];
            if (s1 < sign1Mid && s2 < sign2Mid) cnt1++;
            if (s1 < sign1Mid && s2 > sign2Mid) cnt2++;
            if (s1 > sign1Mid && s2 < sign2Mid) cnt3++;
            if (s1 > sign1Mid && s2 > sign2Mid) cnt4++;
        }

        if (cnt1 == N && cnt2 == N && cnt3 == N && cnt4 == N) {
            double yy = (sign2Mid * A1 - sign1Mid * A2) / (double)(A1 * B2 - A2 * B1);
            double xx = (sign2Mid * B1 - sign1Mid * B2) / (double)(A2 * B1 - A1 * B2);
            System.out.println("long case");
            System.out.println(A1 * xx + B1 * yy - sign1Mid);
            System.out.println(A2 * xx + B2 * yy - sign2Mid);
            pw.println(String.format("%.9f %.9f %.9f %.9f", xx, yy, xx + dx, yy + dy));
            solved = true;
        }
    }

    void solve(Scanner sc, PrintWriter pw) throws Exception {
        N = sc.nextInt();
        x = new long[4*N];
        y = new long[4*N];
        for (int i=0; i<4*N; i++) {
            x[i] = sc.nextLong();
            y[i] = sc.nextLong();
        }
        List<Double> angles = new ArrayList<Double>();
        for (int i=0; i < 4*N; i++) for (int j=0; j < 4*N; j++) if (i != j) {
            angles.add(Math.atan2(y[j] - y[i], x[i] - x[j]));
            angles.add(Math.atan2(y[j] - y[i], x[i] - x[j]) + 2 * Math.PI);
            tryItLong(pw, x[i] - x[j], y[i] - y[j]);
            if (solved) return;
        }
        Collections.sort(angles);

        for (int i=0; i + 1 < angles.size(); i++) {
            double a = (angles.get(i) + angles.get(i + 1)) / 2.0;
            tryItDouble(pw, Math.cos(a), Math.sin(a));
            if (solved) return;
        }

        pw.println("IMPOSSIBLE");
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemC().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
