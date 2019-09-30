import java.io.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ParadoxEasy {
    final static String PROBLEM_NAME = "paradox_easy";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int N, A;
    char[][] pref;
    boolean find;
    boolean[] used;
    int[] res;
    int[] p;

    void go(int pos) {
        if (pos == N) {
            int which = p[0];
            for (int i=1; i<N; i++)
                if (pref[p[i]][which] == 'Y') {
                    which = p[i];
                }
            if (which == A) {
                find = true;
                res = p.clone();
            }
            return;
        }
        for (p[pos]=0; p[pos]<N && !find; p[pos]++) {
            if (!used[p[pos]]) {
                used[p[pos]] = true;
                go(pos+1);
                used[p[pos]] = false;
            }
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        N = sc.nextInt();
        A = sc.nextInt();
        pref = new char[N][];
        for (int i=0; i<N; i++) {
            pref[i] = sc.next().toCharArray();
        }
        p = new int[N];
        used = new boolean[N];
        find = false;
        go(0);
        if (find) {
            for (int i=0; i<N; i++) {
                pw.print(" " + res[i]);
            }
            pw.println();
        } else {
            pw.println(" IMPOSSIBLE");
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ":");
            new ParadoxEasy().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
