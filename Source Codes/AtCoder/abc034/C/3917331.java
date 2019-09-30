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
		long ans = a*(pow(b,mod-2,mod))%mod;
		System.out.println(ans);
	
	}
	public static long pow(long a, long b, long mod){
		long sum = 1;
		while(b>0){
			if((b & 1)==1){
				
				sum*=a;
				sum%=mod;
			}
			
			a*=a;
			a%=mod;
			b >>= 1;
		}
		return sum;
	}
}