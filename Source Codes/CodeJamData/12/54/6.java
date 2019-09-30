package gcj;

import java.util.*;
import java.io.*;

public class Lost {
    final static String PROBLEM_NAME = "lost";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    void solve(Scanner sc, PrintWriter pw) {
        int k = sc.nextInt();
        String s = sc.next();

        char[] eq = new char[256];
        eq['o'] = '0';
        eq['i'] = '1';
        eq['e'] = '3';
        eq['a'] = '4';
        eq['s'] = '5';
        eq['t'] = '7';
        eq['b'] = '8';
        eq['g'] = '9';

        int[] charId = new int[256];
        Arrays.fill(charId, -1);
        int charCnt = 0;
        for (int i=0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (charId[c] == -1) {
                charId[c] = charCnt++;
                if (eq[c] != 0)
                    charId[eq[c]] = charCnt++;
            }
        }

        if (k==1) {
            pw.println(charCnt);
            return;
        }

        int[][] edg = new int[charCnt][charCnt];
        for (int i=0; i+1 < s.length(); i++) {
            int a = charId[s.charAt(i)], b = charId[s.charAt(i+1)];
            int c = (eq[s.charAt(i)] == 0 ? -1 : charId[eq[s.charAt(i)]]);
            int d = (eq[s.charAt(i+1)] == 0 ? -1 : charId[eq[s.charAt(i+1)]]);

            edg[a][b] = 1;
            if (d!=-1) edg[a][d] = 1;
            if (c!=-1) edg[c][b] = 1;
            if (c!=-1 && d!=-1) edg[c][d] = 1;
        }

        int[] compId = new int[charCnt];
        Arrays.fill(compId, -1);

        boolean[][] can = new boolean[charCnt][charCnt];
        for (int i=0; i<charCnt; i++)
            for (int j=0; j<charCnt; j++)
                if (i==j || edg[i][j]==1 || edg[j][i]==1)
                    can[i][j] = true;

        for (int kk=0; kk<charCnt; kk++)
            for (int i=0; i<charCnt; i++)
                for (int j=0; j<charCnt; j++)
                    if (can[i][kk] && can[kk][j]) can[i][j] = true;

        int compCnt = 0;
        for (int i=0; i<charCnt; i++)
            if (compId[i] == -1) {
                for (int j=i; j<charCnt; j++)
                    if (can[i][j])
                        compId[j] = compCnt;
                compCnt++;
            }

        int edgCnt = 0;
        for (int i=0; i<charCnt; i++)
            for (int j=0; j<charCnt; j++)
                if (edg[i][j] == 1) edgCnt++;

        int[] inDeg = new int[charCnt];
        int[] outDeg = new int[charCnt];
        for (int i=0; i<charCnt; i++)
            for (int j=0; j<charCnt; j++)
                if (edg[i][j] ==1) {
                    outDeg[i]++;
                    inDeg[j]++;
                }

        int res = edgCnt+1;
        for (int c=0; c<compCnt; c++) {
            int diff = 0;
            for (int i=0; i<charCnt; i++)
                if (compId[i] == c && inDeg[i] <= outDeg[i]) diff += outDeg[i]-inDeg[i];
            if (diff > 1) {
                res += diff - 1;
            }
        }

        pw.println(res);
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Lost().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
