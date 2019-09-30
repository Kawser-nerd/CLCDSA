import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		long mod = (long)Math.pow(10, 9)+7;
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int d = sc.nextInt();
		int l = sc.nextInt();
		sc.close();

		int num = (r-x+1) * (c-y+1);
		combination comb = new combination(x*y, mod);

		long num2;
		if(x*y == d+l) {
			num2 = comb.calc(x*y, d);
		} else {
			num2 = comb.calc(x*y, d+l);
			long case1 = comb.calc((x-1)*y, d+l);
			long case2 = comb.calc(x*(y-1), d+l);
			long case3 = case1;
			long case4 = case2;
			long case12 = comb.calc((x-1)*(y-1), d+l);
			long case13 = comb.calc((x-2)*y, d+l);
			long case14 = case12;
			long case23 = case12;
			long case24 = comb.calc(x*(y-2), d+l);
			long case34 = case12;
			long case123 = comb.calc((x-2)*(y-1), d+l);
			long case234 = comb.calc((x-1)*(y-2), d+l);
			long case341 = case123;
			long case412 = case234;
			long case1234 = comb.calc((x-2)*(y-2), d+l);
			num2 = num2
					- (case1+case2+case3+case4)
					+ (case12+case13+case14+case23+case24+case34)
					- (case123+case234+case341+case412)
					+ (case1234);
			while(num2<0)
				num2 += mod;
			num2 = num2 % mod * comb.calc(d+l, d) % mod;
		}
		System.out.println(num2*num%mod);
	}
}

class combination {

	/** ?? */
	long[] factorial;
	long[] inverse;
	long mod;

	public combination(int max, long mod) {
		this.factorial = new long[max+1];
		this.inverse = new long[max+1];
		this.mod = mod;

		factorial[0]=1;
		inverse[0]=1;

		for(int i=1; i<=max; i++) {
			factorial[i] = (factorial[i-1]*i)%mod;
			inverse[i] = pow(factorial[i], (int)mod-2)%mod;
		}
	}

	long pow(long x, int n) {
		long ans = 1;
		while(n > 0) {
			if((n&1)==1) {
				ans = ans * x % mod;
			}
			x = x*x%mod;
			n >>= 1;
		}
		return ans;
	}

	long calc(int n, int k) {
		return n >= k ? factorial[n] * inverse[k] % mod * inverse[n-k] % mod : 0;
	}
}