import java.util.*;
import java.io.*;
import java.math.*;

public class LogSet {
    final static String PROBLEM_NAME = "logset";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    class Pair {
        long num, cnt;

        public Pair(long num, long cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }

    Pair[] reduce(Pair[] A, long num) {
        if (num == 0) {
            boolean ok = true;
            for (int i = 0; i < A.length; i++) {
                if (A[i].cnt % 2 != 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                return null;
            }
            Pair[] res = new Pair[A.length];
            for (int i = 0; i < A.length; i++) {
                res[i] = new Pair(A[i].num, A[i].cnt/2);
            }
            return res;
        }

        Pair[] res = new Pair[A.length];

        Map<Long, Long> numToCnt = new HashMap<Long, Long>();
        for (int i=0; i < A.length; i++) {
            numToCnt.put(A[i].num, A[i].cnt);
        }

        int resCnt = 0;
        for (int i=0; i < A.length; i++) {
            long want = numToCnt.get(A[i].num);
            if (want == 0) {
                continue;
            }
            long have = (numToCnt.containsKey(A[i].num + Math.abs(num)) ? numToCnt.get(A[i].num + Math.abs(num)) : 0);
            if (have < want) {
                return null;
            }
            res[resCnt++] = new Pair(num > 0 ? A[i].num : A[i].num + Math.abs(num), want);
            numToCnt.put(A[i].num + Math.abs(num), have - want);
        }

        Pair[] ret = new Pair[resCnt];
        for (int i = 0; i < resCnt; i++) {
            ret[i] = res[i];
        }

        return ret;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int P = sc.nextInt();
        long[] num = new long[P];
        long[] cnt = new long[P];
        for (int i=0; i<P; i++) {
            num[i] = sc.nextLong();
        }
        for (int i=0; i<P; i++) {
            cnt[i] = sc.nextLong();
        }
        Pair[] A = new Pair[P];
        long tot = 0;
        for (int i=0; i<P; i++) {
            A[i] = new Pair(num[i], cnt[i]);
            tot += A[i].cnt;
        }
        long N = 1;
        while ((1L<<N) < tot) {
            N++;
        }
        for (int i = 0; i < N; i++) {
            boolean find = false;
            for (int j = 0; j < A.length; j++) {
                Pair[] B = reduce(A, A[j].num);
                if (B != null) {
                    pw.print(" " + A[j].num);
                    A = B;
                    find = true;
                    break;
                }
            }
            if (!find) {
                System.out.println("ERROR: nothing is found");
                System.exit(0);
            }
        }
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new LogSet().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
