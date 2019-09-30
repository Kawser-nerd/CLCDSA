import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),m=sc.nextInt();
        int[][] d=new int[n+1][n+1];
        int inf=100;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                d[i][j]=inf;
            }
        }
        for (int i = 0; i < m; i++) {
            int a=sc.nextInt(),b=sc.nextInt();
            d[a][b]=d[b][a]=1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if(d[j][k]>d[j][i]+d[i][k]){
                        d[j][k]=d[j][i]+d[i][k];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int ans=0;
            for (int j = 1; j <= n; j++) {
                if(j!=i&&d[i][j]==2){
                    ans++;
                }
            }
            out.println(ans);
        }
    }
}