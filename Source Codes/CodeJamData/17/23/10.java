import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int pp = 0; pp < N; pp++) {
			String[] ss = br.readLine().split(" ");

			int n = Integer.parseInt(ss[0]);
			int q = Integer.parseInt(ss[1]);

			int[] e = new int[n];
			int[] s = new int[n];
			for(int i = 0; i < n; i++) {
				ss = br.readLine().split(" ");
				e[i] = Integer.parseInt(ss[0]);
				s[i] = Integer.parseInt(ss[1]);
			}
			int[][] d = new int[n][n];
			for(int i = 0; i < n; i++) {
				ss = br.readLine().split(" ");
				for(int j = 0; j < n; j++) {
					d[i][j] = Integer.parseInt(ss[j]);
				}
			}

			int[] u = new int[q];
			int[] v = new int[q];
			for(int i = 0; i < q; i++) {
				ss = br.readLine().split(" ");
				u[i] = Integer.parseInt(ss[0]);
				v[i] = Integer.parseInt(ss[1]);
			}

			long[][] dists = apsp(d, n);

			double[][] dd = new double[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(i==j) dd[i][j] = -1.0;
					else {
						if(dists[i][j] <= e[i] && dists[i][j] >= 0) {
							dd[i][j] = dists[i][j]/((double)s[i]);
						} else {
							dd[i][j] = -1.0;
						}
					}
				}
			}

			double[][] rets = apsp(dd,n);

		//	for(int i = 0; i < n; i++) {
		//		System.out.println();
		//		for(int j = 0; j < n; j++) System.out.println(rets[i][j] + " ");
		//	}

			pw.print("Case #" + (pp+1) + ":");

			for(int i = 0; i < q; i++) {
				pw.print(" " + rets[u[i]-1][v[i]-1]);
			}
			pw.println();


		}


		pw.flush();
		pw.close();

	}

	public static long[][] apsp(int[][] e, int n) {
		long[][] dist = new long[n][n];

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i==j) dist[i][j] = 0;
				else dist[i][j] = e[i][j];
			}
		}

		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(dist[i][k] > -1 && dist[k][j] > -1 && (dist[i][j] == -1 || (dist[i][j] > dist[i][k] + dist[k][j]))) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		return dist;
	}

	public static double[][] apsp(double[][] e, int n) {
		double eps = 0.000000001;
		double[][] dist = new double[n][n];

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i==j) dist[i][j] = 0.0;
				else dist[i][j] = e[i][j];
			}
		}

		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(dist[i][k] >= 0.0-eps && dist[k][j] >= 0.0-eps && (dist[i][j] <= -1.0+eps || (dist[i][j] > dist[i][k] + dist[k][j]))) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		return dist;
	}
}