package gcj;

import java.util.*;
import java.io.*;

public class OutOfGas {
    final static String PROBLEM_NAME = "gas";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    void solve(Scanner sc, PrintWriter pw) {
        double D = Double.parseDouble(sc.next());
        int N = sc.nextInt();
        int A = sc.nextInt();
        double[] t = new double[N];
        double[] x = new double[N];
        for (int i=0; i<N; i++) {
            t[i] = Double.parseDouble(sc.next());
            x[i] = Double.parseDouble(sc.next());
        }

        while (N>1 && x[N-2]>=D) N--;
        if (N == 1) {
            t[0] = 0;
            x[0] = D;
        } else {
            t[N-1] = t[N-2] + (t[N-1] - t[N-2]) * ((D - x[N-2]) / (x[N-1] - x[N-2]));
            x[N-1] = D;
        }

        for (int iter=0; iter<A; iter++) {
            double acc = Double.parseDouble(sc.next());
            double wait = 0.0;
            for (int i=0; i<N; i++) {
                double timeAt = Math.sqrt(2 * x[i] / acc);
                if (timeAt < t[i])
                    wait = Math.max(wait, t[i] - timeAt);
            }
            pw.println(wait + Math.sqrt(2 * D / acc));
        }
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.println("Case #" + (caseNum+1) + ":");
            new OutOfGas().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
