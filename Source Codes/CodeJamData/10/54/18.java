import java.util.*;

public class Main {
	static final Scanner in = new Scanner(System.in);
	static final long MOD = 1000000007;
	static int b;
	static class Statement implements Comparable<Statement> {
		final long n;
		final int k;
		Statement(long n, int k) {
			this.n = n;
			this.k = k;
		}
		public int compareTo(Statement r) {
			if(r.n!=this.n) return (int)((this.n-r.n)/Math.abs(this.n-r.n));
			return this.k-r.k;
		}
	}
	static TreeMap<Statement, Integer> map;
	static int f(Statement s) {
		if(s.n==0l&&s.k==0) return 1;
		if(s.n<=0l||s.k<=0) return 0;
		if(map.containsKey(s)) return map.get(s);
		long ans = 0l;
		for(int i=0; i<=s.k; ++i) {
			for(int j=(int)(s.n%b); j<nums[b-1][s.k].length; j+=b) {
				ans = (ans + 1L * c[s.k][s.k-i] * nums[b-1][s.k][j] % MOD * f(new Statement((s.n-j)/b, s.k-i)))%MOD;
			}
		}
		for(int i=0; i<s.k; ++i) {
			for(int j=(int)(s.n%b); j<nums[b-1][s.k-1].length; j+=b) {
				ans = (ans + 1L * c[s.k-1][s.k-i-1] * (s.k-i) % MOD * nums[b-1][s.k-1][j] % MOD * f(new Statement((s.n-j)/b, s.k-i)))%MOD;
			}
		}
		map.put(s, (int)ans);
		return (int)ans;
	}
	static int[][][] nums = new int[71][71][4901];
	static int[][] c = new int[71][71];
	static {
		nums[0][0][0] = 1;
		for(int i=1; i<=70; ++i) {
			for(int j=0; j<=i; ++j) {
				for(int k=0; k<=i*(i+1)/2; ++k) {
					nums[i][j][k] = nums[i-1][j][k];
					if(j>=1&&k>=i)
						nums[i][j][k] += nums[i-1][j-1][k-i];
					nums[i][j][k] %= MOD;
				}
			}
		}
		for(int i=0; i<=70; ++i) {
			c[i][0] = 1;
			for(int j=1; j<=i; ++j) {
				c[i][j] = (int)(1l*c[i-1][j-1]*i%MOD);
			}
		}
	}
	public static void main(String[] args) {
		int t = in.nextInt();
		for(int ca=1; ca<=t; ++ca) {
			map = new TreeMap<Statement, Integer>();
			long n = in.nextLong();
			b = in.nextInt();
			long ans = 0l;
			for(int i=1; i<=b; ++i)
				ans = (ans + f(new Statement(n, i)))%MOD;
			for(Statement s: map.keySet()) {
				//System.err.println(""+s.n+" "+s.k+": "+map.get(s));
			}
			//System.err.println(nums[b][1][0]);
			System.out.println("Case #"+ca+": "+ans);
		}
	}
}

