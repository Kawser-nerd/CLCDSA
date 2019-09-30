/**
 * Created at 12:29 on 2019/03/07
 */

import java.io.*;
import java.util.*;

public class Main {

  static FastScanner sc = new FastScanner();

  static int N, M;
  static long T;

  static long startTime;

  static long INF = Long.MAX_VALUE;

  public static void main(String[] args) {

    N = sc.nextInt(); //???
    M = sc.nextInt(); //???
    T = sc.nextLong(); //????

    startTime = System.currentTimeMillis();

    long[] money = new long[N];
    for (int i=0; i<N; i++) {
      money[i] = sc.nextLong();
    }

    Edge[] roads = new Edge[M];
    for (int i=0; i<M; i++) {
      roads[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
    }

    Node[] n1 = g(roads);

    for (Edge e : roads) {
      e.reverse();
    }

    Node[] n2 = g(roads);

    long ans = 0;
    for (int i=0; i<N; i++) {
      if (n1[i].cost == INF || n2[i].cost == INF) continue;
      long t = T - n1[i].cost - n2[i].cost;
      if (t < 0) continue;
      ans = Math.max(ans, t * money[i]);
    }

    System.out.println(ans);

    //System.out.println("(" + (System.currentTimeMillis() - startTime) + "ms)");

  }

  static Node[] g(Edge[] oRoads) {

    Node[] towns = new Node[N];
    towns[0] = new Node(0, 0);
    for (int i=1; i<N; i++) {
      towns[i] = new Node(i, INF);
    }

    Edge[] roads = new Edge[M];
    for (int i=0; i<M; i++) {
      roads[i] = new Edge(oRoads[i].iFrom, oRoads[i].iTo, oRoads[i].cost);
    }

    return f(towns, roads, 0);
  }

  static Node[] f(Node[] nodeArray, Edge[] edges, int iStart) {

    for (Edge e : edges) {
      e.from = nodeArray[e.iFrom];
      e.to   = nodeArray[e.iTo];
      nodeArray[e.iFrom].addEdge(e);
    }

    PriorityQueue<Node> nodes = new PriorityQueue<>();
    nodes.add(nodeArray[iStart]);

    while(!nodes.isEmpty()) {
      Node n = nodes.poll();
      for (Edge e : n.edges) {
        long newCost = n.cost + e.cost;
        if (newCost < e.to.cost) {
          e.to.cost = newCost;
          nodes.add(e.to);
        }
      }
    }

    return nodeArray;
  }

  static class Edge {
    int iFrom, iTo;
    Node from, to;
    long cost;
    public Edge(int iFrom, int iTo, long cost) {
      this.iFrom = iFrom;
      this.iTo = iTo;
      this.cost = cost;
    }
    /*
      from?to??????????????
     */
    public void reverse() {
      int temp = iFrom;
      iFrom = iTo;
      iTo = temp;
    }
    /*
      from?to?????????????????????
     */
    public void reverse(Node[] nodes) {
      from.edges.remove(this);

      reverse();
      from = nodes[iFrom];
      to = nodes[iTo];

      from.edges.add(this);
    }
  }

  static class Node implements Comparable<Node> {
    int i;
    long cost;
    HashSet<Edge> edges = new HashSet();

    public Node(int i, long cost) {
      this.i = i;
      this.cost = cost;
    }
    public void addEdge(Edge e) {
      edges.add(e);
    }

    @Override
    public int compareTo(Node o) {
      if (cost == o.cost) return 0;
      return (cost - o.cost > 0) ? 1 : -1;
    }
  }

  static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    public long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
      long n = 0;
      boolean minus = false;
      int b = readByte();
      if (b == '-') {
        minus = true;
        b = readByte();
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException();
      }
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }

    public int nextInt() {
      return (int) nextLong();
    }
  }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.