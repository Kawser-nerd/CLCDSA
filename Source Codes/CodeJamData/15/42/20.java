package world2015.round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class KiddiePool {

	public double solve(int N, double V, double X, double[] R, double[] C) {
		boolean upper = false, lower = false;
		for (int i=0; i<N && !(upper && lower); i++) {
			if (C[i]>=X)
				upper = true;
			if (C[i]<=X)
				lower = true;
		}
		if (!(upper && lower))
			return -1.0;
		WaterSource[] wss = new WaterSource[N];
		for (int i=0; i<N; i++)
			wss[i] = new WaterSource(i, R[i], C[i]);
		Arrays.sort(wss);
		for (int i=0; i<N-1; i++)
			if (wss[i].C==wss[i+1].C) {
				wss[i+1].R += wss[i].R;
				wss[i].R = 0;
			}
		double left = 0.0, right = 1000000000.0;
		for (int i=0; i<10000; i++) {
			double mid = (left+right)/2.0;
			if (possible(N, V, X, wss, mid))
				right = mid;
			else
				left = mid;
		}
		return left;
	}
	
	private boolean possible(int N, double V, double X, WaterSource[] wss, double t) {
		double min = 0.0;
		double v = V;
		int idx = 0;
		while (idx<wss.length && v>0.0) {
			if (t*wss[idx].R<=v) {
				min += t*wss[idx].R*wss[idx].C;
				v -= t*wss[idx].R;
			} else {
				min += v*wss[idx].C;
				v = 0.0;
			}
			idx++;
		}
		if (v>0.0)
			return false;
		double max = 0.0;
		v = V;
		idx = wss.length-1;
		while (idx>=0 && v>0.0) {
			if (t*wss[idx].R<=v) {
				max += t*wss[idx].R*wss[idx].C;
				v -= t*wss[idx].R;
			} else {
				max += v*wss[idx].C;
				v = 0.0;
			}
			idx--;
		}
		return min<=V*X && V*X<=max;
	}
	
	private class WaterSource implements Comparable<WaterSource> {
		
		private int id;
		private double R, C;
		
		private WaterSource(int id, double R, double C) {
			this.id = id;
			this.R = R;
			this.C = C;
		}
		
		@Override
		public int compareTo(WaterSource ws) {
			if (C<ws.C)
				return -1;
			else if (C>ws.C)
				return 1;
			else if (R<ws.R)
				return -1;
			else if (R>ws.R)
				return 1;
			else
				return id-ws.id;
		}
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round2/B-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			int N = Integer.parseInt(tokens[0]);
			double V = Double.parseDouble(tokens[1]);
			double X = Double.parseDouble(tokens[2]);
			double[] R = new double[N];
			double[] C = new double[N];
			for (int j=0; j<N; j++) {
				tokens = br.readLine().trim().split(" ");
				R[j] = Double.parseDouble(tokens[0]);
				C[j] = Double.parseDouble(tokens[1]);
			}
			double res = new KiddiePool().solve(N, V, X, R, C);
			StringBuilder sb = new StringBuilder();
			if (res>=0.0)
				sb.append("Case #" + (i+1) + ": " + res);
			else
				sb.append("Case #" + (i+1) + ": IMPOSSIBLE");
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
