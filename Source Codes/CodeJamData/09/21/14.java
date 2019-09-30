import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class A {

	class Tree {
		String name;
		double prob;
		Tree l, r;

		public Tree(String name, double prob) {
			this.name = name;
			this.prob = prob;
		}
	}

	Tree build() {
		treet.nextToken();
		double q = Double.parseDouble(treet.nextToken());
		String s = treet.nextToken();
		if (s.equals(")")) {
			return new Tree(null, q);
		} else {
			Tree t = new Tree(s, q);
			t.l = build();
			t.r = build();
			treet.nextToken();
			return t;
		}
	}

	StringTokenizer treet;

	void test() throws IOException {
		int l = nextInt();
		System.err.println(l);
		String s = "";
		for (int i = 0; i < l; i++) {
			s += br.readLine() + " ";
		}
		s = s.replace(")", " ) ").replace("(", " ( ");
		System.err.println(s);
		treet = new StringTokenizer(s);
		Tree root = build();
		int a = nextInt();
		for (int i = 0; i < a; i++) {
			nextToken();
			int n = nextInt();
			TreeSet<String> ts = new TreeSet<String>();
			for (int j = 0; j < n; j++) {
				ts.add(nextToken());
			}
			double prob = 1;
			Tree t = root;
			while (t.name != null) {
				prob *= t.prob;
				if (ts.contains(t.name)) {
					t = t.l;
				} else {
					t = t.r;
				}
			}
			prob *= t.prob;
			out.printf("%.7f\n", prob);
		}
	}

	private void solve() throws IOException {
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #" + (i + 1) + ":");
			test();
		}
	}

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	private void run() {
		try {
			br = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		} catch (IOException e) {
			return "";
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new A().run();
	}
}
