import java.util.*;

class Main{
    static final long Mod = 1000000000+7;
    static int maxN = 100000+5;
    static ArrayList<Integer>[] unGraph = new ArrayList[maxN+1];
    static ArrayList<Integer>[] diGraph = new ArrayList[maxN+1];
    static long[] black;
    static long[] white;
    static long[] all;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<=maxN;i++){
            unGraph[i] = new ArrayList<>();
            diGraph[i] = new ArrayList<>();
        }
        int N = sc.nextInt();
        black = new long[N+1];
        white = new long[N+1];
        all = new long[N+1];

        for(int i=0;i<N-1;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            unGraph[a].add(b);
            unGraph[b].add(a);
        }
        bfs(N);
        Arrays.fill(black,1);
        Arrays.fill(white,1);
        dfs(1);
        System.out.println(all[1]);
    }

    static void dfs(int root){
        if(diGraph[root].size()!=0){
            for(int i=0;i<diGraph[root].size();i++){
                dfs(diGraph[root].get(i));
            }
            for(int i=0;i<diGraph[root].size();i++){
                int cur = diGraph[root].get(i);
                white[root] = white[root]*all[cur]%Mod;
                black[root] = black[root]*white[cur]%Mod;
            }
        }
        all[root] = (white[root]+black[root])%Mod;
    }
    static void bfs(int N){
        boolean[] vis = new boolean[N+1];
        LinkedList<Integer> cur = new  LinkedList<>();
        cur.add(1);
        while(cur.size()>0){
            int now = cur.poll();
            vis[now]=true;
            for(Integer w:unGraph[now]){
                if(!vis[w]){
                    cur.add(w);
                    diGraph[now].add(w);
                }
            }
        }
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.