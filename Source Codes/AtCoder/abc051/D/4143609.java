import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        final int INF = 1000000000;
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] costs = new int[n][n];
        for (int[] array : costs) {
            Arrays.fill(array, INF);
        }
        boolean[][] unUsedEdge = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();
            costs[a][b] = costs[b][a] = c;
            unUsedEdge[a][b] = unUsedEdge[b][a] = true;
        }

        for (int i = 0; i < n; i++) {
            Node curNode = new Node(i, 0);
            ;
            int[] distances = new int[n];
            Arrays.fill(distances, INF);
            distances[curNode.id] = 0;
            PriorityQueue<Node> nodeQueue = new PriorityQueue<>();
            nodeQueue.add(curNode);

            while (!nodeQueue.isEmpty()) {
                Node node = nodeQueue.poll();
                if (distances[node.id] < node.cost) {
                    continue;
                }

                for (int j = 0; j < n; j++) {
                    if (distances[j] > node.cost + costs[node.id][j]) {
                        distances[j] = node.cost + costs[node.id][j];
                        nodeQueue.add(new Node(j, distances[j]));
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (distances[j] == distances[k] + costs[j][k]) {
                        unUsedEdge[j][k] = unUsedEdge[k][j] = false;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (unUsedEdge[i][j]) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }

    static class Node implements Comparable<Node> {
        int id;
        int cost;

        Node(int id, int cost) {
            this.id = id;
            this.cost = cost;
        }

        public int compareTo(Node o) {
            if (this.cost == o.cost) {
                return 0;
            }

            if (this.cost > o.cost) {
                return 1;
            } else {
                return -1;
            }
        }

        @Override
        public String toString() {
            return "id " + this.id + "cost " + this.cost;
        }
    }
}