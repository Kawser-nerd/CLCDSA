import java.util.*;

class Main implements Runnable {
    ArrayList<Integer>[] graph;
    boolean[] visited;
    int[] color;
    long one;
    long bipartite;
    long count;
    boolean mujun;
    int dfs(int a,int c){
        if(visited[a]){
            if(color[a]>=0&&color[a]!=c)mujun=true;
            return 0;
        }
        visited[a]=true;
        color[a]=c;
        int total=1;
        for(int b:graph[a]){
            total+=dfs(b,1-c);
        }
        return total;
    }
    public void run(){
        Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        int m=scan.nextInt();
        this.graph=new ArrayList[n];
        for(int i=0;i<n;++i)
            this.graph[i]=new ArrayList<Integer>();
        for(int i=0;i<m;++i){
            int u=scan.nextInt()-1;
            int v=scan.nextInt()-1;
            this.graph[u].add(v);
            this.graph[v].add(u);
        }
        visited=new boolean[n];
        color=new int[n];
        Arrays.fill(color,-1);
        one=0;
        bipartite=0;
        count=0;
        for(int i=0;i<n;++i){
            if(visited[i])continue;
            count++;
            mujun=false;
            int kind=dfs(i,0);
            if(kind==1)one++;
            else if(!mujun)bipartite++;
        }
        long total=one*(2*n-one);
        total+=(count-one)*(count-one);
        total+=bipartite*bipartite;
        System.out.println(total);
    }
    // https://qiita.com/p_shiki37/items/a0f6aac33bf60f5f65e4#%E3%82%B9%E3%82%BF%E3%83%83%E3%82%AF%E3%81%AE%E6%8B%A1%E5%BC%B5
    public static void main(String[] args) {
        new Thread(null, new Main(), "", 128 * 1024 * 1024).start(); //16MB???????????
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.