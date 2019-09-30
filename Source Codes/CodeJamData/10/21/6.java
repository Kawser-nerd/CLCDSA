import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class A {
	

	Object solve() {
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		Dir root = new Dir("/");
		
		for (int i = 0; i < N; i++) {
			String p = sc.next().substring(1);
			String[] n = p.split("/");
			Dir d = root;
			for (int j = 0; j < n.length; j++) {
				if (!d.hasChild(n[j]))
					d.children.put(n[j], new Dir(n[j]));
				d = d.children.get(n[j]);
			}
		}
		
		int cnt = 0;
		
		for (int i = 0; i < M; i++) {
			String p = sc.next().substring(1);
			String[] n = p.split("/");
			Dir d = root;
			for (int j = 0; j < n.length; j++) {
				if (!d.hasChild(n[j])) {
					d.children.put(n[j], new Dir(n[j]));
					cnt++;
				}
				d = d.children.get(n[j]);
			}
		}
		
		return cnt;
	}
	
	static class Dir {
		
		String name;
		HashMap<String,Dir> children = new HashMap<String, Dir>();

		public Dir(String name) {
			this.name = name;
		}

		boolean hasChild(String s) {
			return children.containsKey(s);
		}
		
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "A-small-attempt0.in";
		inFile = "A-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
