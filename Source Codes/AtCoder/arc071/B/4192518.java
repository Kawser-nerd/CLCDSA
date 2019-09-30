import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long mod=1000000007;
		int n=sc.nextInt(),m=sc.nextInt();
		long[] x=new long[n];
		for(int i=0;i<n;i++) x[i]=sc.nextLong();
		long[] y=new long[m];
		for(int i=0;i<m;i++) y[i]=sc.nextLong();
		
		long[] a=new long[n-1],b=new long[m-1];
		for(int i=0;i<n-1;i++){
			a[i]=x[i+1]-x[i];
		}
		for(int i=0;i<m-1;i++){
			b[i]=y[i+1]-y[i];
		}
		long res=cal(a)*cal(b)%mod;
		System.out.println(res);
	}
	static long cal(long[] a){
		long mod=1000000007;
		long res=0;
		for(int i=0;i<a.length;i++){
			long coef=(long)(i+1)*(a.length-i)%mod;
			res=(res+coef*a[i]%mod)%mod;
		}
		return res;
	}
}