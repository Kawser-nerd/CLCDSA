import com.sun.imageio.plugins.common.PaletteBuilder;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    class Node {

        int id;
        public int color = -1;

        Node(int id) {
            this.id = id;
        }

        List<Edge> edges = new ArrayList<Edge>();

        void addEdge(Node dst) {
            Edge edge = new Edge();
            Edge rev = new Edge();
            edge.src = this;
            edge.dst = dst;
            edge.rev = rev;
            rev.src = dst;
            rev.dst = this;
            rev.rev = edge;
            edges.add(edge);
            dst.edges.add(rev);
        }
    }

    class Edge implements Comparable<Edge> {
        Node src;
        Node dst;
        Edge rev;

        Edge next;

        Figure figure;

        public int compareTo(Edge edge) {
            return dst.id - edge.dst.id;
        }
    }

    class Figure {

        boolean bad;

        List<Edge> edges = new ArrayList<Edge>();

        public boolean painted;
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        Node[] v = new Node[n];
        for (int i = 0; i < n; i++) {
            v[i] = new Node(i);
        }
        for (int i = 0; i < n - 1; i++) {
            v[i].addEdge(v[i + 1]);
        }
        v[0].addEdge(v[n - 1]);
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            y[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            v[x[i] - 1].addEdge(v[y[i] - 1]);
        }
        for (int i = 0; i < n; i++) {
            List<Edge> e = v[i].edges;
            Collections.sort(e);
            for (int j = 0; j < e.size() - 1; j++) {
                e.get(j).next = e.get(j + 1);
            }
            e.get(e.size() - 1).next = e.get(0);
        }

        List<Figure> figures = new ArrayList<Figure>();
        for (int i = 0; i < n; i++) {
            for (Edge edge : v[i].edges) {
                if (edge.figure == null) {
                    Figure figure = new Figure();
                    Edge cur = edge;
                    while (cur.figure == null) {
                        figure.edges.add(cur);
                        cur.figure = figure;
                        cur = cur.rev.next;
                    }
                    if (figure.edges.size() < n) {
                        figures.add(figure);
                    } else {
                        figure.bad = true;
                    }
                }
            }
        }

        size = n;
        for (Figure figure : figures) {
            size = Math.min(size, figure.edges.size());
        }
        paint(figures.get(0));

        StringBuilder res = new StringBuilder();
        res.append(size).append("\n");
        for (int i = 0; i < n; i++) {
            int c = v[i].color + 1;
            if (c > size) c = size;
            res.append(c).append(" ");
        }
        return res.toString();
    }

    int size;

    private void paint(Figure figure) {
        if (figure.painted) return;
        figure.painted = true;
        int n = figure.edges.size();
        boolean[] used = new boolean[size];
        for (int i = 0; i < n; i++) {
            Edge edge = figure.edges.get(i);
            int c = edge.src.color;
            if (c >= 0) {
                used[c] = true;
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            Edge edge = figure.edges.get(i);
            Edge next = figure.edges.get((i + 1) % n);
            Edge prev = figure.edges.get((i + n - 1) % n);
            Node node = edge.src;
            if (node.color == -1) {
                while (j < size && used[j]) j++;
                if (j == size) {
                    node.color = 0;
                    while (node.color == next.src.color || node.color == prev.src.color) node.color++;
                } else {
                    node.color = j;
                    j++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            Figure nb = figure.edges.get(i).rev.figure;
            if (!nb.bad) {
                paint(nb);
            }
        }
    }
}