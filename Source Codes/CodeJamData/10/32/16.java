package com.gcj10.r1c;

import java.util.*;
import java.io.*;

public class LoadTesting {
	private static String DIR = "data/r1c/";
	private static String ATTEMPT = "B-large";
	private static String FILE_INPUT = DIR + ATTEMPT + ".in";
	private static String FILE_OUTPUT = DIR + ATTEMPT + ".out";
	
	public static void main(String[] args) throws IOException {
		Scanner sin = new Scanner(new FileReader(FILE_INPUT));
		PrintWriter out = new PrintWriter(new FileWriter(FILE_OUTPUT));
		
		final int T = Integer.parseInt(sin.nextLine());
		for (int i=0; i<T; i++) {
			final long L = sin.nextLong();
			final long P = sin.nextLong();
			final int C = sin.nextInt();
			
			out.format("Case #%d: %d\n", i+1, testsNeeded(L, P, C));
		}

		out.flush();
		out.close();
	}
	
	public static int testsNeeded(long lo, long hi, int C) {
		long factor = hi/lo;
		if (hi%lo != 0) factor++;
		if (factor <= C) return 0;
		long mid = Math.round(Math.sqrt(lo*hi));
		return 1+Math.max(testsNeeded(lo, mid, C), testsNeeded(mid, hi, C));
	}
}
