import java.util.*;
import static java.lang.System.*;

//https://atcoder.jp/contests/abc075/tasks/abc075_c
//O(n^2)?????????n=250
//union-find?
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        boolean[][] edges = new boolean[N][N];
        int[] as = new int[M];
        int[] bs = new int[M];
        for (int m = 0; m < M; m++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            as[m] = a-1;
            bs[m] = b-1;
            edges[a-1][b-1] = true;
            edges[b-1][a-1] = true;
        }

        solveUnionFindTree(N, M, as, bs);
        //solver1(N, edges);
        //solver(N, edges);
    }

    // union-find?(???????????????????????)
    // ???????????=????????(?????????)
    public static void solveUnionFindTree(int N, int M, int[] as, int[] bs){
        int ans = 0;
        for(int r1 = 0; r1 < M; r1++) { //????
            // ???
            UnionFindTree road = new UnionFindTree(N);
            for(int r2 = 0; r2 < M; r2++) {
                if(r1 == r2) continue;   //?????
                road.union(as[r2], bs[r2]);
            }

            //??????????????????
            Set<Integer> root = new HashSet<Integer>();
            for(int n = 0; n < N; n++) {
                root.add(road.find(n));
            }

            if(root.size() != 1){
                ans++;
            }
        }
        out.println(ans);
    }

    // https://gist.github.com/keitin/e5ba4ba4ccd6cd3afb3485c5ea85846c#file-union-find-java
    public static class UnionFindTree {
        int[] parent; //???????????????????????????????????
        int[] rank; //parent????????????

        public UnionFindTree(int size) {
            this.parent = new int[size];
            this.rank = new int[size];

            for (int i = 0; i < size; i++) {
                makeSet(i);
            }
        }

        public void makeSet(int i) {
            parent[i] = i;
            rank[i] = 0; //?????
        }

        public void union(int x, int y) {
            int xRoot = find(x);
            int yRoot = find(y);

            //x?????????????
            if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot; //y???x???

            } else if(rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;

            } else if (xRoot != yRoot){
                parent[yRoot] = xRoot;
                rank[xRoot]++; //??????????????????????++;
            }
        }

        //????????????id???
        public int find(int i) {
            if (i != parent[i]) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }

        //??????????
        public boolean same(int x, int y) {
            return find(x) == find(y);
        }
    }

    // ?????? 21:12-21:31
    public static void solver1(int N, boolean[][] edges){
        int ans = 0;

        for(int from = 0; from < N; from++){
            for(int to = from + 1; to < N; to++){
                if(edges[from][to] == true){
                    boolean [][] copiedEdges = new boolean[N][N];
                    for(int i=0; i< N; i++) {
                        System.arraycopy(edges[i], 0, copiedEdges[i], 0, edges[i].length);
                    }
                    copiedEdges[from][to] = false;
                    copiedEdges[to][from] = false;
                    //out.println(from+" "+to);
                    if (canPassAllNodes(N, 0, copiedEdges, new boolean[N]) == false){
                        //out.println("notPassed"+from+" "+to);
                        ans++;
                    };
                }
            }
        }

        out.println(ans);
    }

    public static boolean canPassAllNodes(int N, int pos, boolean[][] edges, boolean[] passed){
        passed[pos] = true;

        boolean isPassed = true;
        for(int n = 0; n < N; n++){
            if(passed[n] == false){
                isPassed = false;
            }
        }

        if(isPassed == true){
            return true;
        }

        for(int n = 0; n < N; n++){
            if(edges[pos][n] == true && passed[n] == false){
                int next = n;
                if(canPassAllNodes(N, next, edges, passed) == true){
                    return true;
                }
            }
        }
        return false;
    }

    public static void solver(int N, boolean[][] edges){
        //??????????????
        Set<Integer> left_nodes = new HashSet<Integer>();
        for(int n = 0; n < N; n++) {
            left_nodes.add(n);
        }

        //1????????????????????????????
        //????????????????????(??????????????????)
        int ans = 0;
        int before_ans = ans + 1;
        while (ans != before_ans) {
            before_ans = ans;
            HashMap<Integer, Integer>  bridgeable_nodes = new HashMap<Integer, Integer>(); //?????????????

            for(Integer from: left_nodes) {
                ArrayList<Integer> bridge_nodes = new ArrayList<Integer>();  //n????????
                for(int to=0; to<N; to++){
                    if(edges[from][to] == true){ bridge_nodes.add(to); }
                }

                //1????????????????
                if (bridge_nodes.size() == 1){
                    bridgeable_nodes.put(from, bridge_nodes.get(0));
                }
            }

            //????????????????????
            for(Integer from: bridgeable_nodes.keySet()) {
                int to = bridgeable_nodes.get(from);
                left_nodes.remove(from);

                //????????????1????????????????1<->2???????1?2???????????
                if(edges[from][to] == false){
                    continue;
                }

                edges[from][to] = false; //?????????????????????????????????
                edges[to][from] = false;

                ans++;
            }
        }

        out.println(ans);
    }
}