import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        long[] dist = new long[N+1];
        final long inf = Long.MAX_VALUE/2;
        Arrays.fill(dist,inf);
        dist[1]=0;
        ArrayList<Edge>[] map = new ArrayList[N+1];
        for(int i=0;i<=N;i++) map[i]=new ArrayList<>();
        for(int i=0;i<M;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            long c = (-1)*sc.nextLong();
            map[a].add(new Edge(b,c));
        }
        for(int pass=1;pass<N;pass++){ // do N-1 pass. if no negative cycle, already finished for all vertice
            for(int ver = 1;ver<=N;ver++){
                if(dist[ver]==inf) continue;
                for(int i=0;i<map[ver].size();i++){
                    Edge e = map[ver].get(i);
                    if(dist[e.to]>dist[ver]+e.weight) dist[e.to]=dist[ver]+e.weight;
                }
            }
        }

        long ans = dist[N]*(-1);

        boolean[] neg = new boolean[N+1];
        for(int pass=1;pass<=N;pass++){
            for(int ver=1;ver<=N;ver++){
                if(dist[ver]==inf) continue;
                for(int i=0;i<map[ver].size();i++){
                    Edge e = map[ver].get(i);
                    if(dist[e.to]>dist[ver]+e.weight){
                        dist[e.to]=dist[ver]+e.weight;
                        neg[e.to] = true;
                    }
                    if(neg[ver]) neg[e.to]=true;
                }
            }
        }
        if(neg[N]) System.out.println("inf");
        else System.out.println(ans);
    }
    static class Edge {
        int to;
        long weight;
        public Edge(int t, long w){
            this.to = t;
            this.weight = w;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.