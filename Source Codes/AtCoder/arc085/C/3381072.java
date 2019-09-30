import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] A = new long[n+1];
        for(int i = 1; i<=n;i++) A[i] =sc.nextLong();
        Flow sl = new Flow(A);
        long res = sl.max_flow(0,n+1);
        long sum = 0;
        for(int i=1;i<=n;i++) sum += Math.max(0,A[i]);
        System.out.println(sum-res);
    }
    static class Flow{
        long inf = Long.MAX_VALUE/10000;
        int n;
        int[] level;
        int[] iter;
        ArrayList<Edge>[] map;

        public Flow(long[] A){
            n = A.length-1;
            level = new int[n+2];
            iter = new int[n+2];
            map = new ArrayList[n+2];
            for(int i=0;i<=n+1;i++) map[i] = new ArrayList<>();
            for(int i=1;i<=n;i++){
                if(A[i]<=0) add_Edge(0,i,Math.abs(A[i]));
                if(A[i]>0) add_Edge(i,n+1,A[i]);
            }
            for(int i=1;i<=n;i++){
                for(int j=2*i; j<=n; j+=i) add_Edge(i, j, inf);
            }
        }

        void add_Edge(int from, int to, long cap){
            map[from].add(new Edge(to, cap, map[to].size()));
            map[to].add(new Edge(from, 0, map[from].size()-1));
        }

        void bfs(int s){
            Arrays.fill(level, -1);
            LinkedList<Integer> que = new LinkedList<>();
            level[s]=0;
            que.add(s);
            while(que.size()>0){
                int v = que.poll();
                for(int i=0;i<map[v].size();i++){
                    Edge e = map[v].get(i);
                    if(e.cap>0&&level[e.to]<0){
                        level[e.to] = level[v]+1;
                        que.add(e.to);
                    }
                }
            }
        }

        long dfs(int v, int t, long f){
            if(v==t) return f;
            int start = iter[v];
            for(int i=start;i<map[v].size();i++){
                Edge e = map[v].get(i);
                if(e.cap>0&&level[v]<level[e.to]){
                    long d = dfs(e.to,t,Math.min(f,e.cap));
                    if(d>0){
                        e.cap -= d;
                        map[e.to].get(e.rev).cap += d;
                        return d;
                    }
                }
                iter[v]++;
            }
            return 0;
        }

        long max_flow(int s, int t){
            long flow = 0;
            for(;;){
                bfs(s);
                if(level[t]<0) return flow;
                Arrays.fill(iter,0);
                long f = dfs(s,t,inf);
                while(f>0){
                    flow += f;
                    f = dfs(s,t,inf);
                }
            }
        }

    }
    static class Edge{
        long cap;
        int to;
        int rev;
        public Edge(int t, long c, int r){
            this.to = t;
            this.cap = c;
            this.rev = r;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.