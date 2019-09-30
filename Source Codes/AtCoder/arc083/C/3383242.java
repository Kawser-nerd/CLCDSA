import java.util.*;

class Main {
    static ArrayList<Integer>[] map;
    static final int inf = Integer.MAX_VALUE/10;
    static int[] other;
    static int[] X;
    static int[][] dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        map = new ArrayList[n+1];
        for(int i=0;i<=n;i++) map[i] = new ArrayList<>();
        other = new int[n+1];
        X = new int[n+1];
        for(int i=2;i<=n;i++){
            int p = sc.nextInt();
            map[p].add(i);
        }
        for(int i=1;i<=n;i++) X[i] = sc.nextInt();
        dfs(1);
        String ans = other[1]<inf?"POSSIBLE":"IMPOSSIBLE";
        System.out.println(ans);
    }

    static void dfs(int s){
        int len = map[s].size();
        if(len==0) return;
        for(int i=0;i<len;i++) dfs(map[s].get(i));
        dp = new int[len+1][X[s]+1];
        for(int i=0;i<dp.length;i++) Arrays.fill(dp[i],inf);
        dp[0][0] = 0;
        for(int i=1;i<=len;i++){
            int curX = X[map[s].get(i-1)];
            int curF = other[map[s].get(i-1)];
            for(int j=0;j<=X[s];j++){
                if(j>=curX) dp[i][j] = Math.min(dp[i][j],dp[i-1][j-curX]+curF);
                if(j>=curF) dp[i][j] = Math.min(dp[i][j],dp[i-1][j-curF]+curX);
            }
        }
        other[s] = inf;
        for(int j=0;j<=X[s];j++){
            other[s] = Math.min(other[s],dp[len][j]);
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.