import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long w = sc.nextLong();
		long h = sc.nextLong();
		long a = 1;
		long b = 1;
		int mod = 1000000007;
		for(int i = 1; i<h; i++){
			a=a*(w-1+i)%mod;
			b=b*i%mod;
		}
		long ans = a*(func(b,mod-2,mod))%mod;
		System.out.println(ans);
	}
	public static long func(long a,long b,long mod){
		if(b==0){
			return 1;
		}
		if(b%2==0){
			return func(a*a%mod,b/2,mod);
		}else{
			return a*func(a,b-1,mod)%mod;
		}
	}
}