package world2014.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;

public class ChargingChaos {

	private BipartiteMatching bm = new BipartiteMatching();
	
	public int solveForSmall(int N, int L, long[] e, long[] d) {
		int min = L+1;
		for (int i=0; i<(1<<L); i++) {
			if (this.checkForSmall(N, L, e, d, i))
				min = Math.min(min, this.countBit(i));
		}
		return min==L+1?-1:min;
	}
	
	private boolean checkForSmall(int N, int L, long[] e, long[] d, int s) {
		boolean[][] match = new boolean[N][N];
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++) {
				if ((e[j]^s)==d[i])
					match[i][j] = true;
			}
		return bm.maxMatching(match)==N;
	}
	
	private int countBit(int n) {
		n = (0x55555555&n) + (0x55555555&(n>>1));
		n = (0x33333333&n) + (0x33333333&(n>>2));
		n = (0x0F0F0F0F&n) + (0x0F0F0F0F&(n>>4));
		n = (0x00FF00FF&n) + (0x00FF00FF&(n>>8));
		return (0x0000FFFF&n) + (0x0000FFFF&(n>>16));
	}
	
	public class BipartiteMatching {

		private static final int INF = 1000000000;

		public int maxMatching(boolean[][] match) {
			int m = match.length;
			int n = match[0].length;
			int[][] cap = new int[m+n+2][m+n+2];
			for (int i=0; i<m; i++)
				for (int j=0; j<n; j++)
					if (match[i][j])
						cap[i][m+j] = 1;
			int s = m+n, t = m+n+1;
			for (int i=0; i<m; i++)
				cap[s][i] = 1;
			for (int i=0; i<n; i++)
				cap[m+i][t] = 1;
			return this.maxflow(cap, s, t);
		}

		public int maxflow(int[][] cap, int s, int t) {
			int n = cap.length;
			int[][] capcopy = new int[n][n];
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					capcopy[i][j] = cap[i][j];
			int[][] connection = new int[n][];
			for (int i=0; i<n; i++) {
				int cnt = 0;
				for (int j=0; j<n; j++)
					if (cap[i][j]>0 || cap[j][i]>0)
						cnt++;
				connection[i] = new int[cnt];
				cnt = 0;
				for (int j=0; j<n; j++)
					if (cap[i][j]>0 || cap[j][i]>0)
						connection[i][cnt++] = j;
			}
			int flow = 0;
			int[] iter = new int[n];
			for (;;) {
				int[] dist = this.bfs(capcopy, connection, s);
				if (dist[t]<0)
					return flow;
				Arrays.fill(iter, 0);
				int f;
				while ((f=this.dfs(capcopy, connection, dist, iter, INF, s, t))>0)
					flow += f;
			}
		}

		private int[] bfs(int[][] cap, int[][] connection, int s) {
			int[] dist = new int[cap.length];
			Arrays.fill(dist, -1);;
			PriorityQueue<Integer> que = new PriorityQueue<Integer>();
			dist[s] = 0;
			que.add(s);
			while (que.size()>0) {
				int v = que.poll();
				for (int i=0; i<connection[v].length; i++) {
					int vv = connection[v][i];
					if (cap[v][vv]>0 && dist[vv]<0) {
						dist[vv] = dist[v]+1;
						que.add(vv);
					}
				}
			}
			return dist;
		}

		private int dfs(int[][] cap, int[][] connection, int[] dist, int[] iter, int max, int v, int t) {
			if (v==t)
				return max;
			for (; iter[v]<connection[v].length; iter[v]++) {
				int vv = connection[v][iter[v]];
				if (cap[v][vv]>0 && dist[v]<dist[vv]) {
					int f = this.dfs(cap, connection, dist, iter, Math.min(max, cap[v][vv]), vv, t);
					if (f>0) {
						cap[v][vv] -= f;
						cap[vv][v] += f;
						return f;
					}
				}
			}
			return 0;
		}
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2014/round1a/A-small-attempt0.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			String[] split = line.split(" ");
			int N = Integer.parseInt(split[0]);
			int L = Integer.parseInt(split[1]);
			long[] e = new long[N];
			split = br.readLine().trim().split(" ");
			for (int j=0; j<N; j++)
				e[j] = Integer.parseInt(split[j], 2);
			long[] d = new long[N];
			split = br.readLine().trim().split(" ");
			for (int j=0; j<N; j++)
				d[j] = Integer.parseInt(split[j], 2);
			int res = new ChargingChaos().solveForSmall(N, L, e, d);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": ");
			if (res>=0)
				sb.append(res);
			else
				sb.append("NOT POSSIBLE");
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
