import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int ans=Integer.MAX_VALUE;
        int s1=n/6,s2=n/9;
        int[] TS=new int[n+10];
        int[] TN=new int[n+10];
        for (int i = 0; i <= n; i+=6) {
            int temp=i;
            while (temp/6>0){
                temp/=6;
                TS[i]+=temp%6;
            }
            for (int j = 0; j < 6; j++) {
                if(i+j<=n)TS[i+j]=TS[i]+j;
            }
        }
        for (int i = 0; i <= n; i+=9) {
            int temp=i;
            while (temp/9>0){
                temp/=9;
                TN[i]+=temp%9;
            }
            for (int j = 0; j < 9; j++) {
                if(i+j<=n)TN[i+j]=TN[i]+j;
            }
        }
        for (int i = 0; i <= s1; i++) {
            for (int j = 0; j <= s2; j++) {
                int six=6*i;
                int nine=9*j;
                if(i*6+j*9<=n){
                    ans=min(ans,TS[six]+TN[nine]+n-six-nine);
                }
            }
        }
        out.println(ans);
    }
}