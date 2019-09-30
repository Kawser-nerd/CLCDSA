import java.util.HashSet;
import java.util.ArrayList;
import java.util.Set;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main{

    static class Edge{
        int to;
        long cost;
        Edge(int to,long cost){
            this.to = to;
            this.cost = cost;
        }
    }
    static class pqNum{
        int v;
        long dis;
        pqNum(int v,long d){
            this.v=v;
            dis=d;
        }
    }

    static void Dijkstra(int v, long[] dis){
        Arrays.fill(dis,Long.MAX_VALUE/2);
        dis[v]=0;
        PriorityQueue<pqNum> que = new PriorityQueue<>((a,b) -> a.dis < b.dis ? -1:1);
        que.add(new pqNum(v,0));
        while(!que.isEmpty()){
            pqNum pq = que.poll();
            if(dis[pq.v] < pq.dis)continue;
            for(Edge e : edge[pq.v]){
                if(dis[e.to] > dis[pq.v] + e.cost){
                    dis[e.to] = dis[pq.v]+e.cost;
                    que.add(new pqNum(e.to,dis[e.to]));
                }
            }
        }
    }

    static void setNum(int v,long[] dis,long[] dp){
        Arrays.fill(dp,0);
        dp[v] = 1;
        Set<Integer> set = new HashSet<>();
        PriorityQueue<pqNum> que = new PriorityQueue<>((a,b) -> a.dis<b.dis ? -1:1);
        long mod = (long)1e9+7;
        que.add(new pqNum(v,0));
        set.add(v);
        while(!que.isEmpty()){
            pqNum pq = que.poll();
            for(Edge e : edge[pq.v]){
                if(dis[e.to] == dis[pq.v] + e.cost){
                    dp[e.to] =(dp[e.to] + dp[pq.v])%mod;
                    if(!set.contains(e.to)){
                        set.add(e.to);
                        que.add(new pqNum(e.to,dis[e.to]));
                    }
                }
            }
        }
    }


    static List<Edge>[] edge;

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        int S = scan.nextInt();
        int T = scan.nextInt();
        long mod = (long)1e9+7;

        edge = new ArrayList[N+1];
        for(int i=1;i<=N;++i)edge[i]=new ArrayList<>();

        for(int i=0;i<M;++i){
            int u=Integer.parseInt(scan.next());
            int v=Integer.parseInt(scan.next());
            long d=Long.parseLong(scan.next());
            edge[u].add(new Edge(v,d));
            edge[v].add(new Edge(u,d));
        }


        long disS[] = new long[N+1];
        long disT[] = new long[N+1];
        Dijkstra(S,disS);
        Dijkstra(T,disT);

        long dpS[] = new long[N+1];
        long dpT[] = new long[N+1];
        setNum(S,disS,dpS);
        setNum(T,disT,dpT);

        List<Long> V = new ArrayList<>();

        long path = disS[T];
        for(int i=1;i<=N;++i){
            if(disS[i]*2 == path)V.add((dpS[i]*dpT[i])%mod);
            else{
                for(Edge e : edge[i]){
                    if(disS[i] + e.cost + disT[e.to] == path && disS[i]*2 < path && disT[e.to]*2 < path)V.add((dpS[i]*dpT[e.to])%mod);
                }
            }
        }
        long ans = 0;
        long sum = 0;
        for(long l : V)sum=(sum+l)%mod;
        for(long v : V)ans = (ans + (v * (sum-v+mod)%mod)%mod)%mod;
        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.