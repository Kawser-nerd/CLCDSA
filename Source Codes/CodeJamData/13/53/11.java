
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C {

    public static final int INF = 1000000000;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();
        Node[] v = new Node[n];
        for (int i = 0; i < n; i++) {
            v[i] = new Node(i);
        }
        Edge[] e = new Edge[m];
        for (int i = 0; i < m; i++) {
            int src = in.nextInt();
            int dst = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();
            e[i] = new Edge(i, l, r, v[src - 1], v[dst - 1]);
            v[dst - 1].in.add(e[i]);
        }
        Edge[] path = new Edge[p];
        for (int i = 0; i < p; i++) {
            path[i] = e[in.nextInt() - 1];
        }
        int res = -1;
        for (int mm = 0; mm < (1 << m); mm++) {
            for (int i = 0; i < m; i++) {
                if (((mm >> i) & 1) == 1) {
                    e[i].c = e[i].l;
                } else {
                    e[i].c = e[i].r;
                }
            }
            int[] d = new int[n];
            boolean[] z = new boolean[n];
            Arrays.fill(d, INF);
            d[1] = 0;
            for (int i = 0; i < n; i++) {
                int k = -1;
                for (int j = 0; j < n; j++) {
                    if (!z[j] && (k == -1 || d[j] < d[k])) {
                        k = j;
                    }
                }
                z[k] = true;
                for (Edge edge : v[k].in) {
                    int j = edge.src.id;
                    d[j] = Math.min(d[j], d[k] + edge.c);
                }
            }
            for (int i = 0; i < path.length; i++) {
                Edge edge = path[i];
                if (d[edge.dst.id] == d[edge.src.id] - edge.c) {
                    res = Math.max(res, i);
                } else {
                    break;
                }
            }
        }

//        System.out.println(res);

        return res == path.length - 1 ? "Looks Good To Me" : "" + (path[res + 1].id + 1);
    }

    class Node {
        int id;
        List<Edge> in = new ArrayList<Edge>();

        Node(int id) {
            this.id = id;
        }
    }

    class Edge {
        int id;
        int l;
        int r;
        int c;

        Node src;
        Node dst;

        Edge(int id, int l, int r, Node src, Node dst) {
            this.id = id;
            this.l = l;
            this.r = r;
            this.src = src;
            this.dst = dst;
        }
    }
}