import java.util.*;
import java.io.*;
import java.math.*;

public class Pool {
    final static String PROBLEM_NAME = "pool";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    static class Data implements Comparable<Data> {
        double A, B;
        int id;
        public Data(double A, double B, int id) {
            this.A = A;
            this.B = B;
            this.id = id;
        }
        public int compareTo(Data other) {
            double diff = this.B * other.A - this.A * other.B;
            if (diff < 0) {
                return -1;
            }
            if (diff == 0) {
                return 0;
            }
            return 1;
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        double V = Double.parseDouble(sc.next());
        double X = Double.parseDouble(sc.next());
        double[] R = new double[N];
        double[] C = new double[N];
        for (int i = 0; i < N; i++) {
            R[i] = Double.parseDouble(sc.next());
            C[i] = Double.parseDouble(sc.next());
        }

        boolean haveLess = false, haveMore = false;

        double[] A = new double[N];
        double[] B = new double[N];
        for (int i=0; i<N; i++) {
            A[i] = R[i] / V;
            B[i] = R[i] * (C[i] - X);
            if (C[i] <= X + 1e-7) {
                haveLess = true;
            }
            if (C[i] >= X - 1e-7) {
                haveMore = true;
            }
        }

        if (!haveLess || !haveMore) {
            pw.println("IMPOSSIBLE");
            return;
        }

        Data[] datas = new Data[N];
        for (int i=0; i<N; i++) {
            datas[i] = new Data(A[i], B[i], i);
        }

        Arrays.sort(datas);

        double sumA = 0;
        for (int i=0; i<N; i++) {
            sumA += A[i];
        }

        double left = 1 / sumA, right = 1e10;
        for (int t = 0; t < 100; t++) {
            double mid = (left + right) / 2.0;

            double min = 0.0;
            double remain = 1.0;
            for (int i=0; i < N; i++) {
                double use = Math.min(mid, remain / datas[i].A);
                remain = (use < mid ? 0 : remain - datas[i].A * use);
                min += datas[i].B * use;
            }

            double max = 0.0;
            remain = 1.0;
            for (int i = N-1; i >= 0; i--) {
                double use = Math.min(mid, remain / datas[i].A);
                remain = (use < mid ? 0 : remain - datas[i].A * use);
                max += datas[i].B * use;
            }

            if (min <=  0 && max >=  0) {
                right = mid;
            } else {
                left = mid;
            }
        }

        pw.println((left + right) / 2.0);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Pool().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
