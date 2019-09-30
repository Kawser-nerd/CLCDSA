import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        long A=sc.nextLong()-1;
        long B=sc.nextLong();
        int[] a=new int[19];
        int[] b=new int[19];
        for (int i = 0; i < 19; i++) {
            a[18-i]=(int)(A%10);
            b[18-i]=(int)(B%10);
            A/=10;
            B/=10;
        }
        out.println(c(b)-c(a));
    }
    static long c(int[] a){
        long[][][] dp=new long[20][2][2];
        dp[0][0][0]=1;
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 2; j++) {
                int x=j==1?9:a[i];
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l <= x; l++) {
                        dp[i+1][j==1||l<x?1:0][l==4||l==9?1:k]+=dp[i][j][k];
                    }
                }
            }
        }
        return dp[19][0][1]+dp[19][1][1];
    }
}