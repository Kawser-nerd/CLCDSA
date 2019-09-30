/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import java.awt.*;
import java.awt.Graphics.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        long n=sc.nextLong();
        long h=sc.nextLong();
        long a=sc.nextLong();
        long b=sc.nextLong();
        long c=sc.nextLong();
        long d=sc.nextLong();
        long e=sc.nextLong();
        long ans=h-e*n>0?0:Long.MAX_VALUE;
        for (long i = 0; i <= n; i++) {
            if(n*e-h-(b+e)*i<0)continue;
            long j=(n*e-h-(b+e)*i)/(d+e)+1l;
            if(j>=0)ans=min(ans,a*i+c*j);
        }
        for (long j = 0; j < n + 1; j++) {
            if((n*e-h-(d+e)*j)<0)continue;
            long i=(n*e-h-(d+e)*j)/(b+e)+1l;
            if(i>=0)ans=min(ans,a*i+c*j);
        }
        for (long i = 0; i < n + 1; i++) {
            long f=h+i*b-(n-i)*e;
            if(f>0)ans=min(ans,a*i);
        }
        for (long i = 0; i < n + 1; i++) {
            long f=h+i*d-(n-i)*e;
            if(f>0)ans=min(ans,c*i);
        }
        out.println(ans);
    }
}