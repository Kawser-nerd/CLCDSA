import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Map;
import java.util.Map.Entry;
import java.util.NoSuchElementException;
import java.util.Set;
import java.util.TreeMap;

class Chr {
	Map<Integer, Integer> val;
	static Integer[] ints = new Integer[5000];
	static {
		for (int i = 0; i < ints.length; i++) {
			ints[i] = new Integer(i);
		}
	}

	static Integer toInt(int i) {
		if (i >= 0 && i < 5000)
			return ints[i];
		return new Integer(i);
	}

	Chr(int c) {
		val = new TreeMap<Integer, Integer>();
		val.put(c, ints[1]);
	}

	Chr() {
		val = new TreeMap<Integer, Integer>();
	}

	Chr addEq(Chr x) {
//		Chr res = new Chr();
//		for (String base : val.keySet()) {
//			res.add(base, val.get(base));
//		}
		for (Integer base : x.val.keySet()) {
			add(base, x.val.get(base));
		}
		return this;
	}

	Chr subEq(Chr x) {
//		Chr res = new Chr();
//		for (String base : val.keySet()) {
//			res.add(base, val.get(base));
//		}
		for (Integer base : x.val.keySet()) {
			add(base, -x.val.get(base));
		}
		return this;
	}

	Chr mul(Chr x) {
		Chr res = new Chr();
		Set<Integer> basis1 = val.keySet();
		Set<Integer> basis2 = x.val.keySet();
		for (Integer base1 : basis1) {
			for (Integer base2 : basis2) {
				Integer base = toInt(base1.intValue() + base2.intValue());
//				char[] c = base.toCharArray();
//				Arrays.sort(c);
//				base = new String(c);
				res.add(base, val.get(base1).intValue() * x.val.get(base2).intValue());
			}
		}
		return res;
	}

	Chr negEq() {
//		Chr res = new Chr();
//		for (String base : val.keySet()) {
//			res.add(base, -val.get(base));
//		}
//		return res;
		for (Integer base : val.keySet()) {
			val.put(base, toInt(-val.get(base)));
		}
		return this;
	}

	private void add(Integer base, int coeff) {
		if (coeff != 0) {
			if (val.containsKey(base)) {
				int newCoeff = val.get(base).intValue() + coeff;
				if (newCoeff != 0) {
					val.put(base, toInt(newCoeff));
				} else {
					val.remove(base);
				}
			} else {
				val.put(base, toInt(coeff));
			}
		}
	}

	@Override
	public String toString() {
		String res = "";
		for (Entry<Integer, Integer> entry : val.entrySet()) {
			Integer base = entry.getKey();
			int coeff = entry.getValue();
			if (res.isEmpty())
				res += (coeff == 1 ? "" : coeff == -1 ? "-" : coeff + "*") + base;
			else
				res += (coeff == 1 ? " + " : coeff == -1 ? " - " : coeff > 0 ? " + " + coeff + "*" : " - " + (-coeff)
						+ "*")
						+ base;
		}
		return "[" + res + "]";
	}
}

public class Main {
	private static void solve() {
		int a = nei();
		int t = nei();
		int k = nei();
		int cities[][] = new int[a][];
		int nums[] = new int[a];
		for (int i = 0; i < a; i++) {
			int num = nei();
			nums[i] = num;
			cities[i] = new int[num];
			for (int j = 0; j < num; j++) {
				cities[i][j] = nei() - 1;
			}
		}
		int[][] costs = new int[t][t];
		int m = nei();
		int totalCost = 0;
		for (int i = 0; i < m; i++) {
			int i1 = nei() - 1;
			int i2 = nei() - 1;
			int cost = nei();
			totalCost += cost;
			costs[i1][i2] = cost;
			costs[i2][i1] = cost;
		}

		int po = 35576;
		int[] cs = new int[77 * 7];
		int[][] dp = new int[2][po];
		dp[0][0] = 1;

		// for each cities
		for (int i = 0; i < a; i++) {
			int num = nums[i]; // num towns

//
//
//
//
//
//
//
//			Chr[][] d = new Chr[num][num]; // vertex matrix
//			for (int i1 = 0; i1 < num; i1++) {
//				for (int i2 = 0; i2 < num; i2++) {
//					d[i1][i2] = new Chr();
//				}
//			}
//
//			// assign chars to each road
//			for (int i1 = 0; i1 < num; i1++) {
//				for (int i2 = i1 + 1; i2 < num; i2++) {
//					int c1 = cities[i][i1];
//					int c2 = cities[i][i2];
//					if (costs[c1][c2] != 0) {
//						Chr c = new Chr(costs[c1][c2]);
//						d[i1][i2].subEq(c);
//						d[i2][i1].subEq(c);
//						d[i1][i1].addEq(c);
//						d[i2][i2].addEq(c);
//					}
//				}
//			}
////			System.out.println("city" + i);
//			Chr trees = compDet(d, num - 1);
//			for (int j = 0; j < 77 * 7; j++) {
//				cs[j] = 0;
//			}
//			for (Integer tree : trees.val.keySet()) {
//				int cost = tree.intValue();
//				int times = trees.val.get(tree);
//				cs[cost] += times;
//			}
//
//
//
//
//

			for (int j = 0; j < 77 * 7; j++) {
				cs[j] = 0;
			}
			int[][] roads = new int[21][3];
			int numRoads = 0;
			for (int c1 = 0; c1 < num; c1++) {
				for (int c2 = c1 + 1; c2 < num; c2++) {
					int i1 = cities[i][c1];
					int i2 = cities[i][c2];
					if (costs[i1][i2] != 0) {
						roads[numRoads][0] = c1;
						roads[numRoads][1] = c2;
						roads[numRoads][2] = costs[i1][i2];
						numRoads++;
					}
				}
			}
			int max = 1 << numRoads;
			int[][] edges = new int[num][num + 1];
			boolean[] visited = new boolean[num];
			for (int j = 0; j < max; j++) {
				int bits = (j & 0x55555555) + (j >> 1 & 0x55555555);
				bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
				bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
				bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
				bits = (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
				if (bits != num - 1)
					continue;
				bits = j;
				for (int l = 0; l < num; l++) {
					edges[l][0] = 0;
					visited[l] = false;
				}
				for (int l = 0; l < numRoads; l++) {
					if ((bits >> l & 1) != 0) {
						int c1 = roads[l][0];
						int c2 = roads[l][1];
						edges[c1][++edges[c1][0]] = c2;
						edges[c2][++edges[c2][0]] = c1;
					}
				}
				dfs(0, visited, edges);
				boolean ok = true;
				for (int l = 0; l < num; l++) {
					if (!visited[l]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					int cost = 0;
					for (int l = 0; l < numRoads; l++) {
						if ((bits >> l & 1) != 0) {
							cost += roads[l][2];
						}
					}
					cs[cost]++;
				}
			}

			int from = i & 1;
			int to = from ^ 1;
			for (int j = 0; j < po; j++) {
				int sum = 0;
				for (int cost = 0; cost < 77 * 7; cost++) {
					if (j - cost >= 0)
						sum += dp[from][j - cost] * cs[cost];
				}
//				if (sum > 0) {
//					System.out.println("cost " + j + " = " + sum);
//				}
				if (sum > k)
					sum = k; // avoid overflow
				dp[to][j] = sum;
			}

			if (i == a - 1) {
				int left = k;
				for (int j = po - 1; j >= 0; j--) {
					left -= dp[to][j];
					if (left <= 0)
						kil(totalCost - j);
				}
				kil(-1);
			}
		}
	}

	static void dfs(int at, boolean[] visited, int[][] edges) {
		if (visited[at])
			return;
		visited[at] = true;
		for (int i = 0; i < edges[at][0]; i++) {
			dfs(edges[at][i + 1], visited, edges);
		}
	}

	static Chr[][][] scof = new Chr[][][] { null, new Chr[1][1], new Chr[2][2], new Chr[3][3], new Chr[4][4],
			new Chr[5][5], new Chr[6][6], };

	// danger: O(n!)
	private static Chr compDet(Chr[][] d, int n) {
		if (n == 1)
			return d[0][0];
		if (n == 2)
			return d[0][0].mul(d[1][1]).subEq(d[0][1].mul(d[1][0]));
		Chr det = new Chr();
		Chr[][] cof = scof[n - 1]; //new Chr[n - 1][n - 1];
		for (int i = 0; i < n; i++) {
			if (d[i][0].val.isEmpty())
				continue;
			int ci = 0;
			for (int i2 = 0; i2 < n; i2++) {
				if (i == i2)
					continue;
				int cj = 0;
				for (int j2 = 1; j2 < n; j2++) {
					cof[ci][cj] = d[i2][j2];
					cj++;
				}
				ci++;
			}
			Chr c = d[i][0].mul(compDet(cof, n - 1));
			if (i % 2 == 1)
				det.subEq(c);
			else
				det.addEq(c);
		}
		return det;
	}

	// returns (x, y, d) s.t. ax + by = d
	static long[] exgcd(long a, long b) {
		int sa = a < 0 ? -1 : 1;
		int sb = b < 0 ? -1 : 1;
		a *= sa;
		b *= sb;
		long x = 1;
		long y = 0;
		long z = 0;
		long w = 1;
		while (b > 0) {
			long q = a / b;
			long t = z;
			z = x - q * z;
			x = t;
			t = w;
			w = y - q * w;
			y = t;
			t = b;
			b = a - q * b;
			a = t;
		}
		return new long[] { x * sa, y * sb, a };
	}

	static int[] lis(int[] s) {
		int n = s.length;
		int[] dp = new int[n];
		int[] ids = new int[n];
		int[] pids = new int[n];
		dp[0] = s[0];
		int len = 1;
		int lidx = 0;
		for (int i = 1; i < n; i++) {
			int idx = bs(s[i], dp, 0, len);
			dp[idx] = s[i];
			ids[idx] = i;
			if (idx == len) {
				lidx = i;
				len++;
			}
			if (idx > 0)
				pids[i] = ids[idx - 1];
		}
		int[] lis = new int[len];
		lis[len - 1] = s[lidx];
		for (int i = len - 1; i >= 0; i--) {
			lis[i] = s[lidx];
			lidx = pids[lidx];
		}
		return lis;
	}

	static int bs(int a, int[] as, int from, int num) {
		int min = from;
		int max = from + num - 1;
		while (min < max) {
			int mid = min + max >> 1;
			if (as[mid] < a)
				min = mid + 1;
			else if (as[mid] > a)
				max = mid;
			else
				return mid;
		}
		return as[min] < a ? min + 1 : min;
	}

	static int gcd(int x, int y) {
		x = (x ^ x >> 31) - (x >> 31);
		y = (y ^ y >> 31) - (y >> 31);
		if (x < y) {
			x ^= y;
			y ^= x;
			x ^= y;
		}
		int z = x % y;
		if (z == 0)
			return y;
		return gcd(y, z);
	}

	static long gcd(long x, long y) {
		x = (x ^ x >> 63) - (x >> 63);
		y = (y ^ y >> 63) - (y >> 63);
		if (x < y) {
			x ^= y;
			y ^= x;
			x ^= y;
		}
		long z = x % y;
		if (z == 0)
			return y;
		return gcd(y, z);
	}

	static long modinv(long a, long mod) {
		return modpow(a, mod - 2, mod);
	}

	static long modpow(long a, long b, long mod) {
		if (b == 0)
			return 1;
		if ((b & 1) == 0) {
			long sqrt = modpow(a, b >> 1, mod);
			return sqrt * sqrt % mod;
		}
		return a * modpow(a, b - 1, mod) % mod;
	}

	static long fact(long n) {
		if (n <= 1)
			return 1;
		long res = 2;
		for (long i = 3; i <= n; i++) {
			res *= i;
		}
		return res;
	}

	static long modfact(long n, long mod) {
		if (n <= 1)
			return 1 % mod;
		long res = 2;
		for (long i = 3; i <= n; i++) {
			res *= i;
			res %= mod;
		}
		return res % mod;
	}

	// returns facts([0]) and invfacts([1])
	static long[][] enumfacts(int n, long mod) {
		int num = n + 10;
		long[][] res = new long[2][num];
		long[] facts = res[0];
		long[] invfacts = res[1];
		for (int i = 0; i < num; i++) {
			if (i <= 1) {
				facts[i] = 1;
				invfacts[i] = 1;
			} else {
				facts[i] = facts[i - 1] * i % mod;
				invfacts[i] = modinv(facts[i], mod);
			}
		}
		return res;
	}

	static long modcomb(long n, long m, long mod) {
		if (m > n)
			return 0;
		if (m > n - m) {
			m = n - m;
		}
		long numer = 1;
		for (int i = 0; i < m; i++) {
			numer = numer * (n - i) % mod;
		}
		long denom = modfact(m, mod);
		return numer * denom % mod;
	}

	static long modcomb(int n, int m, long[] facts, long[] invfacts, long mod) {
		if (m > n)
			return 0;
		long numer = facts[n];
		long denom = invfacts[m] * invfacts[n - m] % mod;
		return numer * denom % mod;
	}

	// res[i][0]: prime factor, res[i][1]: exponent
	static int[][] factorize(int n) {
		int[][] pfs = new int[32][2];
		int num = 0;
		for (int i = 2; i * i <= n; i++) {
			int count = 0;
			while (n % i == 0) {
				n /= i;
				count++;
			}
			if (count > 0) {
				pfs[num][0] = i;
				pfs[num][1] = count;
				num++;
			}
		}
		if (n > 1) {
			pfs[num][0] = n;
			pfs[num][1] = 1;
			num++;
		}
		int[][] res = new int[num][2];
		for (int i = 0; i < num; i++) {
			res[i][0] = pfs[i][0];
			res[i][1] = pfs[i][1];
		}
		return res;
	}

	static long lcm(long x, long y) {
		x = (x ^ x >> 63) - (x >> 63);
		y = (y ^ y >> 63) - (y >> 63);
		return x / gcd(x, y) * y;
	}

	static int abs(int x) {
		return x < 0 ? -x : x;
	}

	static long abs(long x) {
		return x < 0 ? -x : x;
	}

	static int min(int a, int b) {
		return a < b ? a : b;
	}

	static long min(long a, long b) {
		return a < b ? a : b;
	}

	static int max(int a, int b) {
		return a > b ? a : b;
	}

	static long max(long a, long b) {
		return a > b ? a : b;
	}

	static int clamp(int a, int min, int max) {
		return a < min ? min : a > max ? max : a;
	}

	static long clamp(long a, long min, long max) {
		return a < min ? min : a > max ? max : a;
	}

	static void out(String val) {
		IO.out(val);
	}

	static void out(Object val) {
		IO.out(String.valueOf(val));
	}

	static void out(int val) {
		IO.out(String.valueOf(val));
	}

	static void out(long val) {
		IO.out(String.valueOf(val));
	}

	static void out(char val) {
		IO.out(String.valueOf(val));
	}

	static void out(float val) {
		IO.out(String.valueOf(val));
	}

	static void out(double val) {
		IO.out(String.valueOf(val));
	}

	static void out(boolean val) {
		IO.out(String.valueOf(val));
	}

	static void kil(String val) {
		IO.out(val);
		IO.flush();
		System.exit(0);
	}

	static void kil(Object val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(int val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(long val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(char val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(float val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(double val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(boolean val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static String nes() {
		return IO.next();
	}

	static int nei() {
		return IO.nextInt();
	}

	static long nel() {
		return IO.nextLong();
	}

	static double ned() {
		return IO.nextDouble();
	}

	static char nec() {
		return IO.nextChar();
	}

	static String[] nss(int n) {
		String[] as = new String[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.next();
		}
		return as;
	}

	static int[] nis(int n) {
		int[] as = new int[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextInt();
		}
		return as;
	}

	static long[] nls(int n) {
		long[] as = new long[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextLong();
		}
		return as;
	}

	static double[] nds(int n) {
		double[] as = new double[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextDouble();
		}
		return as;
	}

	static char[] ncs(int n) {
		char[] as = new char[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextChar();
		}
		return as;
	}

	static String[][] nss2(int n, int m) {
		String[][] as = new String[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.next();
			}
		}
		return as;
	}

	static int[][] nis2(int n, int m) {
		int[][] as = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextInt();
			}
		}
		return as;
	}

	static long[][] nls2(int n, int m) {
		long[][] as = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextLong();
			}
		}
		return as;
	}

	static double[][] nds2(int n, int m) {
		double[][] as = new double[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextDouble();
			}
		}
		return as;
	}

	static char[][] ncs2(int n, int m) {
		char[][] as = new char[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextChar();
			}
		}
		return as;
	}

	static int parseInt(String val) {
		return Integer.parseInt(val);
	}

	static int parseInt(char val) {
		return Integer.parseInt(String.valueOf(val));
	}

	static long parseLong(String val) {
		return Long.parseLong(val);
	}

	public static void main(String[] args) {
		try {
			solve();
			IO.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

final class IO {
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out, false);
	private static final byte[] buffer = new byte[1024];
	private static int ptr = 0;
	private static int len = 0;

	private static boolean hasNextByte() {
		if (ptr < len)
			return true;
		ptr = 0;
		try {
			len = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return len > 0;
	}

	private static int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	static boolean hasNext() {
		byte c;
		while (hasNextByte() && ((c = buffer[ptr]) < '!' || c > '~'))
			ptr++;
		return hasNextByte();
	}

	static String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (b >= '!' && b <= '~') {
			sb.append((char) b);
			b = readByte();
		}
		return sb.toString();
	}

	static char nextChar() {
		if (!hasNext())
			throw new NoSuchElementException();
		return (char) readByte();
	}

	static long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		int sign = 1;
		int b = readByte();
		if (b == '-') {
			sign = -1;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
		while (true) {
			if ('0' <= b && b <= '9')
				n = n * 10 + b - '0';
			else if (b == -1 || b < '!' || b > '~')
				return n * sign;
			else
				throw new NumberFormatException();
			b = readByte();
		}
	}

	static int nextInt() {
		if (!hasNext())
			throw new NoSuchElementException();
		int n = 0;
		int sign = 1;
		int b = readByte();
		if (b == '-') {
			sign = -1;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
		while (true) {
			if ('0' <= b && b <= '9')
				n = n * 10 + b - '0';
			else if (b == -1 || b < '!' || b > '~')
				return n * sign;
			else
				throw new NumberFormatException();
			b = readByte();
		}
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static void out(String val) {
		out.println(val);
	}

	static void flush() {
		out.flush();
	}
}