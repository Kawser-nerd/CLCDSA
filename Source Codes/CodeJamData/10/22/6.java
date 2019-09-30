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
		int N = sc.nextInt();
		int K = sc.nextInt();
		int B = sc.nextInt();
		int T = sc.nextInt();
		int[] x = new int[N];
		int[] v = new int[N];
		
		for (int i = 0; i < N; i++)
			x[i] = sc.nextInt();
		
		for (int i = 0; i < N; i++)
			v[i] = sc.nextInt();
		
		int[] p = new int[N];
		int pos = 0;
		for (int i = 0; i < N; i++) {
			p[i] = x[i] + T*v[i];
			if (p[i] >= B)
				pos++;
		}
		
		if (pos < K)
			return "IMPOSSIBLE";

		int cnt = 0;
		for (int i = 0; i < K; i++) {
			for (int j = N - i - 1; j >= 0; j--) {
				if (p[j] >= B) {
					swap(p, N - i - 1, j);
					cnt += N - i - 1 - j;
					break;
				}
			}
		}
		
		return cnt;
	}

	private static void swap(int[] p, int i, int j) { int t= p[i]; p[i]= p[j]; p[j]= t; }
	
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
