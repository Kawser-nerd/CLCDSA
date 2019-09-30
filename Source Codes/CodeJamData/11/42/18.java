import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in; static int next() throws Exception {return in.nextInt();};
	static BufferedReader in; //static int next() throws Exception {in.nextToken(); return (int) in.nval;}
	static PrintWriter out;
	static String NAME = "b";

	public static void main(String[] args) throws Exception {
//		in = new Scanner(new File(NAME + ".in"));
		out = new PrintWriter(new File(NAME + ".out"));
		in = new BufferedReader(new FileReader(new File(NAME + ".in")));
		
		int tests = Integer.parseInt(in.readLine());

		for (int test = 1; test <= tests; test++) {
			String[] vars = in.readLine().split(" ");
			int r = Integer.parseInt(vars[0]);
			int c = Integer.parseInt(vars[1]);
			int[][] m = new int[r][c];
			for (int i = 0; i < r; i++) {
				String s = in.readLine();
				for (int j = 0; j < c; j++) m[i][j] = s.charAt(j) - '0';
			}

			int[][] mp = new int[r + 1][c + 1];
			for (int i = 1; i <= r; i++) for (int j = 0; j < c; j++) mp[i][j + 1] = mp[i][j] + m[i - 1][j];
			int[][] mm = new int[r + 1][c + 1];
			for (int i = 0; i < r; i++) for (int j = 0; j <= c; j++) mm[i + 1][j] = mm[i][j] + mp[i + 1][j];

			int[][] mxp = new int[r + 1][c + 1];
			for (int i = 1; i <= r; i++) for (int j = 0; j < c; j++) mxp[i][j + 1] = mxp[i][j] + (i - 1) * m[i - 1][j];
			int[][] mmx = new int[r + 1][c + 1];
			for (int i = 0; i < r; i++) for (int j = 0; j <= c; j++) mmx[i + 1][j] = mmx[i][j] + mxp[i + 1][j];

			int[][] myp = new int[r + 1][c + 1];
			for (int i = 1; i <= r; i++) for (int j = 0; j < c; j++) myp[i][j + 1] = myp[i][j] + (j) * m[i - 1][j];
			int[][] mmy = new int[r + 1][c + 1];
			for (int i = 0; i < r; i++) for (int j = 0; j <= c; j++) mmy[i + 1][j] = mmy[i][j] + myp[i + 1][j];

/*			for (int i = 0; i <= r; i++) {
				for (int j = 0; j <= c; j++) out.print(mm[i][j] + " ");
				out.println();
			}
			out.println();

			for (int i = 0; i <= r; i++) {
				for (int j = 0; j <= c; j++) out.print(mmx[i][j] + " ");
				out.println();
			}
			out.println();

			for (int i = 0; i <= r; i++) {
				for (int j = 0; j <= c; j++) out.print(mmy[i][j] + " ");
				out.println();
			}
			out.println();*/

			int max = -1;
			for (int k = 2; k <= Math.min(r, c); k++)
				for (int x = 0; x + k <= r; x++) for (int y = 0; y + k <= c; y++) {
					if ((2*(mmx[x + k][y + k] + mmx[x][y] - mmx[x][y + k] - mmx[x + k][y] - x * m[x][y] - (x + k - 1) * m[x + k - 1][y] - x * m[x][y + k - 1] - (x + k - 1) * m[x + k - 1][y + k - 1]) == 
						(mm[x + k][y + k] + mm[x][y] - mm[x][y + k] - mm[x + k][y] - m[x][y] - m[x + k - 1][y] - m[x][y + k - 1] - m[x + k - 1][y + k - 1])*(x + x + k - 1)) &&
						(2*(mmy[x + k][y + k] + mmy[x][y] - mmy[x][y + k] - mmy[x + k][y] - y * m[x][y] - y * m[x + k - 1][y] - (y + k - 1) * m[x][y + k - 1] - (y + k - 1) * m[x + k - 1][y + k - 1]) == 
						(mm[x + k][y + k] + mm[x][y] - mm[x][y + k] - mm[x + k][y] - m[x][y] - m[x + k - 1][y] - m[x][y + k - 1] - m[x + k - 1][y + k - 1])*(y + y + k - 1))) max = k;
				}


			if (max > 2) out.println("Case #" + test + ": " + max);
			else out.println("Case #" + test + ": IMPOSSIBLE");
			System.out.println(test);
		}

		
		out.close();
	}
}