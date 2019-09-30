/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        long x=sc.nextLong();
        long[] a=new long[51];
        a[0]=1;
        long[] p=new long[51];
        p[0]=1;
        for (int i = 0; i < 50; i++) {
            a[i+1]=2*a[i]+3;
            p[i+1]=2*p[i]+1;
        }
        out.println(f(a,p,n,x));
    }
    static long f(long[] a,long[] p,int n,long x){
        if(x==1)return n>0?0:1;
        if(x==3+2*a[n-1])return p[n-1]*2+1;
        if(x==a[n-1]+2)return p[n-1]+1;
        if(1<x&&x<=a[n-1]+1)return f(a,p,n-1,x-1);
        return p[n-1]+1+f(a,p,n-1,x-a[n-1]-2);
    }
}