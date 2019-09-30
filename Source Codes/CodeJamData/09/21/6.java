import java.util.*;
import java.io.*;

public class A implements Runnable {
	private BufferedReader in;
	private PrintWriter out;
	private String problemID = getClass().getName().toLowerCase().split("_")[0] + "-large";
	
	private boolean isSpace(char ch) {
		return (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'); 
	}
	
	private int skipSpaces(String line, int u) {
		while (isSpace(line.charAt(u))) {
			u++;
		}
		return u;
	}
	
	private int parseTree(String line, int u, Tree t) {
		while (line.charAt(u) != '(') {
			u++;
		}
		if (line.charAt(u) != '(') {
			throw new Error();
		}
		u++;
		
		u = skipSpaces(line, u);
		int x1 = u;
		while (line.charAt(x1) != ')' && !isSpace(line.charAt(x1))) {
			x1++;
		}
		
		t.p = Double.parseDouble(line.substring(u, x1));
		u = skipSpaces(line, x1);
		if (line.charAt(u) == ')') {
			t.left = t.right = null;
			return u + 1;
		}
		
		x1 = u;
		while (!isSpace(line.charAt(x1))) {
			x1++;
		}
		t.feature = line.substring(u, x1);
		
		t.left = new Tree();
		t.right = new Tree();
		u = parseTree(line, x1, t.left);
		u = parseTree(line, u, t.right);
		
		u = skipSpaces(line, u);
		if (line.charAt(u) != ')') {
			throw new Error();
		}
		return u + 1;
	}
	
	private class Tree {
		public double p;
		public Tree left, right;
		public String feature;
	}
	
	private void solveSingleTest(int testNumber) throws IOException {
		int l = Integer.parseInt(in.readLine());
		String tree = "";
		for (int i = 0; i < l; i++) {
			tree = tree + " " + in.readLine();
		}
		
		Tree root = new Tree();
		parseTree(tree, 0, root);
		
		int a = Integer.parseInt(in.readLine());
		out.println("Case #" + testNumber + ":");
		for (int i = 0; i < a; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			st.nextToken();
			int u = Integer.parseInt(st.nextToken());
			Set<String> features = new HashSet<String>();
			for (int j = 0; j < u; j++) {
				features.add(st.nextToken());
			}
			
			Tree t = root;
			double p = 1.0;
			while (true) {
				p = p * t.p;
				if (t.feature == null) {
					break;
				}
				if (features.contains(t.feature)) {
					t = t.left;
				} else {
					t = t.right;
				}
			}
			out.printf("%.8f\n", p);
		}
	}

	private void solve() throws IOException {
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			solveSingleTest(i + 1);
		}
	}
	
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new FileReader(new File(problemID + ".in")));
			out = new PrintWriter(new File(problemID + ".out"));
			solve();
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		new Thread(new A()).start();
	}
}
