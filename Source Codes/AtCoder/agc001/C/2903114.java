import java.util.*;

public class Main {
    private static final int INF = 114514;

    private class Road {
        int src, dst, cost;

        public Road(int src, int dst, int cost) {
            this.src = src;
            this.dst = dst;
            this.cost = cost;
        }
    }

    private class Node {
        int cost = INF;
        boolean fix = false;
        List<Road> child = new ArrayList<>();
    }

    public void main(Scanner sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        Node nodes[] = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            nodes[a].child.add(new Road(a, b, 1));
            nodes[b].child.add(new Road(b, a, 1));
        }

        int cost[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nodes[j].cost = INF;
                nodes[j].fix = false;
            }
            cost[i] = dij(i, n, nodes);
        }

        int ans = 0;
        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (cost[i][j] <= k / 2) {
                        cnt++;
                    }
                }
                ans = Math.max(ans, cnt);
            }
        } else {
            BitSet bset1 = new BitSet();
            BitSet bset2 = new BitSet();

            for (int i = 0; i < n; i++) {
                bset1 = new BitSet();
                for (int j = 0; j < n; j++) {
                    if (cost[i][j] <= k / 2) {
                        bset1.set(j);
                    }
                }

                for (Road road : nodes[i].child) {
                    bset2 = new BitSet();
                    int dst = road.dst;
                    for (int j = 0; j < n; j++) {
                        if (cost[dst][j] <= k / 2) {
                            bset2.set(j);
                        }
                    }

                    bset2.or(bset1);
                    ans = Math.max(ans, bset2.cardinality());
                }
            }
        }
        System.out.println(n - ans);
    }

    private int[] dij(int start, int n, Node nodes[]) {
        nodes[start].cost = 0;
        Queue<Node> queue = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
        queue.add(nodes[start]);

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            node.fix = true;
            for (Road road : node.child) {
                if (!nodes[road.dst].fix) {
                    nodes[road.dst].cost = Math.min(nodes[road.dst].cost, node.cost + road.cost);
                    queue.add(nodes[road.dst]);
                }
            }
        }

        int costs[] = new int[n];
        for (int i = 0; i < n; i++) {
            costs[i] = nodes[i].cost;
        }
        return costs;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}