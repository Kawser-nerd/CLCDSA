import java.util.*;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long W = sc.nextLong() - 1;
		long H = sc.nextLong() - 1;
		long mod = 1000000007;
		long num = conv(W + H, W, mod);
		System.out.println(num);
	}
	
	public static long conv(long m, long n, long mod) {
		long num = 1;
		for(int i = (int)n + 1; i <= (int)m; i++) {
			num = num * i % mod;
		}
		
		long num2 = 1;
		for(int i = 1; i <= m - n; i++) {
			num2 = num2 * i % mod;
		}
		
		BigInteger big2 = new BigInteger(String.valueOf(num2));
		BigInteger modb = new BigInteger(String.valueOf(mod));
		long ans = num * Long.parseLong(big2.modInverse(modb).toString()) % mod;
		return ans;
	}
}