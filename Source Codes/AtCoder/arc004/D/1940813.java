import java.util.Arrays;

public class Main {

	static int[] primes = sieveAtkin(100000);
	private static void solve() {
		long n = nl();
		long m = nl();

		if (m == 1) {
			System.out.println(1);
			return;
		}
		int mod = (int)1e9 + 7;

		long[][] f = factorize(Math.abs(n), primes);
		int[][] fif = enumFIF(200000, mod);
		
		long ret = 1;
		for (long[] v : f) {
			ret *= CX(m + v[1] - 1, v[1], mod, fif);
			ret %= mod;
		}
		long ret2 = 0;
		for (int i = n < 0 ? 1 : 0; i <= m; i += 2) {
			ret2 += CX(m, i, mod, fif);
			ret2 %= mod;
		}
		System.out.println(ret * ret2 % mod);
	}

	public static long[][] factorize(long n, int[] primes) {
		int rp = (int)Math.sqrt(n);
		long[][] factors = new long[100][2];
		int idx = 0;
		for (int i = 0; primes[i] <= rp; i ++) {
			int p = primes[i];
			int count = 0;
			while (n % p == 0) {
				count ++;
				n /= p;
			}
			if (count > 0) {
				factors[idx][0] = p;
				factors[idx][1] = count;
				idx ++;
			}
			if (n == 1) {
				break;
			}
		}
		if (n != 1) {
			factors[idx][0] = n;
			factors[idx][1] = 1;
			idx ++;
		}

		return Arrays.copyOf(factors, idx);
	}
	
	public static long CX(long n, long r, int p, int[][] fif)
	{
		if(n < 0 || r < 0 || r > n)return 0;
		int np = (int)(n%p), rp = (int)(r%p);
		if(np < rp)return 0;
		if(n == 0 && r == 0)return 1;
		int nrp = np-rp;
		if(nrp < 0)nrp += p;
		return (long)fif[0][np]*fif[1][rp]%p*fif[1][nrp]%p*CX(n/p, r/p, p, fif)%p;
	}
	
	public static int[][] enumFIF(int n, int mod)
	{
		int[] f = new int[n+1];
		int[] invf = new int[n+1];
		f[0] = 1;
		for(int i = 1;i <= n;i++){
			f[i] = (int)((long)f[i-1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
		}
		invf[n] = (int)(p < 0 ? p + mod : p);
		for(int i = n-1;i >= 0;i--){
			invf[i] = (int)((long)invf[i+1] * (i+1) % mod);
		}
		return new int[][]{f, invf};
	}
	
	public static int[] sieveAtkin(int size) {
		boolean[] isPrime = new boolean[size + 1];
		int sqrtN = (int) Math.sqrt(size);
		int n;
		for (int x = 1; x <= sqrtN; ++x) {
			for (int y = 1; y <= sqrtN; ++y) {
				n = 4 * x * x + y * y;
				if (n <= size && (n % 12 == 1 || n % 12 == 5)) {
					isPrime[n] = !isPrime[n];
				}
				n = 3 * x * x + y * y;
				if (n <= size && n % 12 == 7) {
					isPrime[n] = !isPrime[n];
				}
				n = 3 * x * x - y * y;
				if (x > y && n <= size && n % 12 == 11) {
					isPrime[n] = !isPrime[n];
				}
			}
		}

		for (n = 5; n <= sqrtN; ++n) {
			if (isPrime[n]) {
				for (int k = n * n; k <= size; k += n * n) {
					isPrime[k] = false;
				}
			}
		}
		isPrime[2] = isPrime[3] = true;
		
		int[] ret = new int[size];
		int count = 0;
		for (int i = 1; i < size; i ++) {
			if (isPrime[i]) {
				ret[count ++] = i;
			}
		}
		return Arrays.copyOf(ret, count);
	}
	
	public static void main(String[] args) {
		new Thread(null, new Runnable() {
			@Override
			public void run() {
				long start = System.currentTimeMillis();
				String debug = args.length > 0 ? args[0] : null;
				if (debug != null) {
					try {
						is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
					} catch (Exception e) {
						throw new RuntimeException(e);
					}
				}
				reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
				solve();
				out.flush();
				tr((System.currentTimeMillis() - start) + "ms");
			}
		}, "", 64000000).start();
	}

	private static java.io.InputStream is = System.in;
	private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
	private static java.util.StringTokenizer tokenizer = null;
	private static java.io.BufferedReader reader;

	public static String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new java.util.StringTokenizer(reader.readLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	private static double nd() {
		return Double.parseDouble(next());
	}

	private static long nl() {
		return Long.parseLong(next());
	}

	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private static char[] ns() {
		return next().toCharArray();
	}

	private static long[] nal(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nl();
		return a;
	}

	private static int[][] ntable(int n, int m) {
		int[][] table = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				table[i][j] = ni();
			}
		}
		return table;
	}

	private static int[][] nlist(int n, int m) {
		int[][] table = new int[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				table[j][i] = ni();
			}
		}
		return table;
	}

	private static int ni() {
		return Integer.parseInt(next());
	}

	private static void tr(Object... o) {
		if (is != System.in)
			System.out.println(java.util.Arrays.deepToString(o));
	}
}