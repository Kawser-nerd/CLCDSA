import java.util.*;

public class Main{
    public static int h,w;
    public static int[][] a;
    public static int[][] memo;
    public static final int MOD = (int)1e9 + 7;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        h = sc.nextInt();
        w = sc.nextInt();
        
        a = new int[h][w];
        memo = new int[h][w];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                a[i][j] = Integer.parseInt(sc.next());
                memo[i][j] = -1;
            }
        }
        
        long ans = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                ans += saiki(j, i);
                ans %= MOD;
            }
        }
        
        System.out.println(ans);
    }
    
    public static int saiki(int x, int y){
        if(memo[y][x] != -1) return memo[y][x];
        
        long res = 0;
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<w && 0<=ny && ny<h && a[y][x]>a[ny][nx]){
                res += saiki(nx, ny);
            }
        }
        memo[y][x] = (int)(res%MOD)+1;
        return memo[y][x];
    }
}