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
            long j=max(0,(n*e-h-(b+e)*i+d+e)/(d+e));
            ans=min(ans,a*i+c*j);
        }
        out.println(ans);
    }
}