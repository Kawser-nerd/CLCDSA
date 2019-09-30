import java.util.*;

class Vertex {
  long d;
  int n;
  public Vertex(long d, int n) {
    this.d = d;
    this.n = n;
  }
}

class Edge {
  int t;
  long c;
  public Edge(int t, long c) {
    this.t = t;
    this.c = c;
  }
}

class MyComparator implements Comparator {
  public int compare(Object obj1, Object obj2) {
    Vertex v1 = (Vertex)obj1;
    Vertex v2 = (Vertex)obj2;
    if(v1.d > v2.d) {
      return 1;
    } else if(v1.d < v2.d) {
      return -1;
    } else {
      return 0;
    }
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    long T = sc.nextLong();
    long[] A = new long[N];
    for(int i = 0; i < N; i++) {
      A[i] = sc.nextLong();
    }
    ArrayList[] road1 = new ArrayList[N];
    ArrayList[] road2 = new ArrayList[N];
    for(int i = 0; i < N; i++) {
      road1[i] = new ArrayList<Edge>();
      road2[i] = new ArrayList<Edge>();
    }
    for(int i = 0; i < M; i++) {
      int a = sc.nextInt() - 1;
      int b = sc.nextInt() - 1;
      long c = sc.nextLong();
      road1[a].add(new Edge(b, c));
      road2[b].add(new Edge(a, c));
    }
    long[] dist1 = new long[N];
    long[] dist2 = new long[N];
    for(int i = 1; i < N; i++) {
      dist1[i] = (long)Math.pow(10, 12);
      dist2[i] = (long)Math.pow(10, 12);
    }
    PriorityQueue<Vertex> que1 = new PriorityQueue<Vertex>(N, new MyComparator());
    PriorityQueue<Vertex> que2 = new PriorityQueue<Vertex>(N, new MyComparator());
    for(int i = 0; i < N; i++) {
      que1.add(new Vertex(dist1[i], i));
      que2.add(new Vertex(dist2[i], i));
    }
    // ??????
    while(que1.size() > 0) {
      Vertex v = que1.poll();
      ArrayList<Edge> eList = road1[v.n];
      for(int i = 0; i < eList.size(); i++) {
        Edge e = eList.get(i);
        long w1 = dist1[e.t];
        long d = dist1[v.n] + e.c;
        if(w1 > d) {
          dist1[e.t] = d;
          que1.remove(new Vertex(w1, e.t));
          que1.add(new Vertex(d, e.t));
        }
      }
    }
    while(que2.size() > 0) {
      Vertex v = que2.poll();
      ArrayList<Edge> eList = road2[v.n];
      for(int i = 0; i < eList.size(); i++) {
        Edge e = eList.get(i);
        long w2 = dist2[e.t];
        long d = dist2[v.n] + e.c;
        if(w2 > d) {
          dist2[e.t] = d;
          que2.remove(new Vertex(w2, e.t));
          que2.add(new Vertex(d, e.t));
        }
      }
    }
    long ans = 0;
    for(int i = 0; i < N; i++) {
      long t = T - dist1[i] - dist2[i];
      ans = Math.max(ans, t * A[i]);
    }
    System.out.println(ans);
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.