
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class AreWeLostYet implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new AreWeLostYet(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/C-small.in"));
            out = new PrintWriter("src/C-small.out");
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    // solution
    void solve() throws IOException {
        int testcase = readInt();;
        for (int i = 1; i <= testcase; i++) {
            solveTestCase(i);
        }
    }

    void solveTestCase(int testcase) throws IOException {
        int n = readInt();
        int m = readInt();
        int p = readInt();
        first = new Edge[n];
        for (int i = 1; i <= m; i++) {
            int a = readInt() - 1;
            int b = readInt() - 1;
            int minCost = readInt();
            int maxCost = readInt();
            first[a] = new Edge(i, a, b, minCost, maxCost, first[a]);
            getById.put(i, first[a]);
        }
        int[] nextMovement = new int[p];
        for (int i = 0; i < p; i++) {
            nextMovement[i] = readInt();
        }
        int current = 0;
        int cost = 0;
        for (int edgeInt : nextMovement) {
            Edge edge = getById.get(edgeInt);
            cost += edge.minCost;
            current = edge.b;
            usedEdges.add(edgeInt);
            if (!stillMayhapsOptimal(current, cost)) {
                out.println("Case #" + testcase + ": " + edgeInt);
                return;
            }
        }
        out.println("Case #" + testcase + ": Looks Good To Me");
    }
    Edge[] first;
    HashMap<Integer, Edge> getById = new HashMap<>();
    HashSet<Integer> usedEdges = new HashSet<>();

    private boolean stillMayhapsOptimal(int x, int cost) {
        boolean[] enemy = new boolean[first.length];
        boolean[] visited = new boolean[first.length];
        int[] minDistance = new int[first.length];
        enemy[0] = true;
        Arrays.fill(minDistance, Integer.MAX_VALUE / 2);
        minDistance[0] = 0;
        minDistance[x] = cost;
        PriorityQueue<Point> queue = new PriorityQueue<Point>();
        queue.add(new Point(0, 0));
        queue.add(new Point(x, cost));
       // System.out.println("add " + x + " " + cost);
        while (!queue.isEmpty()) {
         //   System.out.println("visit " + queue.peek().x + " by " + enemy[queue.peek().x] + " " + queue.peek().y);
            Point p = queue.poll();
            if (p.x == 1) { //=2 in 1-based system, finish node
                return !enemy[p.x];
            }
            if (visited[p.x]) {
                continue;
            }
            visited[p.x] = true;
            for (Edge edge = first[p.x]; edge != null; edge = edge.next) {
                if (!visited[edge.b]) {
                    int newCost = p.y;
                    if (!enemy[p.x]) {
                        newCost += edge.minCost;
                    } else if (usedEdges.contains(edge.id)) {
                        newCost += edge.minCost;
                    } else {
                        newCost += edge.maxCost;
                    }
                  //  out.println("edge " + edge.a + " " + edge.b + " " + edge.minCost + " " + edge.maxCost);
                    if (minDistance[edge.b] > newCost || (minDistance[edge.b] == newCost && !enemy[p.x])) {
                        queue.add(new Point(edge.b, newCost));
                        minDistance[edge.b] = newCost;
                        enemy[edge.b] = enemy[edge.a];
                    }
                }
            }
        }
        throw new RuntimeException("AAAA WHY IS THIS HAPPENING");
    }

    class Point implements Comparable<Point> {

        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            return this.y - o.y;
        }
    }

    class Edge {

        int id;
        int a;
        int b;
        int minCost;
        int maxCost;
        Edge next;

        Edge(int id, int a, int b, int minCost, int maxCost, Edge next) {
            this.a = a;
            this.b = b;
            this.minCost = minCost;
            this.maxCost = maxCost;
            this.next = next;
        }
    }
}