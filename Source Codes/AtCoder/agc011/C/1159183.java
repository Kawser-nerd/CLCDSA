import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dx = {-1, 0, 1, 0, -1, 1, 1, -1};
    public static int[] dy = {0, 1, 0, -1, 1, 1, -1, -1};
    public static int INF = 0x3f3f3f3f;
    public static long LINF = 0x3f3f3f3f3f3f3f3fL;
    public static int MOD = 1000000007;

    public static boolean[] vis;
    public static int[] col;
    public static int size;
    public static boolean is2;

    public static void dfs(int u, int c){
        size++;
        col[u] = c;

        for(int v : adjList.get(u)){
            if(vis[v]){
                if(col[u] == col[v]){
                    is2 = false;
                }
            } else{
                vis[v] = true;
                dfs(v, c*-1);
            }
        }
    }


    public static void main(String[] args) throws Exception{
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        adjList = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < N; i++){
            adjList.add(new ArrayList<Integer>());
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        vis = new boolean[N];
        col = new int[N];

        long n0 = 0;
        long n1 = 0;
        long n2 = 0;
 
        for(int i = 0; i < N; i++){
            if(vis[i]) continue;
            vis[i] = true;
            size = 0;
            is2 = true;
            dfs(i, 1);
            if(size == 1){
                n0++;
            } else{
                if(is2){
                    n2++;
                } else{
                    n1++;
                }
            }
        }
        long ans = 0;
        ans += (N * n0) + (N - n0) * n0;
        ans += (n2 * n2 * 2);
        ans += (n1 * n1);
        ans += (n1 * n2 * 2);
        pw.print(ans + "\n");
        
        pw.close(); 
        br.close();
    }
}

class Pair {
    public int a, b;

    Pair(int a, int b){
        this.a = a;
        this.b = b;
    }

}