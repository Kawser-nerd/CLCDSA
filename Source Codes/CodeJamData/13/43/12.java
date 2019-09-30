import java.io.*;
import java.util.*;

public class Erdos {
	public static void main(String[] args) {
		new Erdos().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
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

	String FNAME = "c";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			System.out.println("Case #" + test + ": ");
			if (test == 21) {
				test += 0;
			}
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			int[] b = new int[n];
			for (int i = 0; i < b.length; i++) {
				b[i] = nextInt();
			}
			Tree[] last = new Tree[n + 1];
			for (int i = 0; i < a.length; i++) {
				Tree t = new Tree(i, a[i]);
				t.setParent(last[a[i] - 1]);
				if (last[a[i]] != null) {
					last[a[i]].setBrother(t);
				}
				last[a[i]] = t;
			}
			ArrayList<Tree> noparent1 = new ArrayList<>();
			for (int i = 0; i < last.length; i++) {
				if (last[i] != null && last[i].parent == null) {
					noparent1.add(last[i]);
				}
			}
			last = new Tree[n + 1];
			for (int i = b.length - 1; i >= 0; i--) {
				Tree t = new Tree(i, b[i]);
				t.setParent(last[b[i] - 1]);
				if (last[b[i]] != null) {
					last[b[i]].setBrother(t);
				}
				last[b[i]] = t;
			}
			ArrayList<Tree> noparent2 = new ArrayList<>();
			for (int i = 0; i < last.length; i++) {
				if (last[i] != null && last[i].parent == null) {
					noparent2.add(last[i]);
				}
			}
			int[] ans = new int[n];
			int cnt = 0;
			while (cnt < ans.length) {
				Tree good1 = null;
				Tree good2 = null;
				int smallest = Integer.MAX_VALUE / 2;
				for (Tree t1 : noparent1) {
					for (Tree t2 : noparent2) {
						if (t1.id == t2.id) {
							smallest = Math.min(smallest, t2.id);
						}
					}
				}
				if (smallest >= Integer.MAX_VALUE / 2) {
					throw new Error("Oops!!!");
				}
				for (Tree t1 : noparent1) {
					if (t1.id == smallest) {
						good1 = t1;
						break;
					}
				}
				for (Tree t2 : noparent2) {
					if (t2.id == smallest) {
						good2 = t2;
						break;
					}
				}
				ans[good1.id] = ++cnt;
				noparent1.remove(good1);
				noparent2.remove(good2);
				for (Tree t : good1.children) {
					if (t.brother == good1) {
						t.forgetBrother();
					} else {
						t.forgetParent();
					}
					if (t.alone()) {
						noparent1.add(t);
					}
				}
				for (Tree t : good2.children) {
					if (t.brother == good2) {
						t.forgetBrother();
					} else {
						t.forgetParent();
					}
					if (t.alone()) {
						noparent2.add(t);
					}
				}
			}
			int[] a2 = new int[n];
			for (int i = 0; i < a2.length; i++) {
				for (int j = 0; j < i; j++) {
					if (ans[j] < ans[i]) {
						a2[i] = Math.max(a2[i], a2[j]);
					}
				}
				a2[i]++;
			}
			int[] b2 = new int[n];
			for (int i = b2.length - 1; i >= 0; i--) {
				for (int j = i + 1; j < b2.length; j++) {
					if (ans[j] < ans[i]) {
						b2[i] = Math.max(b2[i], b2[j]);
					}
				}
				b2[i]++;
			}
			for (int i = 0; i < b2.length; i++) {
				if (a[i] != a2[i] || b[i] != b2[i]) {
					System.out.println(Arrays.toString(a));
					System.out.println(Arrays.toString(a2));
					System.out.println(Arrays.toString(b));
					System.out.println(Arrays.toString(b2));
					System.out.println(Arrays.toString(ans));
					throw new Error("Oops2!!");
				}
			}
			for (int i = 0; i < ans.length; i++) {
				out.print(ans[i] + " ");
			}
			out.println();
		}
	}

	class Tree {

		@Override
		public String toString() {
			return id + " (" + (parent == null ? "-" : ("" + parent.id)) + ")";
		}

		public boolean alone() {
			return brother == null && parent == null;
		}

		public void setBrother(Tree t) {
			brother = t;
			if (brother != null) {
				brother.children.add(this);
			}
		}

		public Tree(int i, int j) {
			id = i;
			level = j;
			children = new HashSet<>();
		}

		public void setParent(Tree t) {
			parent = t;
			if (parent != null) {
				parent.children.add(this);
			}
		}

		public void forgetParent() {
			if (parent != null) {
				// parent.children.remove(this);
				parent = null;
			}
		}

		public void forgetBrother() {
			if (brother != null) {
				// brother.children.remove(this);
				brother = null;
			}
		}

		int id;
		int level;
		Tree parent;
		Tree brother;
		Set<Tree> children;
	}
}
