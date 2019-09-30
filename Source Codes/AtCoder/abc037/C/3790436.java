import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        long[] a=new long[n+1];
        for (int i = 1; i <=n; i++) {
            a[i]=sc.nextLong();
        }
        long ans=0;
        for (int i = 1; i <=n-k+1; i++) {
            for (int j = 0; j <k ; j++) {
                ans+=a[i+j];
            }
        }
        out.println(ans);
    }
    static long power(long x,int n){
        long mod=1000000007;
        long ans=1;
        while (n>0) {
            if((n&1)==1){
                ans=(ans*x)%mod;
            }
            x=(x*x)%mod;
            n>>=1;
        }
        return ans;
    }
    //?????
    static int gcd (int a,int b) {
        int temp;
        while((temp = a%b)!=0) {
            a = b;
            b = temp;
        }
        return b;
    }
    //???????a*b/gcd(a,b)???
    static class UF{
        static int size=51;
        static int[] par=new int[size];
        //???
        static void init(){
            for (int i = 1; i <size ; i++) {
                par[i]=i;
            }
        }
        //?????
        static int root(int x){
            if(par[x]==x){
                return x;
            }else{
                return par[x]=root(par[x]);
            }
        }
        //???????(?????????)??
        static boolean same(int x,int y){
            return root(x)==root(y);
        }
        //??
        static void unite(int x,int y){
            x=root(x);
            y=root(y);
            if(x==y)return;
            par[x]=y;
        }
    }
}