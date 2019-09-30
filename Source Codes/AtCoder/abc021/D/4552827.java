import java.util.Scanner;
public class Main{
	static long ans;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n=sc.nextLong();
		long k=sc.nextLong();
		long mod=1000000007;
		ans=1;
		for(long i=0; i<n-1; i++){
			ans*=n-1+k-i;
			ans%=mod;
		}
		for(int i=2; i<=n-1; i++){
			pow(i,mod-2,mod);
		}
		System.out.println(ans);
	}
	public static void pow(long h, long e,long mod){
		while(e>0){
			if((e & 1)==1){
				ans*=h;
				ans%=mod;
			}
			e>>=1;
			h*=h;
			h%=mod;
		}
	}
}