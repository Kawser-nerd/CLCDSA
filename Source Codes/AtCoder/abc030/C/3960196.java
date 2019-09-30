import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),m=sc.nextInt(),x=sc.nextInt(),y=sc.nextInt();
        int[] a=new int[n];
        int[] b=new int[m];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        for (int i = 0; i < m; i++) b[i] = sc.nextInt();
        int i=0,j=0,ans=0;
        long t=0;
        //ans:A?B??????????????????ans/2?
        boolean AorB=true;//A?????True
        while (i<n&&j<m){
            if(AorB){
                if(t<=a[i]){
                    t=a[i]+x;
                    i++;
                    ans++;
                }else{
                    while(i<n&&t>a[i]){
                        i++;
                    }
                    if(i<n){
                        t=a[i]+x;
                        ans++;
                    }
                }
                AorB=false;
            }else{
                if(t<=b[j]){
                    t=b[j]+y;
                    j++;
                    ans++;
                }else{
                    while(j<m&&t>b[j]){
                        j++;
                    }
                    if(j<m){
                        t=b[j]+y;
                        ans++;
                    }
                }
                AorB=true;
            }
        }
        out.println(ans/2);
    }
}