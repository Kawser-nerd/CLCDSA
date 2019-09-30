package contest;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class CrimeHouse {
    final static String PROBLEM_NAME = "crime";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        char[] eventType = new char[N];
        int[] id = new int[N];
        int[] recode = new int[2001];
        int nextId = 0;
        Arrays.fill(recode, -1);

        for (int i=0; i<N; i++) {
            eventType[i] = sc.next().charAt(0);
            int who = sc.nextInt();
            if (who == 0) {
                id[i] = -1;
                continue;
            }
            if (recode[who] == -1) {
                recode[who] = nextId++;
            }
            id[i] = recode[who];
        }

        boolean[][] can = new boolean[N+1][1<<N];
        for (int mask=0; mask<(1<<N); mask++) {
            can[0][mask] = true;
        }

        for (int pos = 0; pos < N; pos++) {
            char e = eventType[pos];
            int who = id[pos];
            for (int mask=0; mask < (1<<N); mask++) {
                if (!can[pos][mask]) continue;
                if (e == 'E') {
                    for (int i=0; i<N; i++) {
                        if ((who == -1 || who == i) && (mask & (1<<i)) == 0) {
                            can[pos+1][mask ^ (1<<i)] = true;
                        }
                    }
                } else {
                    for (int i=0; i<N; i++) {
                        if ((who == -1 || who == i) && (mask & (1<<i)) != 0) {
                            can[pos+1][mask ^ (1<<i)] = true;
                        }
                    }
                }
            }
        }

        int ans = N+1;
        for (int mask=0; mask<(1<<N); mask++) if (can[N][mask]) ans = Math.min(ans, Integer.bitCount(mask));

        if (ans == N+1) pw.println("CRIME TIME"); else pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new CrimeHouse().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
