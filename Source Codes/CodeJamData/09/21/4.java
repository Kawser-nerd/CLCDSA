import static java.lang.Double.parseDouble;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Set;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	private static class Node {
		
		final double weight;
		final String feature;
		final Node left, right;
		
		Node(Iterator<String> tokens) {
			if (!"(".equals(tokens.next())) {
				throw new AssertionError();
			}
			weight = parseDouble(tokens.next());
			String feature = tokens.next();
			if (")".equals(feature)) {
				this.feature = null;
				this.left = null;
				this.right = null;
			} else {
				this.feature = feature;
				left = new Node(tokens);
				right = new Node(tokens);
				if (!")".equals(tokens.next())) {
					throw new AssertionError();
				}
			}
		}
	}
	
	public static void main(String args[]) throws Exception {
		in = new BufferedReader(new InputStreamReader(new FileInputStream("a.in")));
		out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("a.out")));
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			int l = nextInt();
			List<String> tree = new ArrayList<String>();
			for (int i = 0; i < l; i++) {
				String s = in.readLine();
				StringTokenizer tok = new StringTokenizer(s, " \t\n\r\f()", true);
				while (tok.hasMoreElements()) {
					String ttok = tok.nextToken();
					if (" ".equals(ttok) || "\t".equals(ttok) || "\n".equals(ttok) || "\r".equals(ttok) || "\f".equals(ttok)) {
						continue;
					}
					tree.add(ttok);
				}
			}
			Iterator<String> treeit = tree.iterator();
			Node root = new Node(treeit);
			if (treeit.hasNext()) {
				throw new AssertionError();
			}
			out.println("Case #" + (t + 1) + ":");
			int A = nextInt();
			for (int a = 0; a < A; a++) {
				Set<String> features = new HashSet<String>();
				next();
				int n = nextInt();
				for (int i = 0; i < n; i++) {
					features.add(next());
				}
				Node cur = root;
				double p = 1;
				while (true) {
					p *= cur.weight;
					if (cur.feature == null) {
						break;
					}
					if (features.contains(cur.feature)) {
						cur = cur.left;
					} else {
						cur = cur.right;
					}
				}
				out.printf(Locale.US, "%.7f%n", p);
			}
		}
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
}