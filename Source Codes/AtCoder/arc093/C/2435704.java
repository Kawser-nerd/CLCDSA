import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Edge{
    int from,to;
    long w;
    Edge(int from,int to,long w){this.from=from;this.to=to;this.w=w;}
}

class MinCostTree{

    int N;

    List<Edge> edges[];
    List<Edge> minedge[];
    boolean tree[][];
    void add_edge(int u,int v,long w){
        edges[u].add(new Edge(u,v,w));
        edges[v].add(new Edge(v,u,w));
    }
    MinCostTree(int N){
        this.N=N;
        edges = new ArrayList[N];
        minedge = new ArrayList[N];
        tree = new boolean[N][N];
        for(int i=0;i<N;++i)edges[i]=new ArrayList<>();
        for(int i=0;i<N;++i)minedge[i]=new ArrayList<>();
    }
    long mincost(){
        PriorityQueue<Edge> que = new PriorityQueue<>((a,b)->a.w<b.w ? -1:1);
        boolean used[] = new boolean[N];
        used[0]=true;
        long res = 0;
        for(Edge e : edges[0])que.add(e);
        while(!que.isEmpty()){
            Edge e = que.poll();
            if(used[e.to])continue;
            used[e.to]=true;
            minedge[e.from].add(e);
            minedge[e.to].add(new Edge(e.to, e.from, e.w));
            tree[e.from][e.to]=tree[e.to][e.from]=true;
            res += e.w;
            for(Edge ed : edges[e.to])que.add(ed);
        }
        return res;
    }
}

class Main{

    static long[][] lpath;
    static long[][] edge;
    static boolean[] used;
    static MinCostTree mct;

    static void dfs(int s, int v, long lp){
        used[v]=true;
        lpath[s][v]=lp;
        for(Edge e : mct.minedge[v]){
            if(used[e.to])continue;
            dfs(s, e.to, Math.max(lp, e.w));
        }
    }


    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        long X = scan.nextLong();
        edge = new long[n][n];
        lpath = new long[n][n];
        used = new boolean[n];
        for(long[] ar : edge)Arrays.fill(ar, -1);
        long mod = (long)1e9+7;
        mct = new MinCostTree(n);
        for(int i=0;i<m;++i){
            int u = scan.nextInt()-1;
            int v = scan.nextInt()-1;
            long w = scan.nextLong();
            edge[u][v]=edge[v][u]=w;
            mct.add_edge(u, v, w);
        }
        long two[] = new long[m+1];
        two[0]=1;
        for(int i=1;i<m+1;++i)two[i]=(two[i-1]*2)%mod;
        long ans = 0;
        long minX = mct.mincost();
        long[][] d = new long[n][n];
        for(int i=0;i<n;++i){
            Arrays.fill(used, false);
            dfs(i,i,0);
        }

        for(int i=0;i<n;++i)for(int j=0;j<n;++j)d[i][j]=edge[i][j]-lpath[i][j];
        if(X==minX){
            //d[i][j]==0??!tree[i][j]
            int cnt = 0;
            for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)if(d[i][j]==0 && !mct.tree[i][j])++cnt;
            ans = (((two[n-1]-2+mod)%mod)*(two[m-n+1]))%mod;
            for(int i=0;i<cnt;++i)ans = (ans + two[m-n+1 -i])%mod;
        }else if(minX<X){
            long D = X-minX;
            int cnt = 0;
            int larg = 0;
            for(int i=0;i<n;++i)for(int j=i+1;j<n;++j){
                if(d[i][j]==D)++cnt;
                else if(d[i][j]>D)++larg;
            }
            while(cnt-->0)ans = (ans + two[cnt+1+larg])%mod;
        }
        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.