import java.util.*;
class Main
{
    static int MOD = 1000000007;
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt(), w = sc.nextInt(), ans = 0, x;
        int[][] c = new int[10][10];
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                c[i][j] = sc.nextInt();
        for(int k = 0; k < 10; k++)
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    c[i][j] = Math.min(c[i][j], c[i][k] + c[k][j]);
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if((x = sc.nextInt())!= -1) ans += c[x][1];
        System.out.println(ans);
    }
}