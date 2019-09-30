import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        PriorityQueue<Edge> road = new PriorityQueue<>(M);
        for(int i=0;i<M;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int y = sc.nextInt();
            road.add(new Edge(a,b,y));
        }
        int Q = sc.nextInt();
        PriorityQueue<human> man = new PriorityQueue<>(Q);
        for(int i=0;i<Q;i++){
            int v = sc.nextInt();
            int w = sc.nextInt();
            man.add(new human(i,v,w));
        }
        int[] res = new int[Q];
        UnionFound uf = new UnionFound(N);
        for(int pass=0;pass<Q;pass++){
            human now = man.poll();
            while(road.size()>0&&road.peek().year>now.latest){
                Edge cur = road.poll();
                uf.union(cur.left,cur.right);
            }
            res[now.id]=uf.size(now.city);
        }
        for(int i=0;i<Q;i++){
            System.out.println(res[i]);
        }

    }
    // the edge with larger year come out first int pq
    static class Edge implements Comparable<Edge>{
        int left;
        int right;
        int year;
        public Edge(int u, int v, int time){
            this.left = u;
            this.right = v;
            this.year = time;
        }
        @Override
        public int compareTo(Edge o){
            return -this.year+o.year;
        }
    }
    // human with later year demand (thus, more demanding, less choice) comes first;
    static class human implements Comparable<human>{
        int id;
        int city;
        int latest;
        public human(int id, int place, int year){
            this.id = id;
            this.latest = year;
            this.city = place;
        }
        @Override
        public int compareTo(human o){
            return -(this.latest-o.latest);
        }
    }
    static class UnionFound{
        private int N;
        private int[] id;
        private int[] sz;
        private int cnt;

        public UnionFound(int n){
            N = n;
            id = new int[N+1];
            for(int i=1;i<=N;i++) id[i]=i;
            sz = new int[N+1];
            Arrays.fill(sz,1);
            cnt = N;
        }
        public int count(){return cnt;}
        public boolean connected(int p, int q){return find(p)==find(q);}
        private int find(int p){
            if(p==id[p]) return p;
            else{
                id[p]=find(id[p]);
                return id[p];
            }
        }
        public void union(int p, int q){
            int i=find(p);
            int j=find(q);
            if(i==j) return;
            if(sz[i]<sz[j]){
                id[i]=j;
                sz[j]+=sz[i];
            } else{
                id[j]=i;
                sz[i]+=sz[j];
            }
            cnt--;
        }
        public int size(int p){return sz[find(p)];}
    }

}