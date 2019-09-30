package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class DontBreakTheNile {
    final static String PROBLEM_NAME = "nile";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    class Rectangle {
        int x1, y1, x2, y2;
        public Rectangle(Scanner sc) {
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
        }
        public Rectangle(Rectangle r, int d) {
            x1 = r.x1 - d;
            x2 = r.x2 + d;
            y1 = r.y1 - d;
            y2 = r.y2 + d;
        }
    }

    boolean intersect(Rectangle a, Rectangle b) {
        return Math.max(a.x1, b.x1) <= Math.min(a.x2, b.x2) &&
                Math.max(a.y1, b.y1) <= Math.min(a.y2, b.y2);
    }

    int dist(Rectangle a, Rectangle b) {
        int L = 0, R = 200000000;
        while (R-L>1) {
            int mid = (L+R)/2;
            if (intersect(new Rectangle(a, mid), b)) {
                R = mid;
            } else {
                L = mid;
            }
        }
        return L;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int W = sc.nextInt();
        int H = sc.nextInt();
        int B = sc.nextInt();
        Rectangle[] r = new Rectangle[B];
        for (int i=0; i<B; i++) {
            r[i] = new Rectangle(sc);
        }

        int[][] dist = new int[B+2][B+2];
        for (int i=0; i<B; i++) {
            dist[0][i+1] = dist[i+1][0] = r[i].x1;
            dist[B+1][i+1] = dist[i+1][B+1] = W-r[i].x2-1;
        }
        dist[0][B+1] = dist[B+1][0] = W;

        for (int i=0; i<B; i++) for (int j=i+1; j<B; j++) {
            dist[i+1][j+1] = dist[j+1][i+1] = dist(r[i], r[j]);
        }

        int[] min = new int[B+2];
        Arrays.fill(min, 200000000);
        boolean[] used = new boolean[B+2];
        min[0] = 0;
        for (int t=0; t<B+2; t++) {
            int minDist = 2000000000, minPos = -1;
            for (int i=0; i<B+2; i++) if (min[i] < minDist && !used[i]) {
                minDist = min[i];
                minPos = i;
            }
            used[minPos] = true;
            for (int i=0; i<B+2; i++) min[i] = Math.min(min[i], minDist + dist[minPos][i]);
        }

        pw.println(min[B+1]);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new DontBreakTheNile().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
