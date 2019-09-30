package world2014.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

public class ProperShuffle {

	private static final int ATTEMPT_NUM = 1000000;
	
	private static final String GOOD = "GOOD";
	private static final String BAD = "BAD";
	
	private int N;
	private double[][] goodp;
	private double[][] badp;
	private Random random = new Random();
	
	public ProperShuffle(int N) {
		this.N = N;
		goodp = new double[N][N];
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				goodp[i][j] = 1.0/N;
		int[][] num = new int[N][N];
		int[] a = new int[N];
		for (int i=0; i<N; i++)
			a[i] = i;
		for (int i=0; i<ATTEMPT_NUM; i++)
			this.badPermutation(N, a, 0, num);
		badp = new double[N][N];
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				badp[i][j] = num[i][j]/(double)ATTEMPT_NUM;
	}
	
	private void badPermutation(int N, int[] a, int idx, int[][] num) {
		if (idx==N) {
			for (int i=0; i<N; i++)
				num[a[i]][i]++;
			return;
		}
		int rand = random.nextInt(N);
		int tmp = a[rand];
		a[rand] = a[idx];
		a[idx] = tmp;
		badPermutation(N, a, idx+1, num);
		a[idx] = a[rand];
		a[rand] = tmp;
	}
	
	public String solve(int N, int[] permutation) {
		double gl = this.logLikelihood(N, permutation, goodp);
		double bl = this.logLikelihood(N, permutation, badp);
		if (gl>bl)
			return GOOD;
		else
			return BAD;
	}
	
	private double logLikelihood(int N, int[] permutation, double[][] p) {
		double res = 0.0;
		for (int i=0; i<N; i++)
			res += Math.log(p[permutation[i]][i]);
		return res;
	}
	
	public static void main(String args[]) throws IOException {
		ProperShuffle ps = null;
		String inputPath = "file/world2014/round1a/C-small-attempt1.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			int N = Integer.parseInt(line);
			if (ps==null || N!=ps.N)
				ps = new ProperShuffle(N);
			int[] permutation = new int[N];
			String[] split = br.readLine().trim().split(" ");
			for (int j=0; j<N; j++)
				permutation[j] = Integer.parseInt(split[j]);
			String res = ps.solve(N, permutation);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
