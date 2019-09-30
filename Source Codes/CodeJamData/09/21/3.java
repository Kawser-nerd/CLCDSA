import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class BaiA {

	static class Node {
		double p;
		String name;
		Node left, right;
	}

	static Node create(String s) {
		s = s.trim();
		if (s.equals("()"))
			return null;
		s = s.substring(1, s.length() - 1);
		// System.out.println(s);
		Scanner sc = new Scanner(s);
		Node res = new Node();
		res.p = sc.nextDouble();
		if (sc.hasNext()) {
			res.name = sc.next();
			s = sc.nextLine();
			s = s.trim();
			int dem = 0;
			for (int i = 0; i < s.length(); ++i) {
				if (s.charAt(i) == '(')
					dem++;
				if (s.charAt(i) == ')')
					dem--;
				if (dem == 0) {
					res.left = create(s.substring(0, i + 1));
					res.right = create(s.substring(i + 1, s.length()));
					break;
				}
			}
		}
		return res;
	}

	static double calc(Node n, TreeSet<String> ts) {
		double res = n.p;
		if (n.name != null) {
			if (ts.contains(n.name))
				return res * calc(n.left, ts);
			else
				return res * calc(n.right, ts);
		}
		return res;
	}

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));
		int ntest = sc.nextInt();
		for (int test = 1; test <= ntest; ++test) {
			int line = sc.nextInt();
			sc.nextLine();
			String s = "";
			for (int i = 0; i < line; ++i) {
				s = s + " " + sc.nextLine();
			}
			Node root = create(s);
			int n = sc.nextInt();
			pw.println("Case #" + test + ":");
			for (int i = 0; i < n; ++i) {
				String name = sc.next();
				int k = sc.nextInt();
				TreeSet<String> ts = new TreeSet<String>();
				for (int j = 0; j < k; ++j) {
					String ss = sc.next();
					ts.add(ss);
				}
				double p = calc(root, ts);
				pw.printf("%.7f\n", p);
			}
		}
		pw.close();
		sc.close();
	}
}
