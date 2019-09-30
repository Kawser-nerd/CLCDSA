import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C
{
	static void floyd(long[][] mat) {
		int N = mat.length;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) mat[j][k] = Math.min(mat[j][k], mat[j][i] + mat[i][k]);
	}
	static void floyd(double[][] mat) {
		int N = mat.length;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) mat[j][k] = Math.min(mat[j][k], mat[j][i] + mat[i][k]);
	}
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		long M = (long)(1e9);
		for (int t = 0; t < T; ++t) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken()), Q = Integer.parseInt(st.nextToken());
			long[][] horses = new long[N][2];
			for (int i = 0; i < N; ++i) {
				st = new StringTokenizer(in.readLine());
				horses[i][0] = Long.parseLong(st.nextToken());
				horses[i][1] = Long.parseLong(st.nextToken());
			}
			long[][] dmat = new long[N][N];
			for (int i = 0; i < N; ++i) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < N; ++j) {
					dmat[i][j] = Long.parseLong(st.nextToken());
					if (dmat[i][j] == -1) dmat[i][j] = M+1;
					if (i == j) dmat[i][j] = 0;
				}
			}
			floyd(dmat);
			double[][] tmat = new double[N][N];
			for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
				tmat[i][j] = dmat[i][j] > horses[i][0] ? Double.POSITIVE_INFINITY : dmat[i][j]*1.0/horses[i][1];
			}
			floyd(tmat);
			StringBuilder ret = new StringBuilder();
			ret.append("Case #").append(t+1).append(":");
			for (int q = 0; q < Q; ++q) {
				st = new StringTokenizer(in.readLine());
				int u = Integer.parseInt(st.nextToken())-1, v = Integer.parseInt(st.nextToken())-1;
				ret.append(' ').append(tmat[u][v]);
			}
			System.out.println(ret.toString());
		}
	}
}
