// with -Xss1024M
import java.util.*;
import java.io.*;
import java.math.*;

public class Fairland {
    final static String PROBLEM_NAME = "fairland";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    class Guy implements Comparable<Guy> {
        int id;
        int salary;
        public Guy(int id, int salary) {
            this.id = id;
            this.salary = salary;
        }
        public int compareTo(Guy other) {
            return this.salary - other.salary;
        }
    }

    class Edge {
        int from, to;
        Edge next;

        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    int[] p;
    int[] S;
    Edge[] adj;

    boolean[] inTree;
    int inTreeCnt = 0;
    int minSalary, maxSalary;

    void reduce(int v) {
        if (!inTree[v]) {
            return;
        }
        inTree[v] = false;
        inTreeCnt--;

        Edge e = adj[v];
        while (e != null) {
            reduce(e.to);
            e = e.next;
        }
    }

    void increase(int v) {
        if (!inTree[p[v]] || inTree[v]) {
            return;
        }
        if (S[v] < minSalary || S[v] > maxSalary) {
            return;
        }
        inTree[v] = true;
        inTreeCnt++;

        Edge e = adj[v];
        while (e != null) {
            increase(e.to);
            e = e.next;
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int D = sc.nextInt();
        int S0 = sc.nextInt();
        int As = sc.nextInt();
        int Cs = sc.nextInt();
        int Rs = sc.nextInt();

        int M0 = sc.nextInt();
        int Am = sc.nextInt();
        int Cm = sc.nextInt();
        int Rm = sc.nextInt();

        S = new int[N];
        int[] M = new int[N];
        S[0] = S0;
        M[0] = M0;
        for (int i=1; i<N; i++) {
            S[i] = (S[i - 1] * As + Cs) % Rs;
            M[i] = (M[i - 1] * Am + Cm) % Rm;
        }

        adj = new Edge[N];
        Guy[] guys = new Guy[N];
        p = new int[N];
        for (int i=0; i<N; i++) {
            guys[i] = new Guy(i, S[i]);
            if (i > 0) {
                p[i] = M[i] % i;
                Edge e = new Edge(M[i] % i, i);
                e.next = adj[e.from];
                adj[e.from] = e;
            }
        }

        Arrays.sort(guys);

        int rootPos = -1;
        for (int i = 0; i < N; i++) {
            if (guys[i].id == 0) {
                rootPos = i;
                break;
            }
        }

        int L = rootPos, R = rootPos;
        while (L > 0 && guys[R].salary - guys[L - 1].salary <= D) {
            L--;
        }

        minSalary = guys[L].salary;
        maxSalary = guys[R].salary;

        inTree = new boolean[N];

        inTree[0] = true;
        inTreeCnt++;
        for (int i = R-1; i>=L; i--) {
            increase(guys[i].id);
        }

        int ans = inTreeCnt;

        while (true) {
            if (R + 1 < guys.length && guys[R + 1].salary - guys[L].salary <= D) {
                R++;
                maxSalary = guys[R].salary;
                increase(guys[R].id);
                if (inTreeCnt > N) {
                    System.out.println("WTF");
                }
                ans = Math.max(ans, inTreeCnt);
            } else {
                reduce(guys[L].id);
                L++;
                if (L > rootPos) {
                    break;
                }
                minSalary = guys[L].salary;
            }
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
            new Fairland().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
