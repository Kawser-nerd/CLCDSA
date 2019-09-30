import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int[] a=new int[n+1];
        int[] t=new int[n+1];
        for (int i = 1; i <= n; i++) {
            int k=sc.nextInt();
            if(i%2==0)a[i]=k;
            else t[i]=k;
        }
        for (int i = 1; i <= n; i++) {
            a[i]+=a[i-1];
            t[i]+=t[i-1];
        }
        int takScore=Integer.MIN_VALUE,ans=Integer.MIN_VALUE;
        for (int tak = 1; tak <= n; tak++) {
            int aokScore=Integer.MIN_VALUE,c=0;
            for (int aok = n; aok > 0; aok--) {
                int A=0,T=0;
                if(min(tak,aok)%2==1){
                    A=a[max(aok,tak)]-a[min(aok,tak)-1];
                    T=t[max(aok,tak)]-t[min(aok,tak)-1];
                }else {
                    A=t[max(aok,tak)]-t[min(aok,tak)-1];
                    T=a[max(aok,tak)]-a[min(aok,tak)-1];
                }
                if(A>=aokScore&&aok!=tak){
                    aokScore=A;
                    takScore=T;
                    c++;
                }
            }
            if(c>0)ans=max(takScore,ans);
        }
        out.println(ans);
    }
}