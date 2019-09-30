import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        long n=sc.nextLong();
        long s=(long)sqrt(n)+1;
        int ans=100;
        for (long i = 1; i <= s; i++) {
            if(n%i==0)ans=min(F(i,n/i),ans);
        }
        out.println(ans);
    }
    static int F(long A,long B){
        return max(get(A),get(B));
    }
    static int get(long n){
        int c=1;
        while (n/10>0){
            c++;
            n/=10;
        }
        return c;
    }
}