import java.util.*;

public class Main{
	static long mod=998244353;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] x=new long[n],y=new long[n];
		for(int i=0;i<n;i++){
			x[i]=sc.nextLong();
			y[i]=sc.nextLong();
		}
		
		long res=modPow(2,n,mod)-1-n;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int count=0;
				for(int k=0;k<n;k++){
					if(((x[i]-x[k])*(y[j]-y[k]))==((x[j]-x[k])*(y[i]-y[k]))) count++;
				}
				long kumi=modPow(2,count,mod)-1-count;
				kumi=kumi*inv(count*(count-1)/2,mod)%mod;
				res=(res-kumi+mod)%mod;
			}
		}
		System.out.println(res);
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=res*c%mod;
			c=c*c%mod;
			b/=2;
		}
		return res;
	}
	static long inv(long a,long mod){
		long b=mod;
		long p=1,q=0;
		while(b>0){
			long c=a/b;
			long d=a;
			a=b;
			b=d%b;
			d=p;
			p=q;
			q=d-c*q;
		}
		return (mod+p)%mod;
	}
}