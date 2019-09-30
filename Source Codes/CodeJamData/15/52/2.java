import java.util.*;
import java.io.*;
import java.math.*;

public class SmoothingWindow {
    final static String PROBLEM_NAME = "smooth";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    class Segment {
        long from, to;

        public Segment(long from, long to) {
            this.from = from;
            this.to = to;
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int K = sc.nextInt();

        long[] add = new long[N];
        for (int i=0; i<K-1; i++) {
            add[i] = 0;
        }
        for (int i=K-1; i<N; i++) {
            add[i] = sc.nextLong();
            for (int j = i-1; j>i-K; j--) {
                add[i] -= add[j];
            }
        }

        Segment[] segments = new Segment[K];

        for (int i=0; i<K; i++) {
            segments[i] = new Segment(add[i], add[i]);
        }

        for (int i=K; i<N; i++) {
            segments[i%K].from = Math.min(segments[i%K].from, add[i]);
            segments[i%K].to = Math.max(segments[i%K].to, add[i]);
        }

        long L = 0;
        for (int i=0; i<K; i++) {
            L = Math.max(L, segments[i].to - segments[i].from);
        }

        L--;

        long minAdd = add[0], maxAdd = add[0];
        for (int i=1; i<N; i++) {
            minAdd = Math.min(minAdd, add[i]);
            maxAdd = Math.max(maxAdd, add[i]);
        }

        long R = maxAdd - minAdd;

        long sumSegmFrom = 0;
        long sumSegmTo = 0;
        for (int i = 0; i< K; i++) {
            sumSegmFrom += segments[i].from;
            sumSegmTo += segments[i].to;
        }

        while (R - L > 1) {
            long H = (L + R) / 2;

            long min = sumSegmTo - K * H;
            long max = sumSegmFrom;

            while (min % K != 0) {
                min++;
            }
            while (max % K != 0) {
                max--;
            }

            if (min <= max) {
                R = H;
            } else {
                L = H;
            }
        }

        pw.println(R);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new SmoothingWindow().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
