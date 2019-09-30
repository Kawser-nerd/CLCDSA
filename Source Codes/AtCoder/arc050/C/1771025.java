import java.util.*;

class Main {
    static long gcd(long x,long y){
        return y==0?x:gcd(y,x%y);
    }
    static long powerMod(long x, long exponent,long m) {
	long prod = 1;
	for (int i = 63; i >= 0; --i) {
	    prod = (prod * prod) % m;
	    if ((exponent & 1L << i) != 0) {
		prod = (prod * x) % m;
	    }
	}
	return prod;
    }
    // 1+x+...+x^(y-1) mod m
    static long f(long x,long y,long m){
        long oy=y;
        long t=0;
        long c=x;
        long s=1;
        while(y>0){
            if(y%2==1){
                t=(t+s)%m;
                s=s*((c+c*c)%m)%m;
            }else
                s=s*(1+c)%m;
            c=c*c%m;
            y/=2;
        }
        return t;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long a=scan.nextLong();
        long b=scan.nextLong();
        long m=scan.nextLong();
        long g=gcd(a,b);
        long t=f(10,g,m);
        t=t*f(powerMod(10,g,m),a/g,m)%m;
        t=t*f(powerMod(10,g,m),b/g,m)%m;
        System.out.println(t);
    }
}