package gcj;

import java.util.*;
import java.io.*;

public class Aerobics {
    final static String PROBLEM_NAME = "aerobics";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    class Square implements Comparable<Square> {
        int R, id;
        public Square(int R, int id) {this.R=R; this.id=id;}
        public int compareTo(Square other) {
            return other.R - this.R;
        }
    }

    boolean ok(int cx, int cy, int i, int[] x, int[] y, Square[] data, int W, int L) {
        if (cx<0 || cx>W || cy<0 || cy>L)
            return false;
        for (int j=0; j<i; j++)
            if (Math.abs(cx - x[j]) < data[i].R + data[j].R &&
                Math.abs(cy - y[j]) < data[i].R + data[j].R)
                return false;
        return true;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int W = sc.nextInt();
        int L = sc.nextInt();

        Square[] data = new Square[N];
        for (int i=0; i<N; i++)
            data[i] = new Square(sc.nextInt(), i);

        Arrays.sort(data);

        int[] x = new int[N];
        int[] y = new int[N];
        x[0] = y[0] = 0;

        for (int i=1; i<N; i++) {
            int minCx = W + 1;
            int minCy = -1;
            for (int j=0; j < i; j++) {
                int cx = x[j] + data[j].R + data[i].R;
                int cy = y[j] - data[j].R + data[i].R;
                if (cx < minCx && ok(cx, cy, i, x, y, data, W, L)) {
                    minCx = cx;
                    minCy = cy;
                }

                cx = x[j] - data[j].R + data[i].R;
                cy = y[j] + data[j].R + data[i].R;
                if (cx < minCx && ok(cx, cy, i, x, y, data, W, L)) {
                    minCx = cx;
                    minCy = cy;
                }

                cx = x[j] + data[j].R + data[i].R;
                cy = y[j];
                if (cx < minCx && ok(cx, cy, i, x, y, data, W, L)) {
                    minCx = cx;
                    minCy = cy;
                }

                cx = x[j];
                cy = y[j] + data[j].R + data[i].R;
                if (cx < minCx && ok(cx, cy, i, x, y, data, W, L)) {
                    minCx = cx;
                    minCy = cy;
                }
            }
            if (minCx == W + 1) {
                System.out.println("Failed");
                System.exit(0);
            }
            x[i] = minCx;
            y[i] = minCy;
        }

        int[] resX = new int[N];
        int[] resY = new int[N];
        for (int i=0; i<N; i++) {
            resX[data[i].id] = x[i];
            resY[data[i].id] = y[i];
        }
        for (int i=0; i<N; i++) {
            pw.print(resX[i]+" "+resY[i]);
            if (i+1<N) pw.print(" ");
        }
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Aerobics().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
