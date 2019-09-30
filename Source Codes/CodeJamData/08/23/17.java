package com.gliebe.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ProblemC {

	public static void main(String[] args) throws IOException {
		InputStream in = new FileInputStream(args[0]);
		FileWriter out = new FileWriter(args[1]);
		try {
		   InputStreamReader inR = new InputStreamReader( in );
		   BufferedReader buf = new BufferedReader( inR );
		   int n = Integer.parseInt(buf.readLine());
		   for (int i = 0; i<n; i++) {
			   out.write("Case #" + (i +1) + ":" + calculateCase(buf) + "\n");
		   }
		 } finally {
		   in.close();
		   out.close();
		 }
	}
	// n, A, B, C, D, x0, y0 and M
	
	static int next(int x, int A, int B, int M) {
		return (x * A + B) % M;
	}
	
	static Pattern p = Pattern.compile("(\\d*)\\s(\\d*)\\s(\\d*)");
	static String calculateCase(BufferedReader buf) throws IOException {
		int K = Integer.parseInt(buf.readLine());
		String s = buf.readLine() + " ";
		List<Integer> ds = new ArrayList<Integer>();
		String result = "";
		s += " ";
		int ix = s.indexOf(" ");
		int n = Integer.parseInt(s.substring(0,ix));
		for (int i = 0; i<n; i++) {
			s = s.substring(ix+1);
			ix = s.indexOf(" ");
			ds.add(Integer.parseInt(s.substring(0,ix)));
			result += " " + calculate(K, Integer.parseInt(s.substring(0,ix)));
	   }
	   
			
		return result;
			
	}
	
	private static int  calculate(int k, int d) {
		for (int i = 1; i<=k; i++) {
			int r = k-i+1;
			int m = i % r;
			if (m==0) {
				m = r;
			}
			if (m == d) {
				return i;
			} else {
				d -= m;
				if (d < 0) {
					d += r;
				}
			}
		}
		return 0;
	}	
	
}
