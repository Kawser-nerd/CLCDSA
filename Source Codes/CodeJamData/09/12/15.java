import java.io.File;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class b {
    public static void main(String[] args) throws Exception {
        String fname = "b.in";
        if (args.length > 0)
            fname = args[0];
        Scanner sc = new Scanner(new File(fname));
        int T = sc.nextInt();
        sc.nextLine();
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #" + i + ": ");
            System.out.println(new b().go(sc));
        }

    }

    private long delayUntilICanGo(boolean vertical, int row, int col, long time) {
        long timeSinceFirstCycleStarted = time - t[row][col];
        if (timeSinceFirstCycleStarted < 0) {
            long cycles = timeSinceFirstCycleStarted
                    / totalCycleLength[row][col];
            timeSinceFirstCycleStarted += (-cycles + 1)
                    * totalCycleLength[row][col];
        }
        long timeIntoCycle = timeSinceFirstCycleStarted
                % totalCycleLength[row][col];
        if (timeIntoCycle < s[row][col]) {
            // south is activated
            if (vertical)
                return 0;
            else
                return s[row][col] - timeIntoCycle;
        } else {
            // west is activated
            if (!vertical)
                return 0;
            else
                return totalCycleLength[row][col] - timeIntoCycle;
        }
    }

    long[][] s, w, t, totalCycleLength;

    private long go(Scanner sc) throws Exception {
        int n = sc.nextInt(); // rows
        int m = sc.nextInt(); // cols

        s = new long[n][m];
        w = new long[n][m];
        t = new long[n][m];
        totalCycleLength = new long[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s[i][j] = sc.nextInt();
                w[i][j] = sc.nextInt();
                t[i][j] = sc.nextInt();
                totalCycleLength[i][j] = s[i][j] + w[i][j];
            }
        }

        // make nodes array
        Node[][] nodes = new Node[2 * n][2 * m];
        for (int i = 0; i < nodes.length; i++)
            for (int j = 0; j < nodes[0].length; j++) {
                nodes[i][j] = new Node(i / 2, j / 2, i % 2 != 0, j % 2 == 0);
            }

        // establish edges
        for (int i = 0; i < nodes.length; i++)
            for (int j = 0; j < nodes[0].length; j++) {
                for (int x = 0; x < 4; x++) {
                    int ti = i + di[x];
                    int tj = j + dj[x];
                    if (ti >= 0 && tj >= 0 && ti < nodes.length
                            && tj < nodes[0].length) {
                        nodes[i][j].neighbors.put(x, nodes[ti][tj]);
                    }
                }
            }
        // goal node
        nodes[0][nodes[0].length - 1].terminal = true;

        PriorityQueue<State> q = new PriorityQueue<State>();
        Map<Node, Long> fastest = new HashMap<Node, Long>();
        q.add(new State(0, nodes[nodes.length - 1][0]));

        while (true) {
            State state = q.remove();
//            System.err.println(state.path);
            if (state.isTerminal())
                return state.cost;
            else {
                for (State suc : state.getSuccessors()) {
                    if (fastest.containsKey(suc.node)
                            && fastest.get(suc.node) <= suc.cost) {
                    } else {
                        fastest.put(suc.node, suc.cost);
                        q.add(suc);
                    }
                }
            }
        }

    }

    class State implements Comparable<State> {
        long cost;
        Node node;
//        String path;

        public String toString() {
            return node + ": " + cost;
        }

        public int hashcode() {
            return (int) cost ^ node.hashCode();
        }

        public boolean equals(Object o) {
            State s = (State) o;
            return cost == s.cost && node == s.node;
        }

        public int compareTo(State o) {
            if (cost < o.cost)
                return -1;
            else if (cost > o.cost)
                return 1;
            else
                return 0;
        }

        boolean isTerminal() {

            return node.terminal;
        }

        public State(long cost, Node node) {
            this.cost = cost;
            this.node = node;
  //          path = toString();
        }

        public Set<State> getSuccessors() {
            Set<State> res = new HashSet<State>();
            for (Integer direction : node.neighbors.keySet()) {
                Node neighbor = node.neighbors.get(direction);
                State succ;
                if (!neighbor.sameIntersection(node))
                    succ = new State(cost + 2, neighbor);
                else
                    succ = new State(cost
                            + 1
                            + delayUntilICanGo(v[direction], node.row,
                                    node.col, cost), neighbor);
//                succ.path = path + " - " + succ.path;
                res.add(succ);

            }
            return res;
        }

    }

    class Node {
        public String toString() {
            return String.format("(%d, %d), %s %s", row, col, lower ? "lower"
                    : "upper", left ? "left" : "right");
        }

        boolean lower, left;
        int row, col;
        boolean terminal = false;
        Map<Integer, Node> neighbors = new HashMap<Integer, Node>();

        boolean sameIntersection(Node other) {
            return row == other.row && col == other.col;
        }

        public Node(int r, int c, boolean low, boolean lef) {
            row = r;
            col = c;
            lower = low;
            left = lef;
        }
    }

    int[] di = new int[] {
            1, 0, -1, 0
    };
    int[] dj = new int[] {
            0, 1, 0, -1
    };
    boolean[] v = new boolean[] {
            true, false, true, false
    };

}
