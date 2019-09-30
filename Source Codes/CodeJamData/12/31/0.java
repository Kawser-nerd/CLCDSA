package gcj;

import java.util.*;
import java.io.*;

public class Diamond {
    final static String PROBLEM_NAME = "diamond";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static void preprocess() {
    }

    int N;
    List<List<Integer>> edg;

    boolean flag;
    boolean[] visited;

    void dfs(int pos) {
        visited[pos] = true;
        for (int next : edg.get(pos)) {
            if (visited[next])
                flag = true;
            else
                dfs(next);
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        edg = new ArrayList<List<Integer>>();
        N = sc.nextInt();
        for (int i=0; i<N; i++) {
            int cnt = sc.nextInt();
            edg.add(new ArrayList<Integer>());
            for (int j=0; j<cnt; j++)
                edg.get(i).add(sc.nextInt() - 1);
        }
        visited = new boolean[N];
        flag = false;
        for (int i=0; i<N; i++) {
            Arrays.fill(visited, false);
            dfs(i);
        }
        pw.println(flag ? "Yes" : "No");
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Diamond().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
