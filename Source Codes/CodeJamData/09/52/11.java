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
		String s = sc.next();
		int k = sc.nextInt();
		String[] t = s.split("\\+");
		int[][] p = new int[t.length][26];
		int T = t.length;
		for (int i = 0; i < T; i++)
			for (int j = 0; j < t[i].length(); j++)
				p[i][t[i].charAt(j) - 'a']++;
		
		int n = sc.nextInt();
		String[] w = new String[n];
		int[][] ww = new int[n][26];
		for (int i = 0; i < n; i++) {
			w[i] = sc.next();
			
			for (int j = 0; j < w[i].length(); j++)
				ww[i][w[i].charAt(j) - 'a']++;
		}
		
		for (int d = 1; d <= k; d++) {
			long res = 0;
			int D = (int)pow(n, d);
			for (int i = 0; i < D; i++) {
				long res1 = 0;
				int z = i;
				int[] num = new int[d];
				for (int j = 0; j < d; j++) {
					num[j] = z%n;
					z /= n;
				}
				
				long[] cnt = new long[26];
				
				for (int j = 0; j < d; j++) {
					for (int l = 0; l < 26; l++) {
						cnt[l] += ww[num[j]][l];
//						cnt[l] %= mod;
					}
				}
				
				
				for (int j = 0; j < T; j++) {
					long r1 = 1;
					for (int l = 0; l < t[j].length(); l++) {
						char c = t[j].charAt(l);
						r1 *= cnt[c - 'a'];
						r1 %= mod;
					}
					
					res1 = (res1 + r1)%mod;
				}
				
//				for (int j = 0; j < d; j++) {
//					System.out.print(w[num[j]] + " ");
//				}
//				System.out.println(res1);
					
				res = (res + res1)%mod;
			}
			
			fw.print(res + " ");
		}
		
		return "";
	}

	
	int mod = 10009;
	
	int[] ia(String s) { String[] a = s.split("\\s+"); int[] r = new int[a.length]; for (int i = 0; i < r.length; i++) r[i] = parseInt(a[i]); return r; }
	
	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "B-small-attempt0.in";
//		inFile = "B-large.in";
		
		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
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
