import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  private static final long M = 1_000_000_007;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    Node[] nodes = new Node[N];
    for (int i = 0; i < N; i++) nodes[i] = new Node();
    for (int i = 0; i < N - 1; i++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      nodes[a].neighbors.add(nodes[b]);
      nodes[b].neighbors.add(nodes[a]);
    }

    long[] count = dfs(nodes[0]);
    System.out.println((count[0] + count[1]) % M);
  }

  private static long[] dfs(Node node) {
    node.visited = true;
    long[] count = new long[] {1, 1};
    for (Node n : node.neighbors) {
      if (!n.visited) {
        long[] c = dfs(n);
        count[0] *= (c[0] + c[1]) % M;
        count[0] %= M;
        count[1] *= c[0];
        count[1] %= M;
      }
    }
    return count;
  }

  private static class Node {
    final List<Node> neighbors = new ArrayList<>();
    boolean visited;
  }
}