package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class TrainCars {
    final static String PROBLEM_NAME = "TrainCars";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    final int MOD = 1000000007;

    void solve(Scanner sc, PrintWriter pw) {
        String[] only = new String[26];
        Arrays.fill(only, "");
        int[] cnt = new int[26];
        List<String> words = new ArrayList<String>();
        int n = sc.nextInt();
        for (int i=0; i<n; i++) {
            words.add(sc.next());
        }
        for (int i=0; i<words.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (words.get(i).matches(c + "*")) {
                    cnt[c - 'a']++;
                    only[c - 'a'] += words.get(i);
                    words.remove(i);
                    i--;
                    break;
                }
            }
        }
        for (int i=0; i<words.size(); i++) {
            char first = words.get(i).charAt(0);
            if (only[first - 'a'].length() > 0) {
                words.set(i, only[first - 'a'] + words.get(i));
                only[first - 'a'] = "";
            }
            char last = words.get(i).charAt(words.get(i).length() - 1);
            if (only[last - 'a'].length() > 0) {
                words.set(i, words.get(i) + only[last - 'a']);
                only[last - 'a'] = "";
            }
        }
        boolean upd = true;
        while (upd) {
            upd = false;
            for (int i=0; i<words.size() && !upd; i++) {
                for (int j=0; j<words.size() && !upd; j++)
                    if (i != j && words.get(i).charAt(words.get(i).length() - 1) == words.get(j).charAt(0)) {
                        char c = words.get(j).charAt(0);
                        words.add(words.get(i) + only[c - 'a'] + words.get(j));
                        only[c - 'a'] = "";
                        words.remove(Math.max(i,j));
                        words.remove(Math.min(i,j));
                        upd = true;
                    }
            }
        }
        for (int i=0; i<26; i++) if (only[i].length() > 0) words.add(only[i]);

        StringBuilder sb = new StringBuilder();
        for (String elm : words) sb.append(elm);
        String s = sb.toString();
        for (char c = 'a'; c <= 'z'; c++) {
            int min = s.length(), max = 0, tot = 0;
            for (int i=0; i<s.length(); i++) {
                if (s.charAt(i) == c) {
                    min = Math.min(min, i);
                    max = Math.max(max, i);
                    tot++;
                }
            }
            if (tot != max - min + 1 && tot != 0) {
                pw.println(0);
                return;
            }
        }


        long ans = 1;
        for (int i=0; i<26; i++) for (int j=1; j<=cnt[i]; j++) {
            ans = (ans * j) % MOD;
        }
        for (int j=1; j<=words.size(); j++) ans = (ans * j) % MOD;
        pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new TrainCars().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
