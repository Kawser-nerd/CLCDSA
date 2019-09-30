import java.io.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class PowerSwapper {
    final static String PROBLEM_NAME = "power";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int[] reduce(int[] p) {
        int N = p.length;
        int[] pp = new int[N/2];
        for (int i=0; i<N/2; i++) pp[i] = (p[2*i] + 1)/2;
        return pp;
    }

    class State implements Comparable<State> {
        int[] p;
        int ops;

        public State(int[] p, int ops) {
            this.p = p;
            this.ops = ops;
        }

        public int compareTo(State other) {
            if (this.p.length != other.p.length) {
                return this.p.length - other.p.length;
            }
            int pos = 0;
            while (pos < p.length && p[pos] == other.p[pos]) pos++;
            if (pos < p.length) return p[pos] - other.p[pos];
            return ops - other.ops;
        }

        public boolean equals(Object other) {
            State otherState = (State)other;

            return Arrays.equals(p, otherState.p) && ops == otherState.ops;
        }
    }

    Map<State, Long> memo;

    long solve(int[] p, int ops) {
        State s = new State(p, ops);
        if (memo.containsKey(s)) {
            return memo.get(s);
        }

        if (p.length == 1) {
            return ops == 0 ? 1 : 0;
        }

        int N = p.length;

        boolean[] ok = new boolean[N/2];
        for (int i=0; i < N; i += 2) {
            ok[i/2] = (p[i] % 2 == 1 && p[i + 1] == p[i] + 1);
        }

        int nBad = 0;
        for (int i=0; i<N/2; i++) if (!ok[i]) nBad++;

        if (nBad > 2) {
            return 0;
        }

        if (nBad == 0) {
            long ans = solve(reduce(p), ops);
            memo.put(s, ans);
            return ans;
        }

        if (ops == 0) return 0;

        if (nBad == 1) {
            int a = 0;
            while (ok[a]) a++;

            int tmp = p[2*a]; p[2*a] = p[2*a+1]; p[2*a + 1] = tmp;

            long ans = ops * solve(reduce(p), ops-1);

            tmp = p[2*a]; p[2*a] = p[2*a+1]; p[2*a + 1] = tmp;

            memo.put(s, ans);
            return ans;
        }

        int a = 0;
        while (ok[a]) a++;
        int b = a+1;
        while (ok[b]) b++;

        long ans = 0;

        for (int i = 2*a; i < 2*a+2; i++) {
            for (int j = 2*b; j < 2*b+2; j++) {
                int tmp = p[i]; p[i] = p[j]; p[j] = tmp;

                if (p[2*a] % 2 == 1 && p[2*a+1] == p[2*a] + 1 &&
                    p[2*b] % 2 == 1 && p[2*b+1] == p[2*b] + 1) {
                    ans += ops * solve(reduce(p), ops-1);
                }

                tmp = p[i]; p[i] = p[j]; p[j] = tmp;
            }
        }

        memo.put(s, ans);
        return ans;
    }

    void solve(Scanner sc, PrintWriter pw) {
        memo = new TreeMap<State, Long>();

        int N = sc.nextInt();

        int[] p = new int[1<<N];

        for (int i=0; i<(1<<N); i++) {
            p[i] = sc.nextInt();
        }

        long ans = 0;

        for (int ops = 0; ops <= N; ops++) {
            ans += solve(p, ops);
        }

        pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new PowerSwapper().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
