import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	String dontKnow = "I don't know.";

	private void solve() {
		int d = in.nextInt();
		int k = in.nextInt();
		int[] s = new int[k];
		int max = 0;
		for (int i = 0; i < k; i++) {
			s[i] = in.nextInt();
			max = Math.max(s[i], max);
		}
		for (int i = 0; i < k - 1; i++) {
			if (s[i] == s[k - 1]) {
				out.println(s[i + 1]);
				return;
			}
		}
		if (k <= 2) {
			out.println(dontKnow);
			return;
		}
		BigInteger v = BigInteger.valueOf(s[0] - s[1]);
		Set<Integer> ans = new HashSet<Integer>();
		iloop:
		for (int i = 0; i < primes.length; i++) {
			int p = primes[i];
			if (("" + p).length() > d) {
				break;
			}
			if (max >= p) {
				continue;
			}
			long a = v.modInverse(pp[i]).intValue();
			a = (a * (s[1] - s[2] + p)) % p;
			long t = (a * s[0]) % p;
			long b = (s[1] - t + p) % p;
			for (int j = 1; j < k; j++) {
				if (((s[j - 1] * a + b) % p) != s[j]) {
					continue iloop;
				}
			}
			int sk = (int) ((s[k - 1] * a + b) % p);
			ans.add(sk);
			if (ans.size() > 1) {
				out.println(dontKnow);
				return;
			}
		}
		out.println(ans.iterator().next());
	}

	static boolean[] isPrime;
	static int[] primes;
	static BigInteger[] pp;
	
	public static void main(String[] args) throws IOException {
		int n = 1000000;
		isPrime = new boolean[n + 1];
		for (int i = 2; i <= n; i++)
			isPrime[i] = true;
		for (int i = 2, j; (j = i * i) <= n; i++) {
			if (!isPrime[i])
				continue;
			do {
				isPrime[j] = false;
				j += i;
			} while (j <= n);
		}
		int m = 0;
		for (int i = 2; i <= n; i++) {
			if (isPrime[i])
				m++;
		}
		primes = new int[m];
		pp = new BigInteger[m];
		m = 0;
		for (int i = 2; i <= n; i++) {
			if (isPrime[i]) {
				primes[m] = i;
				pp[m] = BigInteger.valueOf(i);
				m++;
			}
		}
		
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
		}
		in.close();
		out.close();
	}
}
