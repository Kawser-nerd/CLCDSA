package world2015.round3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class LogSet {

	public long[] solveForSmall(int P, long[] E, long[] F) {
		int sum = 0;
		for (int i=0; i<P; i++)
			sum += F[i];
		int n = 0;
		while (sum>1) {
			n++;
			sum /= 2;
		}
		long[] res = new long[n];
		int idx = 0;
		int fidx = 0;
		F[0]--;
		for (;;) {
			while (F[fidx]==0)
				fidx++;
			res[idx] = E[fidx];
			for (int s=0; s<(1<<idx); s++) {
				long ss = res[idx];
				for (int i=0; i<idx; i++) {
					if (((s>>i)&1)==1)
						ss += res[i];
				}
				int eidx = Arrays.binarySearch(E, ss);
				F[eidx]--;
			}
			idx++;
			if (idx==n)
				break;
		}
		return res;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round3/D-small-attempt0.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		int numProblems = nextInt(br);
		LogSet ls = new LogSet();
		for (int i=0; i<numProblems; i++) {
			int P = nextInt(br);
			long[] E = nextLongArray(br);
			long[] F = nextLongArray(br);
			long[] res = ls.solveForSmall(P, E, F);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ":");
			for (long a : res)
				sb.append(" " + a);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
	
	static int nextInt(BufferedReader br) throws IOException {
		return Integer.parseInt(br.readLine().trim());
	}
	
	static int[] nextIntArray(BufferedReader br) throws IOException {
		String[] tokens = br.readLine().trim().split(" ");
		int[] res = new int[tokens.length];
		for (int i=0; i<tokens.length; i++)
			res[i] = Integer.parseInt(tokens[i]);
		return res;
	}
	
	static String nextString(BufferedReader br) throws IOException {
		return br.readLine().trim();
	}
	
	static String[] nextStringArray(BufferedReader br) throws IOException {
		return br.readLine().trim().split(" ");
	}
	
	static long nextLong(BufferedReader br) throws IOException {
		return Long.parseLong(br.readLine().trim());
	}
	
	static long[] nextLongArray(BufferedReader br) throws IOException {
		String[] tokens = br.readLine().trim().split(" ");
		long[] res = new long[tokens.length];
		for (int i=0; i<tokens.length; i++)
			res[i] = Long.parseLong(tokens[i]);
		return res;
	}
	
	static double nextDouble(BufferedReader br) throws IOException {
		return Double.parseDouble(br.readLine().trim());
	}
	
	static double[] nextDoubleArray(BufferedReader br) throws IOException {
		String[] tokens = br.readLine().trim().split(" ");
		double[] res = new double[tokens.length];
		for (int i=0; i<tokens.length; i++)
			res[i] = Double.parseDouble(tokens[i]);
		return res;
	}
}
