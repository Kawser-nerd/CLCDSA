import java.io.*;
import java.util.*;

public class Main {

	static class Poly {
		int[] coef;
		int lead;

		public Poly(int[] coef, int lead) {
			this.coef = coef;
			this.lead = lead;
		}

		void trim() {
			while (lead >= 0 && coef[lead] == 0) {
				lead--;
			}
		}
	}

	Poly getPoly() {
		String s = nextToken();
		int[] coef = new int[s.length()];
		for (int i = 0; i < s.length(); i++) {
			coef[i] = s.charAt(s.length() - 1 - i) - '0';
		}
		return new Poly(coef, coef.length - 1);
	}

	void divideLeading(Poly a, Poly b) {
		// b.lead -> a.lead
		// b.lead-1 -> a.lead-1
		for (int i = 0; i <= b.lead; i++) {
			a.coef[i + a.lead - b.lead] ^= b.coef[i];
		}
		a.trim();
	}

	Poly gcd(Poly a, Poly b) {
		if (a.lead < b.lead) {
			Poly tmp = a;
			a = b;
			b = tmp;
		}
		if (b.lead == -1) {
			return a;
		}
		divideLeading(a, b);
		return gcd(b, a);
	}

	static final int P = 998244353;

	void submit() {
		int n = nextInt();
		Poly x = getPoly();

		Poly g = getPoly();
		for (int i = 1; i < n; i++) {
			Poly p = getPoly();
			g = gcd(g, p);
		}

		int[] gcd = Arrays.copyOf(g.coef, g.lead + 1);
		
//		System.err.println(Arrays.toString(gcd));

		int[] our = Arrays.copyOf(x.coef, Math.max(x.lead + 1, gcd.length));

		int valLess = 0;
//		for (int i = gcd.length - 1; i < our.length; i++) {
		for (int i = our.length - 1; i >= gcd.length - 1; i--) {
			valLess = (valLess * 2 + our[i]) % P;
		}

		Poly xx = new Poly(x.coef.clone(), x.lead);
		for (int i = 0; i < gcd.length - 1; i++) {
			if (i < xx.coef.length) {
				xx.coef[i] = 0;
			}
		}
		xx.trim();
		while (xx.lead >= g.lead) {
			divideLeading(xx, g);
		}
		
		int[] gMult = Arrays.copyOf(xx.coef, gcd.length - 1);
		
		if (compare(gMult, Arrays.copyOf(x.coef, gcd.length - 1)) <= 0) {
			valLess++;
			if (valLess >= P) {
				valLess -= P;
			}
		}
		
		out.println(valLess);
	}
	
	int compare(int[] a, int[] b){
		if (a.length != b.length) {
			throw new AssertionError();
		}
		
		for (int i = b.length - 1; i >= 0; i--) {
			if (a[i] != b[i]) {
				return a[i] < b[i] ? -1 : 1;
			}
		}
		return 0;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}