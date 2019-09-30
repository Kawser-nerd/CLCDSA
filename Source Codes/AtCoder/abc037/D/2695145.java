import java.util.Scanner;

public class Main {

    static int H,W;
    static int[][] src;
    static int[][] dp;
    static final int MOD = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        H = Integer.parseInt(sc.next());
        W = Integer.parseInt(sc.next());
        src = new int[H][W];
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                src[i][j] = Integer.parseInt(sc.next());
            }
        }
        dp = new int[H][W];
        int ans = 0;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                ans = (ans + pattern(j,i))%MOD;
            }
        }
        System.out.println(ans);
    }
    static int pattern(int x, int y) {
        if(dp[y][x] > 0) return dp[y][x];
        int a = src[y][x];
        int ret = 1;
        if(x > 0 && a > src[y][x-1]) ret = (ret + pattern(x-1,y))%MOD;
        if(y > 0 && a > src[y-1][x]) ret = (ret + pattern(x,y-1))%MOD;
        if(x < W-1 && a > src[y][x+1]) ret = (ret + pattern(x+1,y))%MOD;
        if(y < H-1 && a > src[y+1][x]) ret = (ret + pattern(x,y+1))%MOD;
        return dp[y][x] = ret;
    }
}