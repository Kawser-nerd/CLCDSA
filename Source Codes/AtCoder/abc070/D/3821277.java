import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    Node[] nodes = new Node[N];
    for (int i = 0; i < N; i++) nodes[i] = new Node(i);
    for (int i = 0; i < N - 1; i++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      int c = scanner.nextInt();

      nodes[a].edges.add(new Edge(nodes[b], c));
      nodes[b].edges.add(new Edge(nodes[a], c));
    }

    int Q = scanner.nextInt();
    int K = scanner.nextInt() - 1;
    dfs(nodes[K], 0);
    for (int i = 0; i < Q; i++) {
      int x = scanner.nextInt() - 1;
      int y = scanner.nextInt() - 1;
      System.out.println(nodes[x].depth + nodes[y].depth);
    }
  }

  private static void dfs(Node n, long depth) {
    n.depth = depth;
    n.visited = true;
    for (Edge e : n.edges) {
      if (!e.to.visited) dfs(e.to, depth + e.dist);
    }
  }

  static class Node {
    final int id;
    boolean visited;
    List<Edge> edges = new ArrayList<>();
    long depth = 0;

    Node(int id) {
      this.id = id;
    }
  }

  static class Edge {
    final Node to;
    final int dist;

    Edge(Node to, int dist) {
      this.to = to;
      this.dist = dist;
    }
  }
}