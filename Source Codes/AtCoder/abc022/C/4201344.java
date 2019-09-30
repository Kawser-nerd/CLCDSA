/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n= sc.nextInt(),m=sc.nextInt();
        Point[] road=new Point[m];
        long[] dist=new long[m];
        long[][] d=new long[n+1][n+1];
        ArrayList<Integer> list=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt(),v=sc.nextInt();
            long l=sc.nextLong();
            d[u][v]=d[v][u]=l;
            if(u==1)list.add(v);
        }
        long inf=Integer.MAX_VALUE;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= n; j++) {
                for (int k = 2; k <= n; k++) {
                    if(d[j][k]==0)d[j][k]=inf;
                    if(d[j][i]==0)d[j][i]=inf;
                    if(d[i][k]==0)d[i][k]=inf;
                    if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
                }
            }
        }
        long ans=Long.MAX_VALUE;
        for (Integer s:list){
            for (Integer g:list){
                if(s==g)break;
                long distance=d[1][s]+d[s][g]+d[g][1];
                /*
                out.println(s+"?"+g);
                out.println(1+"?"+s+":"+d[1][s]);
                out.println(s+"?"+g+":"+d[s][g]);
                out.println(g+"?"+1+":"+d[g][1]);
                out.println(distance);
                */
                ans=min(ans,distance);
            }
        }
        out.println(ans>Integer.MAX_VALUE?-1:ans);
    }
}