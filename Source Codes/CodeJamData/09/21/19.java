import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Locale;
import java.util.Set;

public class A {

	public static final String FILE_NAME = "A-large";

	// public static final String FILE_NAME = "A-small-attempt0";

	// public static final String FILE_NAME = "test";

	private static NumberFormat fmt = new DecimalFormat("0.0000000",
			new DecimalFormatSymbols(Locale.US));

	private static class Node {
		public double p;
		public String feature;
		public Node yes, no;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(FILE_NAME
				+ ".in"));
		BufferedWriter output = new BufferedWriter(new FileWriter(FILE_NAME
				+ ".out"));
		final int T = Integer.parseInt(input.readLine());
		for (int t = 0; t < T; t++) {
			output.append("Case #" + (t + 1) + ":\n");
			final int L = Integer.parseInt(input.readLine());
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < L; i++) {
				sb.append(input.readLine());
				sb.append(' ');
			}
			String[] tokens = sb.toString().replaceAll("(\\(|\\))", " $1 ")
					.trim().split(" +");
			Iterator<String> iter = Arrays.asList(tokens).iterator();
			Node root = buildTree(iter);
			final int A = Integer.parseInt(input.readLine());
			for (int a = 0; a < A; a++) {
				String[] line = input.readLine().trim().split(" +");
				final int N = Integer.parseInt(line[1]);
				Set<String> features = new HashSet<String>();
				for (int n = 0; n < N; n++)
					features.add(line[n + 2]);
				output.append(fmt.format(getP(root, features)));
				output.append('\n');
			}
		}
		output.close();
	}

	static Node buildTree(Iterator<String> iter) {
		if (!iter.next().equals("(")) {
			throw new IllegalArgumentException();
		}
		Node node = new Node();
		node.p = Double.parseDouble(iter.next());
		String t = iter.next();
		if (t.equals(")")) {
			return node;
		}
		node.feature = t;
		node.yes = buildTree(iter);
		node.no = buildTree(iter);
		if (!iter.next().equals(")")) {
			throw new IllegalArgumentException();
		}
		return node;
	}

	static double getP(Node node, Set<String> f) {
		if (node.feature == null)
			return node.p;
		Node next;
		if (f.contains(node.feature))
			next = node.yes;
		else
			next = node.no;
		return node.p * getP(next, f);
	}
}
