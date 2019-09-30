import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class D {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int P = in.nextInt();
        int W = in.nextInt();

        Node[] v = new Node[P];
        for (int i = 0; i < P; i++) {
            v[i] = new Node(i);
        }

        for (int i = 0; i < W; i++) {
            String[] s = in.next().split(",");
            int x = Integer.parseInt(s[0]);
            int y = Integer.parseInt(s[1]);
            v[x].addEdge(v[y]);
        }

        Node[] q = new Node[P];
        q[0] = v[0];
        v[0].visited = true;
        int h = 0;
        int t = 1;
        while (t > h) {
            Node node = q[h++];
            for (Edge edge : node.edges) {
                Node next = edge.dst;
                if (!next.visited) {
                    next.visited = true;
                    next.d = node.d + 1;
                    q[t++] = next;
                }
            }
        }
        mem = new int[P][P][P];
        for (int[][] ints : mem) {
            for (int[] anInt : ints) {
                Arrays.fill(anInt, -10);
            }
        }
        int maxTh = dfs(v[0], new Node(0), new Node(0), v[1]);
        return (v[1].d - 1) + " " + (mem[0][0][0] + 1);
    }

    int[][][] mem;
    boolean[] zzz = new boolean[1000];

    private int dfs(Node current, Node prev, Node prev2, Node target) {
        if (mem[current.id][prev.id][prev2.id] > -10) {
            return mem[current.id][prev.id][prev2.id];
        }
        if (current == target) {
            mem[current.id][prev.id][prev2.id] = 0;
        } else {

            Set<Node> newNodes = new HashSet<Node>();
            for (Edge edge : current.edges) {
                newNodes.add(edge.dst);
            }
            newNodes.remove(prev);
            for (Edge edge : prev.edges) {
                newNodes.remove(edge.dst);
            }
            newNodes.remove(prev2);
            for (Edge edge : prev2.edges) {
                newNodes.remove(edge.dst);
            }
            int sum = newNodes.size();
            int res = -5;
            for (Edge edge : current.edges) {
                if (edge.dst.d == current.d + 1) {
                    int x = dfs(edge.dst, current, prev, target);
                    if (x > -5) {
                        res = Math.max(res, sum + x - 1);
                    }
                }
            }
            mem[current.id][prev.id][prev2.id] = res;
        }
        return mem[current.id][prev.id][prev2.id];
    }


    class Node {

        int id;
        int d;
        boolean visited;

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

    class Edge {
        Node src;
        Node dst;
        Edge rev;
    }

}