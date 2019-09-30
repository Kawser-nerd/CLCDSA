import java.util.Scanner;
public class Main{
	static long ans;
	public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
		int n = sc.nextInt();
		long m = sc.nextLong();
		ans=1;
		long mod=1000000007;
		for(long i = 2; i<=m; i++){
			long o=0;
			while(m%i==0){
				m/=i;
				o++;
			}
			if(o!=0){
				for(long j = 1; j<=o;j++){
					ans*=((o+n-j)%mod);
					ans%=mod;
				}
				for(long h=2; h<=o; h++){
					pow(h,mod-2,mod);
					ans%=mod;
				}
			}
		}
		System.out.println(ans);
	}
	public static void pow(long h,long e,long mod){
		while(e>0){
			if((e & 1)==1){
				ans*=h;
				ans%=mod;
			}
			h*=h;
			h%=mod;
			e>>=1;
		}
	}
}