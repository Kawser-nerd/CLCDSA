import java.util.*;

public class Main{
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int t = sc.nextInt();        
             
        long money[] = new long[N];
        
        for(int i = 0;i < N;i++){
             money[i]  = sc.nextLong();   
        }
        
        Dijkstra dijkstra1 = new Dijkstra(N);
        Dijkstra dijkstra2 = new Dijkstra(N);
        
        for (int i = 0; i < M; i++) {
                int from = sc.nextInt() - 1;
                int to =   sc.nextInt() - 1;
                int cost = sc.nextInt();

                dijkstra1.addDirectedEdge(from, to, cost);
                dijkstra2.addDirectedEdge(to, from, cost);
        }

        long[] dist1 = dijkstra1.getDist(0);
        long[] dist2 = dijkstra2.getDist(0);
        
            long ans = 0;
        
            for (int i = 0; i < N; i++) {
                if (t >= dist1[i] + dist2[i])
                    ans = Math.max(ans, money[i] * (t - (dist1[i] + dist2[i])));
            }        
                
            System.out.println(ans);        
            
    }        
}
        
class Dijkstra{
        int n;
        ArrayList<Pair>[] G;
        long INF = Long.MAX_VALUE / 3;

        public Dijkstra(int n) {
            this.n = n;
            G = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                G[i] = new ArrayList<>();
            }
        }

        public void addDirectedEdge(int from, int to, int cost) {
            G[from].add(new Pair(to, cost));
        }

        public long[] getDist(int s) {
            PriorityQueue<Pair> Q = new PriorityQueue<>();
            Q.add(new Pair(s, 0));
            
            long[] dist = new long[n];            
            Arrays.fill(dist, INF);            
            boolean[] used = new boolean[n];
            
            while (!Q.isEmpty()) {
                Pair p = Q.poll();
                if (used[p.x]) continue;
                used[p.x] = true;
                dist[p.x] = p.y;

                for (Pair edge : G[p.x]) {
                    Q.add(new Pair(edge.x, p.y + edge.y));
                }
                
            }
            
            return dist;            
        }

       
        
        class Pair implements Comparable<Pair> {
            int x;
            long y;

            Pair(int x, long y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return Long.compare(y, p.y);
            }

        }
        
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.