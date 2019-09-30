package world2014.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class FullBinaryTree {

	public int solve(int N, int[][] connection) {
		int[] cnt = new int[N];
		for (int i=0; i<connection.length; i++) {
			cnt[connection[i][0]]++;
			cnt[connection[i][1]]++;
		}
		int[][] connect = new int[N][];
		for (int i=0; i<N; i++)
			connect[i] = new int[cnt[i]];
		Arrays.fill(cnt, 0);
		for (int i=0; i<connection.length; i++) {
			int v1 = connection[i][0], v2 = connection[i][1];
			connect[v1][cnt[v1]++] = v2;
			connect[v2][cnt[v2]++] = v1;
		}
		memo = new int[N][N+1];
		num = new int[N][N+1];
		for (int i=0; i<N; i++) {
			Arrays.fill(memo[i], -1);
			Arrays.fill(num[i], -1);
		}
		int min = N;
		for (int i=0; i<N; i++)
			min = Math.min(min, this.dfs(N, connect, i, N));
		return min;
	}
	
	private int[][] memo;
	
	private int dfs(int N, int[][] connect, int idx, int parent) {
		if (memo[idx][parent]>=0)
			return memo[idx][parent];
		int num = connect[idx].length;
		if (parent<N)
			num--;
		if (num==0) {
			memo[idx][parent] = 0;
			return memo[idx][parent];
		}
		if (num==1) {
			int v = connect[idx][0];
			if (v==parent)
				v = connect[idx][1];
			memo[idx][parent] = this.num(connect, v, idx);
			return memo[idx][parent];
		}
		int min = N+1;
		int sum = 0;
		for (int i=0; i<connect[idx].length; i++)
			if (connect[idx][i]!=parent)
				sum += this.num(connect, connect[idx][i], idx);
		for (int i=0; i<connect[idx].length; i++) {
			if (connect[idx][i]==parent)
				continue;
			for (int j=i+1; j<connect[idx].length; j++) {
				if (connect[idx][j]==parent)
					continue;
				int n = sum-this.num(connect, connect[idx][i], idx)-this.num(connect, connect[idx][j], idx);
				n += this.dfs(N, connect, connect[idx][i], idx)+this.dfs(N, connect, connect[idx][j], idx);
				min = Math.min(min, n);
			}
		}
		memo[idx][parent] = min;
		return memo[idx][parent];
	}
	
	private int[][] num;
	
	private int num(int[][] connect, int idx, int parent) {
		if (num[idx][parent]>=0)
			return num[idx][parent];
		int res = 0;
		for (int i=0; i<connect[idx].length; i++)
			if (connect[idx][i]!=parent)
				res += this.num(connect, connect[idx][i], idx);
		num[idx][parent] = res+1;
		return num[idx][parent];
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2014/round1a/B-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			int N = Integer.parseInt(line);
			int[][] connection = new int[N-1][2];
			for (int j=0; j<N-1; j++) {
				String[] split = br.readLine().trim().split(" ");
				connection[j][0] = Integer.parseInt(split[0])-1;
				connection[j][1] = Integer.parseInt(split[1])-1;
			}
			int res = new FullBinaryTree().solve(N, connection);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
