import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int T = scanner.nextInt();
    long[] a = new long[N];
    for (int i = 0; i < N; i++) a[i] = scanner.nextInt();

    int[][] edges = new int[M][2];
    int[] costs = new int[M];
    for (int i = 0; i < M; i++) {
      edges[i][0] = scanner.nextInt() - 1;
      edges[i][1] = scanner.nextInt() - 1;
      costs[i] = scanner.nextInt();
    }
    long[] dist1 = shortest_sparse1(N, M, edges, costs, 0);
    long[] dist2 = shortest_sparse2(N, M, edges, costs, 0);

    long max = 0;
    for (int i = 0; i < N; i++) {
      max = Math.max(max, (T - dist1[i] - dist2[i]) * a[i]);
    }
    System.out.println(max);
  }

  private static final long INF = 100_000_000_000L;

  public static long[] shortest_sparse1(int V, int E, int[][] edges, int[] costs, int s) {
    List<Edge>[] graph = new List[V];
    for (int i = 0; i < V; i++) graph[i] = new LinkedList<>();
    for (int i = 0; i < E; i++) {
      int from = edges[i][0];
      int to = edges[i][1];
      int cost = costs[i];
      graph[from].add(new Edge(from, to, cost));
    }

    long[] dist = new long[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[s] = 0;

    PriorityQueue<Node> toVisit = new PriorityQueue<>(Comparator.comparingLong(o -> o.dist));
    toVisit.add(new Node(s, 0));

    while (!toVisit.isEmpty()) {
      Node n = toVisit.remove();
      for(Edge e : graph[n.number]) {
        int i = e.to;
        int cost = e.cost;
        long newValue = dist[e.from] + cost;
        if (dist[i] > newValue) {
          dist[i] = newValue;
          toVisit.add(new Node(i, newValue));
        }
      }
    }

    return dist;
  }

  public static long[] shortest_sparse2(int V, int E, int[][] edges, int[] costs, int t) {
    List<Edge>[] graph = new List[V];
    for (int i = 0; i < V; i++) graph[i] = new LinkedList<>();
    for (int i = 0; i < E; i++) {
      int from = edges[i][0];
      int to = edges[i][1];
      int cost = costs[i];
      graph[to].add(new Edge(from, to, cost));
    }

    long[] dist = new long[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[t] = 0;

    PriorityQueue<Node> toVisit = new PriorityQueue<>(Comparator.comparingLong(o -> o.dist));
    toVisit.add(new Node(t, 0));

    while (!toVisit.isEmpty()) {
      Node n = toVisit.remove();
      for(Edge e : graph[n.number]) {
        int i = e.from;
        int cost = e.cost;
        long newValue = dist[e.to] + cost;
        if (dist[i] > newValue) {
          dist[i] = newValue;
          toVisit.add(new Node(i, newValue));
        }
      }
    }

    return dist;
  }

  private static class Edge {
    public final int from;
    public final int to;
    public final int cost;

    private Edge(int from, int to, int cost) {
      this.from = from;
      this.to = to;
      this.cost = cost;
    }
  }

  private static class Node {
    public int number;
    public long dist;

    public Node(int number, long dist) {
      this.number = number;
      this.dist = dist;
    }

    @Override public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;
      Node node = (Node) o;
      return number == node.number;
    }

    @Override public int hashCode() {
      return number;
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.