package gcj;

import com.sun.org.apache.xerces.internal.impl.xs.opti.DefaultXMLDocumentHandler;

import java.util.*;
import java.io.*;

public class HallOfMirrors {
    final static String PROBLEM_NAME = "mirrors";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    int H, W, D;
    double stX, stY;
    int res = 0;
    String[] map;

    int gcd(int a, int b) {
        while (a>0 && b>0)
            if (a>b) a %= b; else b %= a;
        return a + b;
    }

    final double EPS = 1e-10;

    double getT(double cur, int V) {
        cur *= 2; V *= 2;
        if (V == 0)
            return 1e100;
        if (V > 0) {
            double want = Math.ceil(cur + EPS);
            return (want - cur) / V;
        } else {
            double want = Math.floor(cur - EPS);
            return (want - cur) / V;
        }
    }

    boolean isInteger(double x) {
        return Math.abs(x - Math.floor(x)) <= EPS || Math.abs(x - Math.ceil(x)) <= EPS;
    }

    boolean inMirror(double x, double y) {
        int xx = (int)Math.floor(x);
        int yy = (int)Math.floor(y);
        return map[xx].charAt(yy) == '#';
    }

    void process(int dx, int dy) {
        double curX = stX, curY = stY;
        double dist = 0.0;
        while (true) {
            double t1 = getT(curX, dx);
            double t2 = getT(curY, dy);
            double t = Math.min(t1, t2);

            double nextX = curX + t * dx;
            double nextY = curY + t * dy;

            double piece = Math.sqrt((nextX - curX) * (nextX - curX) + (nextY - curY) * (nextY - curY));
            dist += piece;
            if (dist > D + EPS)
                return;

            if (Math.abs(nextX - stX) <= EPS && Math.abs(nextY - stY) <= EPS) {
                res++;
                return;
            }

            curX = nextX;
            curY = nextY;

            boolean fx = isInteger(nextX);
            boolean fy = isInteger(nextY);

            if (fx && fy) {
                // corner
                // A B
                // C D
                boolean A = inMirror(nextX - EPS, nextY - EPS);
                boolean B = inMirror(nextX - EPS, nextY + EPS);
                boolean C = inMirror(nextX + EPS, nextY - EPS);
                boolean D = inMirror(nextX + EPS, nextY + EPS);

                int cnt = (A ? 1 : 0) + (B ? 1 : 0) + (C ? 1 : 0) + (D ? 1 : 0);
                if (cnt == 3) {
                    dx = -dx;
                    dy = -dy;
                } else if ((A && B && !C && !D) || (!A && !B && C & D)) {
                    dx = -dx;
                } else if ((A && C && !B && !D) || (!A && !C && B && D)) {
                    dy = -dy;
                } else if (inMirror(nextX + (dx > 0 ? EPS : -EPS), nextY + (dy > 0 ? EPS : -EPS))) {
                    return;
                } else {
                    // just continue;
                }
            } else if (fx && !fy) {
                // horizontal
                if (dx != 0 && inMirror(nextX + (dx > 0 ? EPS : -EPS), nextY))
                    dx = -dx;
            } else if (!fx && fy) {
                // vertical
                if (dy != 0 && inMirror(nextX, nextY + (dy > 0 ? EPS : -EPS)))
                    dy = -dy;
            } else {
                // nothing
            }
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        H = sc.nextInt();
        W = sc.nextInt();
        D = sc.nextInt();
        map = new String[H];
        for (int i=0; i<H; i++)
            map[i] = sc.next();

        for (int i=0; i<H; i++)
            for (int j=0; j<W; j++)
                if (map[i].charAt(j) == 'X') {
                    stX = i + 0.5;
                    stY = j + 0.5;
                }

        for (int dx=-D; dx<=D; dx++)
            for (int dy=-D; dy<=D; dy++)
                if (dx*dx + dy*dy > 0 && dx*dx + dy*dy <= D * D && gcd(Math.abs(dx), Math.abs(dy)) == 1) {
                    process(dx, dy);
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
            new HallOfMirrors().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
