import java.util.*;

public class Main{

	static Scanner s=new Scanner(System.in);

	static int mod=998244353;

	public static void main(String[] $){
		int n=s.nextInt();
		long a=s.nextInt(),b=s.nextInt(),k=s.nextLong(),r=0,nCa[]=new long[n+1];
		
		nCa[0]=1;
		for(int i=1;i<=n;++i)
			nCa[i]=nCa[i-1]*(n-i+1)%mod*pow(i,mod-2)%mod;

		for(int i=0;i<=n;++i) {
			int l=(int)((k-a*i)/b);
			if((k-a*i)%b==0&&0<=l&&l<=n) {
				r+=nCa[i]*nCa[l];
				r%=mod;
			}
		}
		
		System.out.println(r);
	}
	static long pow(long n,long a){
		if(a==1)
			return n;
		if(a%2==0){
			long d=pow(n,a/2);
			return d*d%mod;
		}
		return n*pow(n,a-1)%mod;
	}
}