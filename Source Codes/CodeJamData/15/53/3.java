package world2015.round3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;

public class RunawayQuail {

	public double solveForSmall(int Y, int N, int[] P, int[] S) {
		Quail[] qs = new Quail[N];
		for (int i=0; i<N; i++)
			qs[i] = new Quail(i, P[i], S[i]);
		PriorityQueue<Quail> lque = new PriorityQueue<>();
		PriorityQueue<Quail> rque = new PriorityQueue<>();
		for (int i=0; i<N; i++)
			if (qs[i].p<0)
				lque.add(qs[i]);
			else
				rque.add(qs[i]);
		return solveForSmall(lque, rque, 0.0, 0.0, Y);
	}
	
	private double solveForSmall(PriorityQueue<Quail> lque, PriorityQueue<Quail> rque, double t, double p, double y) {
		if (lque.size()==0 && rque.size()==0)
			return t;
		double min = -1.0;
		if (lque.size()>0) {
			PriorityQueue<Quail> que = new PriorityQueue<>();
			for (Quail q : lque) {
				q.setT(t, p, y);
				que.add(q);
			}
			Quail q = que.poll();
			double tt = solveForSmall(que, rque, q.t, q.p + q.s*q.t, y);
			if (min<0 || tt<min)
				min = tt;
		}
		if (rque.size()>0) {
			PriorityQueue<Quail> que = new PriorityQueue<>();
			for (Quail q : rque) {
				q.setT(t, p, y);
				que.add(q);
			}
			Quail q = que.poll();
			double tt = solveForSmall(lque, que, q.t, q.p + q.s*q.t, y);
			if (min<0 || tt<min)
				min = tt;
		}
		return min;
	}
	
	class Quail implements Comparable<Quail> {
		
		int id;
		int p, s;
		double t;
		
		Quail(int id, int p, int s) {
			this.id = id;
			this.p = p;
			this.s = s;
			if (p<0)
				this.s *= -1;
		}
		
		void setT(double t, double p, double y) {
			double pp = this.p + t*s;
			this.t = t + Math.abs(p-pp)/Math.abs(y-Math.abs(s));
		}
		
		@Override
		public int compareTo(Quail quail) {
			if (t<quail.t)
				return -1;
			else if (t>quail.t)
				return 1;
			else
				return id-quail.id;
		}
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round3/C-small-attempt1.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		int numProblems = nextInt(br);
		RunawayQuail rq = new RunawayQuail();
		for (int i=0; i<numProblems; i++) {
			int[] YN = nextIntArray(br);
			int Y = YN[0], N = YN[1];
			int[] P = nextIntArray(br);
			int[] S = nextIntArray(br);
			double res = rq.solveForSmall(Y, N, P, S);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
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
