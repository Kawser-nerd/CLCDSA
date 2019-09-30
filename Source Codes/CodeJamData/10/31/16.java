package com.gcj10.r1c;

import java.util.*;
import java.io.*;

public class RopeIntranet {
	private static String DIR = "data/r1c/";
	private static String ATTEMPT = "A-large";
	private static String FILE_INPUT = DIR + ATTEMPT + ".in";
	private static String FILE_OUTPUT = DIR + ATTEMPT + ".out";
	
	public static void main(String[] args) throws IOException {
		Scanner sin = new Scanner(new FileReader(FILE_INPUT));
		PrintWriter out = new PrintWriter(new FileWriter(FILE_OUTPUT));
		
		final int T = Integer.parseInt(sin.nextLine());
		for (int i=0; i<T; i++) {
			final int N = sin.nextInt();
			sin.nextLine();
			
			int[] a = new int[N];
			int[] b = new int[N];
			for (int n=0; n<N; n++) {
				a[n] = sin.nextInt();
				b[n] = sin.nextInt();
			}
			
			int ans = 0;
			for (int x=0; x<N; x++) {
				for (int y=x+1; y<N; y++) {
					if (intersects(a[x], a[y], b[x], b[y])) ans++;
				}
			}
			out.format("Case #%d: %d\n", i+1, ans);
		}

		out.flush();
		out.close();
	}
	
	public static boolean intersects(int l1, int l2, int r1, int r2) {
		return ((l1 < l2 && r1 > r2) || (l1 > l2 && r1 < r2));
	}
}
