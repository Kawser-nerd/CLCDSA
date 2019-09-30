import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c {
	public static int[] des;
	public static int c;
	public static int r;
	public static PrintWriter out;

	public static void main(String[] Args) throws Exception {
		FS sc = new FS(new File("C-small-attempt0.in"));
		// FS sc = new FS(System.in);
		// out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
		// System.out)));
		out = new PrintWriter(new BufferedWriter(new FileWriter(new File(
				"c.out"))));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			out.printf("Case #%d:%n", ++cc);
			r = sc.nextInt();
			c = sc.nextInt();
			int tot = (r + c) * 2;
			int[] vals = new int[(r + c) * 2];
			des = new int[(r + c) * 2];
			for (int i = 0; i < (r + c); i++) {
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				des[a] = b;
				des[b] = a;
			}
			int ans = -1;
			for (int i = 0; i < (1 << (r * c)); i++) {
				if (check(i)) {
					ans = i;
					break;
				}
			}
			if (ans == -1)
				out.println("IMPOSSIBLE");
			else {
				print(ans);
			}
		}
		out.close();
	}

	public static void print(int ans) {

		int we = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((ans & (1 << we)) != 0)
					out.print("\\");
				else
					out.print("/");
				we++;
			}
			out.println();
		}
	}

	public static int[] dy = { 1, 0, 0, -1 };
	public static int[] dx = { 0, 1, -1, 0 };

	public static boolean check(int val) {
		int[][] st = new int[r + 2][c + 2];
		int[][] things = new int[r + 2][c + 2];
		for (int[] iiii : st)
			Arrays.fill(iiii, -1);
		int[] stx = new int[(r + c) * 2];
		int[] sty = new int[(r + c) * 2];
		int cc = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				things[i + 1][j + 1] = ((val & (1 << cc)) != 0) ? 1 : 0;
				cc++;
			}
		}

		cc = 0;
		for (int i = 0; i < c; i++) {
			st[0][i + 1] = cc;
			sty[cc] = i + 1;
			stx[cc] = 0;
			cc++;
		}
		for (int i = 0; i < r; i++) {
			st[i + 1][c + 1] = cc;
			sty[cc] = c + 1;
			stx[cc] = i + 1;
			cc++;
		}
		for (int i = c; i > 0; i--) {
			st[r + 1][i] = cc;
			sty[cc] = i;
			stx[cc] = r + 1;
			cc++;
		}
		for (int i = r; i > 0; i--) {
			st[i][0] = cc;
			sty[cc] = 0;
			stx[cc] = i;
			cc++;
		}
		cc = 0;
		for (int i = 0; i < c; i++) {
			int cx = stx[cc];
			int cy = sty[cc];
			int cd = 1;
			while (st[cx][cy] == -1 || st[cx][cy] == cc) {
				int nx = cx + dx[cd];
				int ny = cy + dy[cd];
				if (things[nx][ny] != 0)
					cd ^= 1;
				else
					cd ^= 2;
				cx = nx;
				cy = ny;
			}
			if (des[cc] != st[cx][cy])
				return false;
			cc++;
		}

		for (int i = 0; i < r; i++) {
			int cx = stx[cc];
			int cy = sty[cc];
			int cd = 3;

			while (st[cx][cy] == -1 || st[cx][cy] == cc) {
				int nx = cx + dx[cd];
				int ny = cy + dy[cd];
				if (things[nx][ny] != 0)
					cd ^= 1;
				else
					cd ^= 2;
				cx = nx;
				cy = ny;
			}
			if (des[cc] != st[cx][cy])
				return false;
			cc++;
		}

		for (int i = 0; i < c; i++) {
			int cx = stx[cc];
			int cy = sty[cc];
			int cd = 2;

			while (st[cx][cy] == -1 || st[cx][cy] == cc) {
				int nx = cx + dx[cd];
				int ny = cy + dy[cd];
				if (things[nx][ny] != 0)
					cd ^= 1;
				else
					cd ^= 2;
				cx = nx;
				cy = ny;
			}
			if (des[cc] != st[cx][cy])
				return false;
			cc++;
		}

		for (int i = 0; i < r; i++) {
			int cx = stx[cc];
			int cy = sty[cc];
			int cd = 0;

			while (st[cx][cy] == -1 || st[cx][cy] == cc) {
				int nx = cx + dx[cd];
				int ny = cy + dy[cd];
				if (things[nx][ny] != 0)
					cd ^= 1;
				else
					cd ^= 2;
				cx = nx;
				cy = ny;
			}
			if (des[cc] != st[cx][cy])
				return false;
			cc++;
		}

		return true;
	}

	public static class FS {
		BufferedReader br;
		StringTokenizer st;

		FS(InputStream in) throws Exception {
			br = new BufferedReader(new InputStreamReader(in));
			st = new StringTokenizer(br.readLine());
		}

		FS(File in) throws Exception {
			br = new BufferedReader(new FileReader(in));
			st = new StringTokenizer(br.readLine());
		}

		String next() throws Exception {
			if (st.hasMoreTokens())
				return st.nextToken();
			st = new StringTokenizer(br.readLine());
			return next();
		}

		int nextInt() throws Exception {
			return Integer.parseInt(next());
		}
	}
}
