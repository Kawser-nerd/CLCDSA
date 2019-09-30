import java.util.*;

public class Main{
	static long[] fact,ifact;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		
		long mod=1000000007;
		int size=1001000;
		fact=new long[size];
		ifact=new long[size];
		fact[0]=1;
		for(int i=1;i<size;i++) fact[i]=fact[i-1]*i%mod;
		ifact[size-1]=inv(fact[size-1],mod);
		for(int i=size-1;i>0;i--) ifact[i-1]=ifact[i]*i%mod;
		
		long res=0;
		long sum=0;
		for(int i=n/2;i<n;i++){
			long v=binom(i-1,n-i-1,mod)*fact[i]%mod*fact[n-i-1]%mod;
			res=(res+(v-sum+mod)%mod*i)%mod;
			sum=v;
		}
		System.out.println(res);
	}
	static long binom(int a,int b,long mod){
		if(a<b) return 0;
		return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
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
		return (p+mod)%mod;
	}
}