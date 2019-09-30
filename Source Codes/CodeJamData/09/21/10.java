import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Pattern;

class Tree {
	double weight;
	String feat;
	Tree t1, t2;
	
	public double eval(final Set<String> set) {
		double p = weight;
		if (feat != null) {
			final Tree t = set.contains(feat) ? t1 : t2;
			p *= t.eval(set);
		}
		return p;
	}
}

class Parser {
	final String s;
	int p = 0;
	char c;
	
	public Parser(final String s) {
		this.s = s;
		next();
	}
	
	private void next() {
		if (p == s.length()) {
			throw new RuntimeException();
		}
		c = s.charAt(p++);
	}
	
	private void skip() {
		while (c == ' ') {
			next();
		}
	}
	
	private String get() {
		skip();
		if (c == '(' || c == ')') {
			final String s = String.valueOf(c);
			next();
			return s;
		}
		final StringBuilder sb = new StringBuilder();
		while (Character.isLetterOrDigit(c) || c == '.') {
			sb.append(c);
			next();
		}
		return sb.toString();
	}
	
	public Tree parse() {
		String s = get();
		if (!"(".equals(s)) {
			throw new RuntimeException();
		}
		s = get();
		double d = Double.parseDouble(s);
		final Tree t = new Tree();
		t.weight = d;
		s = get();
		if (")".equals(s)) {
			return t;
		}
		t.feat = s;
		t.t1 = parse();
		t.t2 = parse();
		s = get();
		if (!")".equals(s)) {
			throw new RuntimeException();
		}
		return t;
	}
}

public class Decision {
	public static void main(final String... args) throws IOException {
		final String fname = "A-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int n = sc.nextInt();
		for (int i = 0; i < n; ++i) {
			final int l = sc.nextInt();
			sc.nextLine();
			final StringBuilder sb = new StringBuilder();
			for (int j = 0; j < l; ++j) {
				sb.append(sc.nextLine()).append(' ');
			}
			pw.println("Case #" + (i + 1) + ":");
			final Tree t = new Parser(sb.toString()).parse();
			final int a = sc.nextInt();
			sc.nextLine();
			for (int j = 0; j < a; ++j) {
				final String s = sc.nextLine();
				final String[] q = s.split(" ");
				final Set<String> set = new HashSet<String>();
				for (int k = 2; k < q.length; ++k) {
					set.add(q[k]);
				}
				pw.printf("%.8f\n", t.eval(set));
			}
		}
		pw.close();
	}
}
