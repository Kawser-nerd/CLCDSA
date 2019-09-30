import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static final int INF = Integer.MAX_VALUE;
  static Node[] nodes;

  public static void main(String[] args) {
    boolean result = solve();
    if (result) {
      System.out.println("Yes");
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < nodes.length; i++) {
        sb.append(nodes[i].v + "\n");
      }
      System.out.print(sb);
    } else {
      System.out.println("No");
    }
  }

  static boolean solve() {
    int N = sc.nextInt();
    nodes = new Node[N];
    for (int i = 0; i < N; i++) {
      nodes[i] = new Node(i);
    }
    for (int i = 0; i < N - 1; i++) {
      int A = Integer.parseInt(sc.next()) - 1;
      int B = Integer.parseInt(sc.next()) - 1;
      nodes[A].next.add(nodes[B]);
      nodes[B].next.add(nodes[A]);
    }
    int K = sc.nextInt();
    for (int i = 0; i < K; i++) {
      int V = Integer.parseInt(sc.next()) - 1;
      int P = Integer.parseInt(sc.next());
      nodes[V].v = nodes[V].min = nodes[V].max = P;
    }
    Node[] order = new Node[N];
    order[0] = nodes[0];
    nodes[0].parent = -1;
    for (int i = 0, pos = 1; i < N; i++) {
      for (Node c : order[i].next) {
        if (c.parent != INF) continue;
        c.parent = order[i].id;
        c.depth = order[i].depth + 1;
        order[pos++] = c;
      }
    }
    int parity = -1;
    for (int i = 0; i < N; i++) {
      if (order[i].v == INF) continue;
      int p = (order[i].v ^ order[i].depth) & 1;
      if (parity == -1) {
        parity = p;
      } else if (parity != p) {
        return false;
      }
    }
    for (int i = N - 1; i >= 0; i--) {
      for (Node c : order[i].next) {
        if (c.id == order[i].parent) continue;
        order[i].min = Math.max(order[i].min, c.min - 1);
        order[i].max = Math.min(order[i].max, c.max + 1);
      }
      if (order[i].min > order[i].max) return false;
    }
    for (int i = 1; i < N; i++) {
      order[i].min = Math.max(order[i].min, nodes[order[i].parent].min - 1);
      order[i].max = Math.min(order[i].max, nodes[order[i].parent].max + 1);
      if (order[i].min > order[i].max) return false;
    }
    order[0].v = order[0].min;
    for (int i = 1; i < N; i++) {
      int pv = nodes[order[i].parent].v;
      if (order[i].min <= pv - 1 && pv - 1 <= order[i].max) {
        order[i].v = pv - 1;
      } else {
        order[i].v = pv + 1;
      }
    }
    return true;
  }


  static class Node {
    int id, depth, parent = INF, v = INF, min = -INF / 2, max = INF / 2;
    ArrayList<Node> next = new ArrayList<>();

    public Node(int id) {
      this.id = id;
    }
  }
}