import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    static int mod=1000000007;
    public static void main(String[]$) {
        Scanner sc=new Scanner(in);
        double X=sc.nextDouble();
        double Y=sc.nextDouble();
        int n=sc.nextInt();
        double[] x=new double[n];
        double[] y=new double[n];
        for (int i = 0; i <n ; i++) {
            x[i]=sc.nextDouble();
            y[i]=sc.nextDouble();
        }
        double[] dist=new double[n];
        double ans=100000000;
        for (int i = 0; i <n ; i++) {
            double a=y[i]-y[(i+1+n)%n];
            double b=-x[i]+x[(i+1+n)%n];
            double c=-x[i]*a-y[i]*b;
            dist[i]=abs(a*X+b*Y+c)/sqrt(pow(a,2)+pow(b,2));
            ans=min(dist[i],ans);
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