import java.util.*;
public class Main{
	static long Comb(long t, long r){
		r = Math.min(r, t-r);
		if(r==0)return 1;
		if(r==1)return t;
		long ans = (((Fact(t, 1000000007) * revFact(r, 1000000007)) % 1000000007) * revFact(t-r, 1000000007)) % 1000000007;
		return ans;
	}
 
	static long Fact(long n, long mod){
		long ans = 1;
		for(int i=1; i<=n; i++){
			ans = (ans * i) % mod;
		}
		return ans;
	}
 
	static long revFact(long n, long mod){
		long ans = PowMod(Fact(n, mod), mod-2, mod);
		return ans;
	}
 
	static long PowMod(long x, long n, long mod){
		long ans = 1;
		x = x % mod;
		while(n!=0){
			if(n%2==0){
				x = (x * x) % mod;
				n /= 2;
			}else{
				ans = (ans * x) % mod;
				n -= 1;
			}
		}
		return ans;
	}
 
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int p = 0;
		long ans = 1;
		if(m==1)ans = 1;
		else{
			int[] num = new int[30];
			int k = m;
			while(k%2==0){
				num[p]++;
				k /= 2;
			}
			p++;
			for(int i=3; i*i<=k; i+=2){
				while(k%i==0){
					num[p]++;
					k /= i;
				}
				if(num[p]!=0)p++;
			}
			if(k!=1)num[p]++;
			for(int i=0; i<=p; i++){
				ans = (Comb(num[i]+n-1, num[i]) * ans) % 1000000007;
			}
		}
		System.out.println(ans);
	}
}