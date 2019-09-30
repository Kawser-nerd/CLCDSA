package com.gcj10.r1c;

import java.util.*;
import java.io.*;

public class MakingChessBoards {
	private static String DIR = "data/r1c/";
	private static String ATTEMPT = "C-large";
	private static String FILE_INPUT = DIR + ATTEMPT + ".in";
	private static String FILE_OUTPUT = DIR + ATTEMPT + ".out";
	
	static final String s = "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"
		+ "010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101";
	
	public static void main(String[] args) throws IOException {
		Scanner sin = new Scanner(new FileReader(FILE_INPUT));
		PrintWriter out = new PrintWriter(new FileWriter(FILE_OUTPUT));
		
		final int T = Integer.parseInt(sin.nextLine());
		for (int i=0; i<T; i++) {
			final int M = sin.nextInt();
			final int N = sin.nextInt();
			sin.nextLine();
			
			StringBuilder[] board = new StringBuilder[M];
			for (int m=0; m<M; m++) {
				String hex = sin.nextLine();
				String bin = "";
				for (int c=0; c<hex.length(); c++) {
					String sx = Integer.toBinaryString(Integer.parseInt(""+hex.charAt(c), 16));
					while (sx.length() < 4) {
						sx = "0"+sx;
					}
					bin += sx;
				}
				board[m] = new StringBuilder(bin);
			}
			
			List<Integer> sizeList = new ArrayList<Integer>();
			Map<Integer, Integer> sizeMap = new HashMap<Integer, Integer>();
			for (int n=N; n>=1; n--) {
				//System.out.print("n: " +n);
				int x = numBoards(board, n);
				//System.out.println(", boards: " + x);
				//if (i == 0 && n == 6) {
				//	for (int b=0; b<board.length; b++) {
				//		System.out.println(board[b]);
				//	}
				//}
				if (x > 0) {
					sizeList.add(n);
					sizeMap.put(n, x);
				}
			}
			
			out.format("Case #%d: %d\n", i+1, sizeList.size());
			for (int k=0; k<sizeList.size(); k++) {
				out.format("%d %d\n", sizeList.get(k), sizeMap.get(sizeList.get(k)));
			}
		}

		out.flush();
		out.close();
	}
	
	public static int numBoards(StringBuilder[] board, int size) {
		int n = 0;
		for (int h=0; h<board.length; h++) {
			for (int w=0; w<board[h].length(); w++) {
				if (isBoard(board, size, h, w)) {
					n++;
					invalidate(board, size, h, w);
				}
			}
		}
		return n;
	}
	
	public static boolean isBoard(StringBuilder[] board, int size, int h, int w) {
		if (h+size>board.length || w+size>board[0].length()) return false;
		boolean zeroStart = (board[h].charAt(w) == '0');
		String zeroStr = getAltStr(size, true);
		String oneStr = getAltStr(size, false);
		for (int hh=h; hh<h+size; hh++) {
			String ss = board[hh].substring(w, w+size);
			if ((zeroStart && !zeroStr.equals(ss)) || (!zeroStart && !oneStr.equals(ss))) return false;
			zeroStart = !zeroStart;
		}
		return true;
	}
	
	public static void invalidate(StringBuilder[] board, int size, int h, int w) {
		String replace = "";
		for (int ww=w; ww<w+size; ww++) {
			replace += "X";
		}
		for (int hh=h; hh<h+size; hh++) {
			board[hh].replace(w, w+size, replace);
		}
	}
	
	public static String getAltStr(int len, boolean zeroStart) {
		if (zeroStart) return s.substring(0, len);
		return s.substring(1, len+1);
	}
}
