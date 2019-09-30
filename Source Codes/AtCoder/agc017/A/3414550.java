import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int p=sc.nextInt();
        long M0=0,M1=0;
        for (int i = 0; i < n; i++) {
            if(sc.nextInt()%2==0)M0++;else M1++;
        }
        long ans=0;
        long temp=0;
        if(p==0){
            for (long i = 0; i <= M0; i++) {
                ans+=comb(M0,i);
            }
            long i=0;
            while(i*2<=M1){
                temp+=comb(M1,i*2);
                i++;
            }
        }else{
            long i=0;
            while(i*2+1<=M1){
                ans+=comb(M1,2*i+1);
                i++;
            }
            for (long j = 0; j <= M0; j++) {
                temp+=comb(M0,j);
            }
        }
        out.println(ans*temp);
    }
    static long comb(long a,long b){
        if(b==0)return 1;
        return comb(a-1,b-1)*a/b;
    }
}