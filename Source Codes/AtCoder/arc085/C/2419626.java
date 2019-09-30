import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;
class Main{

    static class MinCut{
        class Edge{
            int to,rev;
            long cap;
            Edge(int to,long cap,int rev){this.to=to;this.cap=cap;this.rev=rev;}
        }
        List<Edge> edges[];
        int[] itr;
        int[] level;
        void add_edge(int from,int to,long cap){
            edges[from].add(new Edge(to,cap,edges[to].size()));
            edges[to].add(new Edge(from, 0, edges[from].size()-1));
        }
        // dinic?
        // itr, bfs + dfs
        MinCut(int N){
            edges = new ArrayList[N];
            itr = new int[N];
            level = new int[N];
            for(int i=0;i<N;++i)edges[i] = new ArrayList<>();
        }
        private void bfs(int s){
            Deque<Integer> que = new ArrayDeque<>();
            que.add(s);
            Arrays.fill(level, -1);
            level[s]=0;
            while(!que.isEmpty()){
                int v = que.poll();
                for(Edge e : edges[v]){
                    if(level[e.to]<0 && e.cap>0){
                        level[e.to]=level[v]+1;
                        que.add(e.to);
                    }
                }
            }
        }

        private long dfs(int s,int t,long f){
            if(s==t)return f;
            while(itr[s]<edges[s].size()){
                Edge e = edges[s].get(itr[s]);
                if(e.cap>0 && level[e.to]>level[s]){
                    long d = dfs(e.to, t, Math.min(f, e.cap));
                    if(d>0){
                        e.cap-=d;
                        edges[e.to].get(e.rev).cap+=d;
                        return d;
                    }
                }
                ++itr[s];
            }
            return 0;
        }

        long mincut(int s,int t){
            long res =0;
            while(true){
                bfs(s);
                Arrays.fill(itr, 0);
                boolean flag=false;
                while(true){
                    long d = dfs(s,t,Long.MAX_VALUE/10000);
                    if(d>0)flag=true;
                    if(d==0)break;
                    res+=d;
                }
                if(!flag)return res;
            }
        }

    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long[] a = new long[N+1];
        for(int i=1;i<=N;++i)a[i]=scan.nextLong();
        long max = 0;
        for(int i=1;i<=N;++i)if(a[i]>0)max+=a[i];
        MinCut mc = new MinCut(2*N+2);
        for(int i=1;i<=N;++i){
            for(int j=i;j<=N;j+=i)mc.add_edge(j,i+N,Integer.MAX_VALUE);
            mc.add_edge(0,i,(a[i]>0 ? a[i]:0));
            mc.add_edge(N+i, 2*N+1, (a[i]<=0 ? -a[i]:0));
        }
        System.out.println(max - mc.mincut(0,2*N+1));


    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.