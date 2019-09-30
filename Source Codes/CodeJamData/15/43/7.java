import java.util.*;
import java.io.*;
import java.math.*;

public class Bilingual {
    final static String PROBLEM_NAME = "bilingual";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        sc.nextLine();
        String[][] words = new String[N][];
        for (int i=0; i<N; i++) {
            words[i] = sc.nextLine().split(" ");
        }

        Map<String, Integer> id = new HashMap<String, Integer>();
        int cnt = 0;
        int[][] w = new int[N][];

        for (int i=0; i<N; i++) {
            w[i] = new int[words[i].length];
            for (int j=0; j < words[i].length; j++) {
                if (!id.containsKey(words[i][j])) {
                    id.put(words[i][j], cnt++);
                }
                w[i][j] = id.get(words[i][j]);
            }
        }

        int ans = cnt;

        for (int mask=2; mask<(1<<N); mask += 4) {
            boolean[] english = new boolean[cnt];
            boolean[] french = new boolean[cnt];
            for (int i=0; i<N; i++) {
                if ((mask & (1<<i)) != 0) {
                    for (int j=0; j<w[i].length; j++) {
                        english[w[i][j]] = true;
                    }
                } else {
                    for (int j=0; j<words[i].length; j++) {
                        french[w[i][j]] = true;
                    }
                }
            }
            int tmp = 0;
            for (int i=0; i < cnt; i++) {
                if (english[i] && french[i]) {
                    tmp++;
                }
            }
            ans = Math.min(ans,tmp);
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
            new Bilingual().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
