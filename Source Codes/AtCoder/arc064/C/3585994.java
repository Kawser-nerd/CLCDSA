import java.util.*;

public class Main{
    
    static int[] x;
    static int[] y;
    static int[] r;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int sx = Integer.parseInt(sc.next());
        int sy = Integer.parseInt(sc.next());
        int gx = Integer.parseInt(sc.next());
        int gy = Integer.parseInt(sc.next());
        int n = Integer.parseInt(sc.next());
        x = new int[n+2];
        y = new int[n+2];
        r = new int[n+2];
        x[0] = sx;
        y[0] = sy;
        x[n+1] = gx;
        y[n+1] = gy;
        for(int i=0; i<n; i++){
            x[i+1] = Integer.parseInt(sc.next());
            y[i+1] = Integer.parseInt(sc.next());
            r[i+1] = Integer.parseInt(sc.next());
        }
        
        Dijkstra dj = new Dijkstra(n+2);
        for(int i=0; i<n+2; i++){
            for(int j=i+1; j<n+2; j++){
                long difx = Math.abs(x[i]-x[j]);
                long dify = Math.abs(y[i]-y[j]);
                double dis = Math.sqrt(difx*difx + dify*dify);
                double cost = Math.max(0, dis-(r[i]+r[j]));
                dj.addEdge(i, j, cost);
            }
        }
        
        double[] dist = dj.dijkstra(0);
        System.out.println(dist[n+1]);
        
    }
}


class Dijkstra{
    
    public final long INF = (long)1e18;
    private int n;
    private List<Edge>[] edge;
    
    public Dijkstra(int n){
        this.n = n;
        edge = new List[n];
        for(int i=0; i<n; i++){
            edge[i] = new ArrayList<>();
        }
    }
    
    public void addEdge(int from, int to, double cost){
        edge[from].add(new Edge(from, to, cost));
        edge[to].add(new Edge(to, from, cost));
    }
    
    public double[] dijkstra(int from){
        double[] dist = new double[n];
        Arrays.fill(dist, INF);
        dist[from] = 0;
        
        PriorityQueue<Vertex> q = new PriorityQueue<>();
        q.add(new Vertex(from, 0));
        while(q.size() != 0){
            Vertex p = q.poll();
            int u = p.ver;
            if (dist[u] < p.cost) {
                continue;
            }
            for(Edge ne : edge[u]){
                int v = ne.to;
                double weight = ne.cost;
                if(dist[v] > dist[u]+weight){
                    dist[v] = dist[u]+weight;
                    q.add(new Vertex(v, dist[v]));
                }
            }
        }
        
        return dist;
    }
}

class Edge implements Comparable<Edge>{
    public int from = 0;
    public int to = 0;
    public double cost = 0;
    
    public Edge(int from, int to, double cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
    
    @Override
    public int compareTo(Edge o) {
        double tmp = this.cost - o.cost;
        if(tmp == 0.0) return 0;
        return (int)(tmp/Math.abs(tmp));
    }
}

class Vertex implements Comparable<Vertex>{
    public int ver = 0;
    public double cost = 0;
    
    public Vertex(int ver, double cost) {
        this.ver = ver;
        this.cost = cost;
    }
    
    @Override
    public int compareTo(Vertex o) {
        double tmp = this.cost - o.cost;
        if(tmp == 0.0) return 0;
        return (int)(tmp/Math.abs(tmp));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.