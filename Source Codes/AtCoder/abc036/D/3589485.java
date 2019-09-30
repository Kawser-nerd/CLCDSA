import java.util.*;

public class Main {
    static long mod = 1000000000+7;
    static ArrayList<Integer>[] map;
    static long[] white;
    static long[] black;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        map = new ArrayList[n+1];
        for(int i=0;i<=n;i++) map[i]=new ArrayList<>();
        black = new long[n+1];
        white = new long[n+1];
        for(int i=1;i<n;i++){
            int a = Integer.parseInt(sc.next());
            int b = Integer.parseInt(sc.next());
            map[a].add(b);
            map[b].add(a);
        }
        boolean[] vis = new boolean[n+1];
        long ans = 1;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            dfs(i,vis);
            ans = ans*(black[i]+white[i])%mod;
        }
        System.out.println(ans);
    }
    static void dfs(int i,boolean[] vis){
        vis[i] = true;
        black[i] = white[i] = 1;
        for(int w:map[i]){
            if(vis[w]) continue;
            dfs(w,vis);
            white[i] = white[i]*(white[w]+black[w])%mod;
            black[i] = black[i]*white[w]%mod;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.