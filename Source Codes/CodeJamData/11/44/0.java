import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		final int INF = 1000000000;
		
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("case " + caseNum);
			
			int N = sc.nextInt();
			int M = sc.nextInt();
			boolean[][] adj = new boolean[N][N];
			int[][] dist = new int[N][N];
			for (int i=0; i < N; i++)
				Arrays.fill(dist[i], INF);
			for (int i=0; i < N; i++)
				dist[i][i] = 0;
			for (int i=0; i < M; i++) {
				StringTokenizer st = new StringTokenizer(sc.next(), ",");
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				adj[a][b] = adj[b][a] = true;
				dist[a][b] = dist[b][a] = 1;
			}
			
			for (int k=0; k < N; k++)
				for (int i=0; i < N; i++)
					for (int j=0; j < N; j++)
						dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
			
			int D = dist[0][1];
			
			pw.print("Case #" + caseNum + ": " + (D-1) + " ");
			
			if (D == 1) {
				int cnt = 0;
				for (int i=0; i < N; i++)
					if (adj[0][i])
						cnt++;
				pw.println(cnt);
				continue;
			}
			
			int[] layerSz = new int[D+1];
			int[][] layer = new int[D+1][N];
			for (int i=0; i < N; i++)
				if (dist[0][i] + dist[i][1] == D) {
					int d = dist[0][i];
					layer[d][layerSz[d]++] = i;
				}
			
			int[][] F = new int[N][N];
			
			for (int i=0; i < N; i++)
				Arrays.fill(F[i], -INF);
			
			for (int i=0; i < layerSz[0]; i++)
				for (int j=0; j < layerSz[1]; j++) {
					int a = layer[0][i];
					int b = layer[1][j];
					
					if (!adj[a][b]) continue;
					
					int cnt = 0;
					for (int x=0; x < N; x++)
						if (x != a && x != b && (adj[a][x] || adj[b][x]))
							cnt++;
					F[a][b] = cnt;
				}
			
			for (int len=0; len + 2 < D; len++)
				for (int i=0; i < layerSz[len]; i++)
					for (int j=0; j < layerSz[len+1]; j++)
						for (int k=0; k < layerSz[len+2]; k++) {
							int a = layer[len][i];
							int b = layer[len+1][j];
							int c = layer[len+2][k];
							
							if (!adj[b][c]) continue;
							if (F[a][b] == -INF) continue;
							
							int newValue = F[a][b] - 1;
							for (int x=0; x < N; x++) {
								if (x == a || x == b || x == c) continue;
								if (adj[c][x] && !adj[b][x] && !adj[a][x]) newValue++;
							}
							
							F[b][c] = Math.max(F[b][c], newValue);
						}
			
			int res = -INF;
			
			for (int i=0; i < layerSz[D-2]; i++)
				for (int j=0; j < layerSz[D-1]; j++) {
					int a = layer[D-2][i];
					int b = layer[D-1][j];
					res = Math.max(res, F[a][b]);
				}
			
			pw.println(res);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
