import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B_train_cars2 {
	public static boolean isValid(final String s) {
		boolean f[] = new boolean[26];
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if (f[c - 'a'] && c != s.charAt(i - 1)) {
				return false;
			}
			f[c - 'a'] = true;
		}
		return true;
	}
	
	public BigInteger fact(int n) {
		BigInteger p = BigInteger.ONE;
		for (int i = 1; i <= n; ++i) {
			p = p.multiply(BigInteger.valueOf(i));
		}
		return p;
	}
	
	public BigInteger calc2(List<String> l) {
		while (true) {
			boolean found = false;
			for (String s : l) {
				for (String t : l) {
					if (!s.equals(t) && t.charAt(0) == s.charAt(s.length() - 1)) {
						if (!isValid(s + t)) {
							return BigInteger.ZERO;
						}
						found = true;
						l.remove(s);
						l.remove(t);
						l.add(s + t);
						break;
					}
				}
				if (found) break;
			}
			if (!found) break;
		}
		String w = "";
		for (String s : l) {
			w += s;
		}
		if (!isValid(w)) {
			return BigInteger.ZERO;
		}
		return fact(l.size());
	}
	
	public BigInteger calc1(char ch, List<String> l) {
		if (ch > 'z') {
			return calc2(l);
		}
		List<String> a = new ArrayList<String>();
		for (String s : l) {
			if (s.charAt(0) == ch && s.charAt(s.length() - 1) == ch) {
				a.add(s);
			}
		}
		if (a.isEmpty()) {
			return calc1((char) (ch + 1), l);
		}
		l.removeAll(a);
		boolean f = false;
		for (String s : l) {
			if (s.charAt(0) == ch || s.charAt(s.length() - 1) == ch) {
				f = true;
				break;
			}
		}
		if (!f) l.add(String.valueOf(ch));
		return calc1((char) (ch + 1), l).multiply(fact(a.size()));
	}
	
	public BigInteger calc(List<String> l) {
		for (String s : l) {
			if (!isValid(s)) {
				return BigInteger.ZERO;
			}
		}
		for (String s : l) {
			for (String t : l) {
				char c = s.charAt(0);
				if (t.indexOf(c) > 0 && t.charAt(t.length() - 1) != c) {
					return BigInteger.ZERO;
				}
				c = s.charAt(s.length() - 1);
				if (t.indexOf(c) > 0 && t.charAt(t.length() - 1) != c) {
					return BigInteger.ZERO;
				}
			}
		}
		return calc1('a', l);
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int n = sc.nextInt();
		final List<String> w = new ArrayList<String>();
		for (int j = 0; j < n; ++j) {
			w.add(sc.next());
		}
		pw.println(calc(w).mod(BigInteger.valueOf(1000000007)));
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new B_train_cars2().solve(sc, pw);
		}
		pw.close();
	}
}
