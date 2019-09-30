import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[][] s = new char[n][n];
        for(int i = 0; i < n; i ++){
            String ss = sc.next();
            for(int j = 0; j < n; j++) s[i][j] = ss.charAt(j);
        }
        int ans = 0;
        for(int a = 0; a < n; a++){
            boolean flag = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    if(s[(i + a) % n][j] != s[(j + a) % n][i]) flag = false;
            }
            if(flag) ans += n;
        }
        System.out.println(ans);
    }
}