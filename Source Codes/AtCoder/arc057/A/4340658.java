import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        long a=sc.nextLong();
        long k=sc.nextLong();
        if(k==0){
            out.println(2000000000000l-a);
        }else {
            long i=1;
            long t=a;
            while (t<2000000000000l){
                i++;
                t=exp(1+k,i-1)*a+(exp(1+k,i-1)-1)/k;
            }
            out.println(i-1);
        }
    }
    static long exp(long a,long n){
        if(n==0)return 1;
        if(n%2==0){
            long e=exp(a,n/2);
            return e*e;
        }
        return a*exp(a,n-1);
    }
}