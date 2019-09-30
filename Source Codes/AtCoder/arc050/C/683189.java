import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long m = sc.nextLong();
		
		long g = gcd(a,b);
		System.out.println(onesModM(1,g,m) * onesModM(g,a/g,m) % m * onesModM(g,b/g,m) % m);
	}

	public static long onesModM(long a,long b,long m) {
		MatrixMod.MOD = m;
		MatrixMod x = new MatrixMod(new long[][] {{pow(10, a, m),1},{0,1}});
		x = x.pow(b);
		return x.e[0][1];
	}
	
	public static long gcd(long a,long b) {
		while(b!=0) {
			long r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	public static long lcm(long a,long b) {
		return a / gcd(a,b) * b;
	}
	public static long pow(long a,long n,long mod) {
		long res = 1;
		while(n > 0) {
			if ((n & 1) > 0) {
				res = (res * a) % mod;
			}
			a = (a * a) % mod;
			n/=2;
		}
		return res;
	}
}
class MatrixMod {
	public static long MOD = 2;
	long[][] e;
	int n,m;
	public MatrixMod(long[][] e) {
		this.e = e;
		this.n = e.length;
		this.m = e[0].length;
	}
	public static MatrixMod identity(int n) {
		long[][] e = new long[n][n];
		for(int i=0;i<n;i++) e[i][i] = 1;
		return new MatrixMod(e);
	}
	public static MatrixMod zero(int n,int m) {
		return new MatrixMod(new long[n][m]);
	}
	public static MatrixMod vector(long[] v) {
		long[][] e = new long[v.length][1];
		for(int i=0;i<v.length;i++) e[i][0] = v[i];
		return new MatrixMod(e);
	}
	public MatrixMod add(MatrixMod b) {
		long[][] c = new long[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				c[i][j] = e[i][j] + b.e[i][j];
				if (c[i][j] >= MOD) {
					c[i][j] -= MOD;
				}
			}
		}
		return new MatrixMod(c);
	}
	public MatrixMod multiply(long k) {
		k = (k%MOD+MOD)%MOD;
		long[][] c = new long[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				c[i][j] = e[i][j] * k % MOD;
			}
		}
		return new MatrixMod(c);
	}
	public MatrixMod multiply(MatrixMod b) {
		long[][] c = new long[n][b.m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<b.m;j++) {
				for(int k=0;k<m;k++) {
					c[i][j] = (c[i][j] + e[i][k] * b.e[k][j]) % MOD;
				}
			}
		}
		return new MatrixMod(c);
	}
	public MatrixMod pow(long exp) {
		MatrixMod ret = identity(n);
		MatrixMod x = this;
		while(exp > 0) {
			if ((exp & 1) != 0) {
				ret = ret.multiply(x);
			}
			x = x.multiply(x);
			exp >>>= 1;
		}
		return ret;
	}
	//O(n m^2)
	public int rank() {
		long[][] x = new long[n][];
		for(int i=0;i<n;i++) {
			x[i] = Arrays.copyOf(e[i], m);
		}
		int rank = 0;
		for(int j=0;j<m;j++) {
			int ind = -1;
			for(int i=rank;i<n;i++) {
				if (x[i][j] != 0) {
					ind = i;
					break;
				}
			}
			if (ind == -1) {
				continue;
			}
			long[] temp = x[ind];
			x[ind] = x[rank];
			x[rank] = temp;
			long a = inverse(x[rank][j], MOD);
			for(int k=j;k<m;k++) {
				x[rank][k] = x[rank][k] * a % MOD;
			}
			for(int i=rank+1;i<n;i++) {
				long b = (MOD - x[i][j]) % MOD;
				for(int k=j;k<m;k++) {
					x[i][k] = (x[rank][k] * b + x[i][k]) % MOD;
				}
			}
			rank++;
		}
		return rank;
	}
	public static long inverse(long a,long mod) {
		long b = mod, u = 1, v = 0;
		while(b > 0) {
			long temp;
			long t = a / b;
			a -= t * b;
			temp = a; a = b; b = temp;
			u -= t * v;
			temp = u; u = v; v = temp;
		}
		return (u % mod + mod) % mod;
	}
	public String toString() {
		return Arrays.deepToString(e);
	}
}