import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import com.sun.org.apache.regexp.internal.StringCharacterIterator;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class A {
	
	Object solve() {
		int l = sc.nextInt();
		sc.nextLine();
		String s = "";
		for (int i = 0; i < l; i++)
			s += " " + sc.nextLine();
		
		s = s.replaceAll("\\(", " ( ").replaceAll("\\)", " ) ");

		Tree t = parse(new Scanner(s));
		
		int A = sc.nextInt();
		
		for (int i = 0; i < A; i++) {
			sc.next();
			int n = sc.nextInt();
			HashSet<String> h = new HashSet<String>();
			for (int j = 0; j < n; j++)
				h.add(sc.next());
			fw.printf("%.8f\n", t.calc(h));
		}
		
		return null;
	}
	
	Tree parse(Scanner s) {
		String c = s.next();
		if (c.charAt(0) != '(') System.out.println(c);
		
		double w = parseDouble(s.next());
		
		String next = s.next();
		
		if (next.equals(")")) {
			return new Tree(w, null, null, null);
		} 
		
		String feature = next;
		Tree left = parse(s);
		Tree right = parse(s);
		
		s.next();
		
		return new Tree(w, feature, left, right);
	}
	
	static class Tree {
		double w;
		Tree left, right;
		String feature;
		public Tree(double w, String feature, Tree left, Tree right) {
			this.w = w;
			this.feature = feature;
			this.left = left;
			this.right = right;
		}
		
		double calc(Collection<String> c) {
			if (feature == null) return w;
			if (c.contains(feature)) {
				return w*left.calc(c);
			} else {
				return w*right.calc(c);
			}
		}
	}
	
	int[] ia(String s) { String[] a = s.split("\\s+"); int[] r = new int[a.length]; for (int i = 0; i < r.length; i++) r[i] = parseInt(a[i]); return r; }
	
	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
//		inFile = "A-small-attempt0.in";
		inFile = "A-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
//			fw.print("Case #" + cas + ": ");
			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
//			fw.println(res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
