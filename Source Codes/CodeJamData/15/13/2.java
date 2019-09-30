import java.util.*;
import java.io.*;
import java.math.*;

public class Logging {
    final static String PROBLEM_NAME = "logging";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    class Point implements Comparable<Point> {
        long x, y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        int getType() {
            if (x > 0) {
                return 1;
            } else if (x == 0 && y > 0) {
                return 2;
            } else if (x < 0) {
                return 3;
            } else {
                return 4;
            }
        }
        public int compareTo(Point other) {
            int t1 = getType(), t2 = other.getType();
            if (t1 != t2) {
                return t1 - t2;
            }
            if (t1 == 2 || t1 == 4) {
                return 0;
            }
            long diff = y * other.x - x * other.y;
            return (diff < 0 ? -1 : (diff > 0 ? 1 : 0));
        }
    }

    int solve(int[] X, int[] Y) {
        int N = X.length;
        Point[] p = new Point[N];
        for (int i = 0; i < N; i++) {
            p[i] = new Point(X[i], Y[i]);
        }
        Arrays.sort(p);

        int pos = 0;
        Point[] p2 = new Point[2*N];
        int[] cnt = new int[2*N];

        for (int i = 0; i < N; i++) {
            if (i == 0 || p[i].compareTo(p[i-1]) > 0) {
                p2[pos] = p[i];
                for (int j = i; j <= N; j++) {
                    if (j < N && p[j].compareTo(p[i]) == 0) {
                        cnt[pos]++;
                    } else {
                        pos++;
                        break;
                    }
                }
            }
        }

        for (int i = pos; i < 2*pos; i++) {
            p2[i] = p2[i - pos];
            cnt[i] = cnt[i - pos];
        }

        int[] cumCnt = new int[2*N+1];
        cumCnt[0] = 0;
        for (int i = 1; i <= 2*pos; i++) {
            cumCnt[i] = cumCnt[i - 1] + cnt[i - 1];
        }

        int ans = N;
        int j = 0;
        for (int i = 0; i < pos; i++) {
            if (i == j) {
                j++;
            }
            while (true) {
                long area = (p2[j].x - p2[i].x) * (p2[j].y + p2[i].y) + (0 - p2[j].x) * (0 + p2[j].y) + (p2[i].x - 0) * (p2[i].y + 0);
                if (area < 0) {
                    j++;
                } else {
                    break;
                }
            }
            int toDelete = cumCnt[j] - cumCnt[i + 1];
            ans = Math.min(ans, toDelete);
        }

        return ans;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] X = new int[N];
        int[] Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            Y[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            int[] XX = new int[N-1];
            int[] YY = new int[N-1];
            int pos = 0;
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    XX[pos] = X[j] - X[i];
                    YY[pos++] = Y[j] - Y[i];
                }
            }

            pw.println(solve(XX, YY));
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.println("Case #" + (caseNum + 1) + ":");
            new Logging().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
