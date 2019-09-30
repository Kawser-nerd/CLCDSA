import java.util.*;

class Main{
	static int mod=1000000007;
	static Scanner s=new Scanner(System.in);
	public static void main(String[]$){
		int n=s.nextInt()-1,m=s.nextInt()-1;
		long[]a=new long[n],b=new long[m];
		f(a);
		f(b);
		System.err.println(Arrays.toString(a));
		System.err.println(Arrays.toString(b));
		long A=g(n,a),B=g(m,b);
		System.out.println(A*B%mod);
	}
	static void f(long[]a){
		long p=s.nextLong();
		for(int i=0;i<a.length;++i) {
			long q=s.nextLong();
			a[i]=q-p;
			p=q;
		}
	}
	static long g(int n,long[]a){
		long A=0;
		for(int i=0;i<n;++i) {
			long p=Math.min(i,n-1-i);
			A+=((p+1)*p+(n-p*2)*(p+1))%mod*a[i];
			A%=mod;
		}
		return A;
	}
}