import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), ans = 0;
        int[] a = new int[m], b = new int[m];
        for(int i = 0; i < m; i++){
            a[i] = sc.nextInt() - 1;
            b[i] = sc.nextInt() - 1;
        }
        for(int x = 0; x < m; x++){
            boolean[][] bl = new boolean[n][n];
            for(int i = 0; i < m; i++)
                if(i != x)
                    bl[a[i]][b[i]] = true;
            for(int k = 0; k < n; k++)
                for(int from = 0; from < n; from++)
                    for(int to = from + 1; to < n; to++)
                            if(bl[Math.min(k, from)][Math.max(k, from)] && bl[Math.min(k, to)][Math.max(k, to)])
                                bl[from][to] = true;
            boolean flag = true;
            for(int from = 0; from < n; from++)
                for(int to = from + 1; to < n; to++)
                    if(!bl[from][to])
                        flag = false;
            if(!flag)
                ans++;
        }
        System.out.println(ans);
    }
}