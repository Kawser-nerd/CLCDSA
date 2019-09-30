import java.util.*;

public class Main {
    private static int N;
    private static int M;
    private static int r;
    private static int t;
    private static List<Edge>[] node;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        M = scan.nextInt();
        r = scan.nextInt();
        t = scan.nextInt();

        node = new List[N];
        for(int i = 0;i < N;i++) node[i] = new ArrayList<>();

        for (int i=0;i<M;i++){
            int a = scan.nextInt() - 1;
            int b = scan.nextInt() - 1;
            int c = scan.nextInt();
            node[a].add(new Edge(b,c));
            node[b].add(new Edge(a,c));
        }

    }

    static class Edge{
        int to,dist;
        Edge(int to,int d){
            this.to = to;
            dist    = d;
        }
    }

    static int [] dijkstra(List<Edge>[] node,int s){
        Queue<Pos> queue = new PriorityQueue<>();
        queue.add(new Pos(s,0));
        int[] dist = new int[node.length];
        Arrays.fill(dist,Integer.MAX_VALUE);
        while(!queue.isEmpty()){
            Pos p = queue.poll();
            if(dist[p.id] < Integer.MAX_VALUE) continue;
            dist[p.id] = p.dist;
            for(Edge e: node[p.id]){
                queue.add(new Pos(e.to,e.dist + p.dist));
            }
        }
        Arrays.sort(dist);
        return dist;
    }

    static class Pos implements Comparable<Pos>{
        int id,dist;

        Pos(int id,int d){
            this.id = id;
            dist    = d;
        }

        public int compareTo(Pos o){
            return dist - o.dist;
        }
    }

    static int binarySearch(int []a,int v){
        int l = 0, r = a.length - 1, s = -1;

        while(l <= r){
            int m = (l + r)/2;

            if(a[m] >= v){
                s = m;
                r = m - 1;
            }else l = m + 1;
        }
        return s;
    }

    public static void main(String args[]) {
        //??
        input();

        long ans = 0;
        for(int i = 0;i < N;i++){
            int dist[] = dijkstra(node,i);   // ???(i)???????????????????
            for(int j = 1 ;j < N;j++){
                final int d = (int) ((dist[j] * r + t) / t);   // ????????
                final int idx = binarySearch(dist,d);          // ?????????????????
                if(idx < 0) break;
                ans += N - idx - (r < t ? 1 : 0);   // ???????????????
            }
        }
        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.