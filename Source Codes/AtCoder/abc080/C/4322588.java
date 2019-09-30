import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int[][] f=new int[n][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                f[i][j]=sc.nextInt();
            }
        }
        int[][] p=new int[n][11];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                p[i][j]=sc.nextInt();
            }
        }
        long ans=Long.MIN_VALUE;
        for (int i = 1; i < (1<<10); i++) {
            long temp=0;
            int[] c=new int[n];
            for (int j = 0; j < 10; j++) {
                if((1&(i>>j))==1){
                    for (int k = 0; k < n; k++) {
                        c[k]+=f[k][j];
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                temp+=p[j][c[j]];
            }
            ans=max(ans,temp);
        }
        out.println(ans);
    }
}