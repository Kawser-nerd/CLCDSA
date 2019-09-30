import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        
        BellmanFord bf = new BellmanFord(n);
        
        for(int i=0; i<m; i++){
            int a = Integer.parseInt(sc.next());
            int b = Integer.parseInt(sc.next());
            int c = Integer.parseInt(sc.next());
            bf.addEdge(a-1, b-1, -c);
        }
        
        boolean isInf = bf.bellmanford(0);
        long ans = -bf.getDist(n-1);
        
        if(isInf){
            System.out.println("inf");
        }else{
            System.out.println(ans);
        }
    }
}

class BellmanFord{
    
    public final long INF = (long)1e18;
    private int n;
    private List<Edge>[] graph;
    private long[] dist;
    
    public BellmanFord(int n){
        this.n = n;
        graph = new List[n];
        for(int i=0; i<n; i++){
            graph[i] = new ArrayList<>();
        }
    }
    
    public void addEdge(int from, int to, int cost){
        graph[from].add(new Edge(to, cost));
    }
    
    public boolean bellmanford(int from){
        dist = new long[n];
        Arrays.fill(dist, INF);
        dist[from] = 0;
        
        for(int i=0; i<n; i++){
            for(int v=0; v<n; v++){
                for(int k=0; k<graph[v].size(); k++){
                    Edge e = graph[v].get(k);
                    if(dist[v] != INF && dist[e.to] > dist[v] + e.cost){
                        dist[e.to] = dist[v] + e.cost;
                        /*if(i==n-1){
                            //n??????????????????
                            return true;
                        }*/
                        if(i==n-1 && e.to==n-1){
                            //n?????N???????????INF
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
    
    public long getDist(int to){
        if(dist != null){
            return dist[to];
        }
        return -1;
    }
}

class Edge implements Comparable<Edge>{
    public int to = 0;
    public int cost = 0;
    
    public Edge(int to, int cost) {
        this.to = to;
        this.cost = cost;
    }
    
    @Override
    public int compareTo(Edge o) {
        return this.cost - o.cost;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.