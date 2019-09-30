package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class GoodLuckLarge {
    final static String PROBLEM_NAME = "GLLarge";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static int T, R, N, M, K;
    static int[] A;

    static Map<String, Integer> mp = new HashMap<String, Integer>();
    static List<String> answers = new ArrayList<String>();
    static List<Long> answerCnt = new ArrayList<Long>();

    static int states = 0;
    static long fact(long n) {
        return n == 0 ? 1 : n * fact(n-1);
    }

    static void go(int pos, int what) {
        if (pos == N) {
            states++; if (states%100==0) System.out.println(states);
            String key = "";
            for (int i=0; i < N; i++) key += A[i];
            answers.add(key);

            long cnt = 1;
            for (int x = 2; x <= M; x++) {
                int tt = 0;
                for (int i=0; i < N; i++) if (A[i] == x) tt++;
                cnt *= fact(tt);
            }

            cnt = fact(N) / cnt;
            answerCnt.add(cnt);

            key += " ";
            for (int mask = 0; mask < (1<<N); mask++) {
                long prod = 1;
                for (int i=0; i < N; i++)
                    if ((mask & (1<<i)) != 0) prod *= A[i];
                String key2 = key + prod;
                if (!mp.containsKey(key2)) mp.put(key2, 0);
                mp.put(key2, mp.get(key2) + 1);
            }
            return;
        }
        for (A[pos] = what; A[pos] <= M; A[pos]++)
            go(pos+1, A[pos]);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        T = sc.nextInt();
        R = sc.nextInt(); N = sc.nextInt(); M = sc.nextInt(); K = sc.nextInt();

        A = new int[N];
        go(0, 2);

        pw.println("Case #1:");
        for (int r = 0; r < R; r++) {
            long[] prod = new long[K];
            for (int k=0; k < K; k++) prod[k] = sc.nextLong();
            double maxProb = 0;
            String ans = answers.get(0);
            for (int pos = 0; pos < answers.size(); pos++) {
                String cand = answers.get(pos);
                double prob = 0;
                for (int k=0; k < K; k++) {
                    String key = cand + " " + prod[k];
                    int cnt = (mp.containsKey(key) ? mp.get(key) : 0);
                    if (cnt == 0) {
                        prob = -1e100;
                        break;
                    } else prob += Math.log(cnt);
                }
                prob += Math.log(answerCnt.get(pos));
                if (prob > maxProb) {
                    maxProb = prob;
                    ans = cand;
                }
            }
            pw.println(ans);
            System.out.println("Solving " + r + " " + maxProb);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
