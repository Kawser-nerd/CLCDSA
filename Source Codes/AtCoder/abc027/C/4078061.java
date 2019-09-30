import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        long[] a=new long[61];
        for(int i=0;i<61;i++){
            a[i]=power(2,i);
        }
        long n=sc.nextLong();
        int exponent=0;
        while(n/a[exponent]>0)exponent++;
        exponent--;
        int count=0;
        long t=1;
        while (t<=n){
            if(exponent%2==1){
                if(count%2==0)t=right(t);
                else t=left(t);
            }else{
                if(count%2==0)t=left(t);
                else t=right(t);
            }
            count++;
        }
        String[] ans={"Aoki","Takahashi"};
        out.println(ans[(count+1)%2]);
    }
    static long power(long x,int n){
        if(n==0)return 1;
        if(n%2==0){
            long e=power(x,n/2);
            return (e*e);
        }
        long e=(x*power(x,n-1));
        return e;
    }
    static long right(long a){
        return a*2;
    }
    static long left(long a){
        return a*2+1;
    }
}