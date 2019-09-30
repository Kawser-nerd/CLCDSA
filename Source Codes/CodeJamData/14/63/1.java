import java.io.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class SymmetricTrees {
    final static String PROBLEM_NAME = "symmetric";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    class Edge {
        int from, to;
        String subtree;
        Edge next;
        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    int N;
    char[] color;
    Edge[] adj;

    public void addEdge(int x, int y) {
        Edge e = new Edge(x, y);
        e.next = adj[x];
        adj[x] = e;
    }

    String getSubtree(Edge e) {
        if (e.subtree != null) {
            return e.subtree;
        }

        Edge ee = adj[e.to];
        List<String> subtrees = new ArrayList<String>();
        while (ee != null) {
            if (ee.to != e.from) {
                subtrees.add(getSubtree(ee));
            }
            ee = ee.next;
        }

        Collections.sort(subtrees);

        StringBuilder sb = new StringBuilder();
        sb.append(color[e.to]);
        for (String s : subtrees) {
            sb.append("0");
            sb.append(s);
            sb.append("1");
        }

        e.subtree = sb.toString();
        return e.subtree;
    }

    boolean can(int x, int y) {
        List<String> sx = new ArrayList<String>();
        List<String> sy = new ArrayList<String>();

        Edge e = adj[x];
        while (e != null) {
            if (e.to != y) {
                sx.add(getSubtree(e));
            }
            e = e.next;
        }

        e = adj[y];
        while (e != null) {
            if (e.to != x) {
                sy.add(getSubtree(e));
            }
            e = e.next;
        }

        Collections.sort(sx);
        Collections.sort(sy);

        if (sx.size() != sy.size()) {
            return false;
        }

        for (int i=0; i<sx.size(); i++) {
            if (!sx.get(i).equals(sy.get(i))) {
                return false;
            }
        }

        return true;
    }

    boolean can(int v, Edge prev) {
        Edge e = adj[v];

        List<String> subs = new ArrayList<String>();

        while (e != null) {
            if (prev == null || e.to != prev.from) subs.add(getSubtree((e)));
            e = e.next;
        }

        Collections.sort(subs);

        int bad = -1;

        int cur = 0;
        while (cur < subs.size()) {
            if (cur == subs.size() - 1 || !subs.get(cur).equals(subs.get(cur+1))) {
                if (bad != -1) {
                    return false;
                }
                bad = cur;
                cur++;
                continue;
            }
            cur += 2;
        }

        if (bad == -1) {
            return true;
        }

        e = adj[v];
        while (e != null) {
            if (prev == null || e.to != prev.from) {
                if (getSubtree(e).equals(subs.get(bad))) {
                    return can(e.to, e);
                }
            }
            e = e.next;
        }

        System.out.println("!?!");
        return false;
    }

    void solve(Scanner sc, PrintWriter pw) {
        N = sc.nextInt();
        color = new char[N];
        for (int i=0; i<N; i++) {
            color[i] = sc.next().charAt(0);
        }
        adj = new Edge[N];
        for (int i=0; i<N-1; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            addEdge(x, y);
            addEdge(y, x);
        }

        for (int i=0; i<N; i++)
            if (can(i, null)) {
                pw.println("SYMMETRIC");
                return;
            }

        for (int i=0; i<N; i++) {
            Edge e = adj[i];
            while (e != null) {
                if (can(i, e.to)) {
                    pw.println("SYMMETRIC");
                    return;
                }
                e = e.next;
            }
        }

        pw.println("NOT SYMMETRIC");
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new SymmetricTrees().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
