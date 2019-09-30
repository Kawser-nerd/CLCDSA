import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

import static java.lang.Math.*;


public class Solution implements Runnable {

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
			throw new RuntimeException("Laja in solution");
		}
	}
	
	private String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(cin.readLine());
		}
		
		return tok.nextToken();
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	BufferedReader cin;
	StringTokenizer tok;
	PrintWriter cout;
	
	public void solve() throws Exception {
		//cin = new BufferedReader(new FileReader("input.txt"));
		cin = new BufferedReader(new FileReader("C-large.in"));
		cout = new PrintWriter("output.txt");
		//cout = new PrintWriter("");
		
		int testcases = nextInt();
		for (int test = 0; test < testcases; ++test) {
			int n = nextInt();
			int m = nextInt();
			
			ArrayList<Series> a = readSeries(n);
			ArrayList<Series> b = readSeries(m);
			//n = a.size();
			//m = b.size();
			
			long[][] d = new long[n + 1][m + 1];
			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					Set<Integer> types = new HashSet<Integer>();
					types.add(a.get(i).type);
					types.add(b.get(j).type);
					
					for(int curType: types) {
						long curA = 0;
						for (int k = i; k < n; ++k) {
							if (a.get(k).type == curType) {
								curA += a.get(k).amount;
							}
							
							long curB = 0;
							for (int l = j; l < m; ++l) {
								if (b.get(l).type == curType) {
									curB += b.get(l).amount;
								}
								
								d[k + 1][l + 1] = max(d[k + 1][l + 1], d[i][j] + min(curA, curB));
							}
						}
					}
				}
			}
			
			cout.println("Case #" + (test + 1) + ": " + d[n][m]);
			cout.flush();
		}
		
		cout.close();
	}
	
	private ArrayList<Series> readSeries(int numberOfSeries) throws IOException {
		ArrayList<Series> result = new ArrayList<Series>();
		
		for (int i = 0; i < numberOfSeries; ++i) {
			result.add(new Series(nextLong(), nextInt()));
		}
		/*
		int i = 0;
		while (i < result.size() - 1) {
			if (result.get(i).type != result.get(i + 1).type) {
				++i;
			} else {
				result.set(i, new Series(result.get(i).amount + result.get(i + 1).amount, result.get(i).type));
				result.remove(i + 1);
			}
		}*/
		
		return result;
	}

	class Series {
		final long amount;
		final int type;
		
		public Series(long amount, int type) {
			this.amount = amount;
			this.type = type;
		}
	}
}
