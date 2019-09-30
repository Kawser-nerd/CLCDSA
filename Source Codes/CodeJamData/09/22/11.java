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


public class B {
	

	Object solve() {
		String s = "000000000000000000000000000000000" + sc.next();
		char[] c = s.toCharArray();
		nextPerm(c);
		String res = new String(c);
		while (res.startsWith("0"))
			res = res.substring(1);
		return res;
	}
	
	private static boolean nextPerm(char[] a) { int n = a.length; int i = n; if(i-- <= 1) return false; while(true) { int ii = i--; if(a[i] < a[ii]) { int j = n; while(!(a[i] < a[--j])); swap(a, i, j); for (j = n; j > ii; swap(a, --j, ii++)); return true; } if(i == 0) { reverse(a); return false; } } }
	private static void swap(char[] p, int i, int j) { char t= p[i]; p[i]= p[j]; p[j]= t; }	
	private static void reverse(char[] p) { for (int l=0, r=p.length-1; l<r; l++, r--) { swap(p, l, r); } }  
	
	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "B-small-attempt0.in";
		inFile = "B-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
			fw.println(res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
