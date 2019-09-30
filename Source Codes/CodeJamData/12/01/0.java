package gcj;

import java.util.*;
import java.io.*;

public class SpeakingInTongues {
    final static String PROBLEM_NAME = "tongues";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static char[] p = new char[26];

    static void preprocess() {
        String[] inp = new String[]{
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv"
        };
        String[] out = new String[]{
                "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up"
        };

        Arrays.fill(p, '?');
        for (int i = 0; i < inp.length; i++) {
            for (int j = 0; j < inp[i].length(); j++) {
                if (inp[i].charAt(j) != ' ') {
                    p[inp[i].charAt(j) - 'a'] = out[i].charAt(j);
                }
            }
        }

        for (int i = 0; i < 26; i++)
            System.out.println((char) ((int) 'a' + i) + " -> " + p[i]);

        p['q' - 'a'] = 'z';
        p['z' - 'a'] = 'q';
    }

    void solve(Scanner sc, PrintWriter pw) {
        String s = sc.nextLine();
        for (char c : s.toCharArray()) {
            if (c == ' ') {
                pw.print(c);
            } else {
                pw.print(p[c - 'a']);
            }
        }
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        sc.nextLine();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new SpeakingInTongues().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
