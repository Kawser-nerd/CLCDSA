import java.util.*;

public class Main {
  static ArrayList<Edge>[] graph;
  static int vNum;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    vNum = sc.nextInt();
    Vertice[] V = new Vertice[vNum];
    graph = new ArrayList[vNum];
    for(int i = 0; i < vNum; i++) {
      graph[i] = new ArrayList<Edge>();
    }
    for(int i = 0; i < vNum; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      V[i] = new Vertice(i, x, y);
    }
    Arrays.sort(V, new Comparator<Vertice>() {
      public int compare(Vertice vertice1, Vertice vertice2) {
	return vertice1.x - vertice2.x;
      }
    });
    for(int i = 0; i < vNum - 1; i++) {
      Vertice v1 = V[i];
      Vertice v2 = V[i + 1];
      graph[v1.id].add(new Edge(v2.id, v2.x - v1.x));
      graph[v2.id].add(new Edge(v1.id, v2.x - v1.x));
    }

    Arrays.sort(V, new Comparator<Vertice>() {
      public int compare(Vertice vertice1, Vertice vertice2) {
	return vertice1.y - vertice2.y;
      }
    });
    for(int i = 0; i < vNum - 1; i++) {
      Vertice v1 = V[i];
      Vertice v2 = V[i + 1];
      graph[v1.id].add(new Edge(v2.id, v2.y - v1.y));
      graph[v2.id].add(new Edge(v1.id, v2.y - v1.y));
    }
    int ans = prim();
    System.out.println(ans);
  }

  public static int prim() {
    int total = 0;
    Queue<Edge> que = new PriorityQueue<Edge>();
    que.add(new Edge(0,0));
    boolean[] use = new boolean[vNum];
    while(!que.isEmpty()) {
      Edge e = que.poll();
      if(use[e.to]) {
        continue;
      }
      use[e.to] = true;
      total += e.cost;
      for(Edge e2 : graph[e.to]) {
        que.add(e2);
      }
    }
    return total;
  }

  static class Edge implements Comparable<Edge> {
    int to;
    int cost;

    public Edge(int to, int cost) {
      this.to = to;
      this.cost = cost;
    }
    @Override
    public int compareTo(Edge o) {
      return this.cost - o.cost;
    }
  }

  static class Vertice {
    int id;
    int x;
    int y;

    public Vertice(int id, int x, int y) {
      this.id = id;
      this.x = x;
      this.y = y;
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.