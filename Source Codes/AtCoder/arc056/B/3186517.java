import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int S = sc.nextInt();
        //HashSet<Integer>[] map = new HashSet[N+1];
        ArrayList<Integer>[] map = new ArrayList[N+1];
        for(int i=0;i<=N;i++) map[i] = new ArrayList<>();
        for(int i=1;i<=M;i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int a = Math.min(u,v);
            int b = Math.max(u,v);
            map[a].add(b);
        }
        boolean[] res = new boolean[N+1];
        UnionFind uf = new UnionFind(N);
        for(int i=N;i>=1;i--){
            for(Integer w:map[i]){
                uf.union(i,w);
            }
            res[i] = uf.connected(S,i);
        }
        for(int i=1;i<=N;i++){
            if(res[i]) System.out.println(i);
        }

    }
    static class UnionFind{
        private int[] id;
        private int cnt;
        private int N;
        private int[] size;

        public int count(){ return cnt;}

        public boolean connected(int p, int q){
            return find(p)==find(q);
        }

        public UnionFind(int n){
            N = n;
            id = new int[N+1];
            cnt = N;
            size = new int[N+1];
            for(int i=1;i<=N;i++) id[i]=i;
            Arrays.fill(size,1);
        }

        private int find(int p){
            int ans = p;
            while(id[ans]!=ans){
                id[ans] = id[id[ans]];
                ans = id[ans];
            }
            return ans;
        }

        public void union(int p, int q){
            int i = find(p);
            int j = find(q);
            if(i==j) return;
            if(size[i]<size[j]){
                id[i] = j;
                size[j] += size[i];
            } else{
                id[j] = i;
                size[i] += size[j];
            }
            cnt--;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.