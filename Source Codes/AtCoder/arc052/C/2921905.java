import java.util.*;
import java.io.*;
class Main{
  static class Edge{
    int to;
    boolean B;
    Edge(int to, boolean b){this.to=to;B=b;}
  }
 static class Node{
    int v;
    long cost;
    int b;
    Node(int v, long c, int b){this.v=v;this.cost=c;this.b=b;}
  }
  
  static List<Edge>[] edges;
	public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      edges = new List[n];
      for(int i=0;i<n;++i)edges[i] = new ArrayList<>();
      for(int i=0;i<m;++i){
        boolean B = sc.next().charAt(0)=='1';
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        edges[a].add(new Edge(b, B));
        edges[b].add(new Edge(a, B));
      }
      PriorityQueue<Node> que = new PriorityQueue<>((a,b)->a.cost==b.cost ? a.b-b.b : a.cost-b.cost<0?-1:1);
      TreeMap<Integer, Long> dis[] = new TreeMap[n];
      for(int i=0;i<n;++i)dis[i]=new TreeMap<>();
      dis[0].put(0, 0L);
      for(int i=1;i<n;++i)dis[i].put(0, Long.MAX_VALUE);
      que.add(new Node(0, 0L, 0));
      while(!que.isEmpty()){
        Node node = que.poll();
        if(node.cost > dis[node.v].getOrDefault(node.b, Long.MAX_VALUE))continue;
        for(Edge e: edges[node.v]){
          int bnum = node.b + (e.B ? 1:0);
          long cost = node.cost + (e.B ? bnum:1);
          if((long)(dis[e.to].floorEntry(bnum).getValue()) <= cost)continue;
          dis[e.to].put(bnum, cost);
          while(true){
            Map.Entry<Integer, Long> entry = dis[e.to].higherEntry(bnum);
            if(entry == null || entry.getValue()<cost)break;
            dis[e.to].remove(entry.getKey());
          }
          que.add(new Node(e.to, cost, bnum));
        }
      }
      PrintWriter out = new PrintWriter(System.out);
      for(int i=0;i<n;++i)out.println(dis[i].lastEntry().getValue());
      out.flush();
                                     }
                                     } Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.