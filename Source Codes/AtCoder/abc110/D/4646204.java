import java.util.Scanner;
public class Main{
	static long mod;
	static long ans;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		long m=sc.nextLong();
		mod=1000000007;
		ans=1;
		for(long i = 2; i<=m; i++){
			long count=0;
			while(m%i==0){
				m/=i;
				count++;
			}
			if(count>0){
				for(long j=1; j<=count; j++){
					ans*=((n+count-j)%mod);
					ans%=mod;
				}
				for(long k=2; k<=count; k++){
					pow(k,mod-2);
				}
			}
		}
		System.out.println(ans);
	}
	public static void pow(long a,long p){
		while(p>0){
			if((p & 1)==1){
				ans*=a;
				ans%=mod;
			}
			
			a*=a;
			a%=mod;
			p>>=1;
		}
	}
}