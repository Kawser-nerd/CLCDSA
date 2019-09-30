import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemB {
    final static String PROBLEM_NAME = "problem_B";
    final static String WORK_DIR = "C:\\GCJ\\" + PROBLEM_NAME + "\\";

    double area(double x1, double y1, double x2, double y2, double x3, double y3) {
        return (x2 - x1) * (y1 + y2) + (x3 - x2) * (y2 + y3) + (x1 - x3) * (y1 + y3);
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] T = new int[N];
        for (int i=0; i<N; i++) T[i] = sc.nextInt();

        double L = 0.0, R = 1000000.0;
        for (int it=0; it<100; it++) {
            double mid = (L + R) / 2.0;

            double[] yUp = new double[N];
            double[] yDown = new double[N];
            for (int i=0; i<N; i++) {
                yUp[i] = T[i] + mid;
                yDown[i] = T[i] - mid;
            }

            int stackCnt = 0;
            int[] stackX = new int[N];
            double[] stackY = new double[N];

            stackX[stackCnt] = 0;
            stackY[stackCnt++] = yUp[0];
            stackX[stackCnt] = 1;
            stackY[stackCnt++] = yUp[1];

            for (int i=2; i<N; i++) {
                while (stackCnt > 1 && area(stackX[stackCnt - 2], stackY[stackCnt - 2], stackX[stackCnt - 1], stackY[stackCnt - 1], i, yUp[i]) > 0) stackCnt--;
                stackX[stackCnt] = i;
                stackY[stackCnt++] = yUp[i];
            }

            for (int i=0; i + 1 < stackCnt; i++)
                for (int x = stackX[i]; x <= stackX[i+1]; x++)
                    yUp[x] = stackY[i] + (x - stackX[i]) / (double)(stackX[i+1] - stackX[i]) * (stackY[i+1] - stackY[i]);

            stackCnt = 0;

            stackX[stackCnt] = 0;
            stackY[stackCnt++] = yDown[0];
            stackX[stackCnt] = 1;
            stackY[stackCnt++] = yDown[1];

            for (int i=2; i<N; i++) {
                while (stackCnt > 1 && area(stackX[stackCnt - 2], stackY[stackCnt - 2], stackX[stackCnt - 1], stackY[stackCnt - 1], i, yDown[i]) < 0) stackCnt--;
                stackX[stackCnt] = i;
                stackY[stackCnt++] = yDown[i];
            }

            for (int i=0; i + 1 < stackCnt; i++)
                for (int x = stackX[i]; x <= stackX[i+1]; x++)
                    yDown[x] = stackY[i] + (x - stackX[i]) / (double)(stackX[i+1] - stackX[i]) * (stackY[i+1] - stackY[i]);

            boolean ok = true;
            for (int i=0; i < N; i++) if (yDown[i] > yUp[i]) ok = false;

            if (ok) R = mid; else L = mid;
        }
        pw.println((L + R) / 2.0);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemB().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
