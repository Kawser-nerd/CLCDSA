import java.util.*;
import java.math.*;

class Node implements Comparable<Node> {
  static ArrayList<ArrayList<Integer>> dest;
  static ArrayList<ArrayList<Boolean>> typeB;

  int index;
  int typeBCount;
  int cost;

  Node(int index, int typeBCount, int cost) {
    this.index = index;
    this.typeBCount = typeBCount;
    this.cost = cost;
  }

  public int compareTo(Node node) {
    return this.cost - node.cost;
  }

  public int hashCode() {
    return (index << 16) | typeBCount;
  }

  public boolean equals(Object object) {
    Node node = (Node)object;
    return this.index == node.index &&
        this.typeBCount == node.typeBCount;
  }

  public ArrayList<Node> getNextNode() {
    ArrayList<Node> output = new ArrayList<Node>();
    for (int i = 0; i < dest.get(index).size(); i++) {
      output.add(new Node(
          dest.get(index).get(i),
          typeBCount + (typeB.get(index).get(i) ? 1 : 0),
          cost + (typeB.get(index).get(i) ? typeBCount + 1 : 1)));
    }
    return output;
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int m = s.nextInt();
    Node.dest = new ArrayList<ArrayList<Integer>>();
    Node.typeB = new ArrayList<ArrayList<Boolean>>();
    for (int i = 0; i < n; i++) {
      Node.dest.add(new ArrayList<Integer>());
      Node.typeB.add(new ArrayList<Boolean>());
    }

    for (int i = 0; i < m; i++) {
      int c = s.nextInt();
      int a = s.nextInt();
      int b = s.nextInt();
      Node.dest.get(a).add(b);
      Node.dest.get(b).add(a);
      Node.typeB.get(a).add(c == 1);
      Node.typeB.get(b).add(c == 1);
    }

    int[] cost = new int[n];
    int[] typeBCount = new int[n];
    Arrays.fill(cost, Integer.MAX_VALUE);
    Arrays.fill(typeBCount, Integer.MAX_VALUE);
    HashSet<Node> visited = new HashSet<Node>();
    PriorityQueue<Node> queue = new PriorityQueue<Node>();
    queue.add(new Node(0, 0, 0));
    while(!queue.isEmpty()) {
      Node node = queue.poll();
      if (visited.contains(node)) {
        continue;
      }
      if (typeBCount[node.index] < node.typeBCount) {
        continue;
      }
      cost[node.index] = Math.min(cost[node.index], node.cost);
      typeBCount[node.index] = node.typeBCount;
      visited.add(node);
      for (Node next : node.getNextNode()) {
        if (visited.contains(next)) {
          continue;
        }
        queue.add(next);
      }
    }
    for (int c : cost) {
      System.out.println(c);
    }
  }
}