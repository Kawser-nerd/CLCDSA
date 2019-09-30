import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class D {

	public static void main(String... args) throws Exception {
		configure();

		int casos = Integer.parseInt(in.readLine());
		for (int casito = 1; casito <= casos; casito++) {
			Object o = new D().solve();

			out.println("Case #" + casito + ": " + o);
			System.out.println("Case #" + casito + ": " + o);
		}
		out.close();
	}

	String RICHARD = "RICHARD";
	String GABRIEL = "GABRIEL";

	private Object solve() throws Exception {
		int x = ni();
		int r = ni();
		int c = ni();

		if (x >= 7)
			return RICHARD;

		if ((r * c) % x != 0)
			return RICHARD;
		List<boolean[][]> ominos = getOminos(x);

		for (boolean[][] bss : ominos) {
//			print(bss);
//			System.out.println(tryOmino(bss, x, r, c));
//			System.out.println();
//			
//			print(rotate(bss));
//			System.out.println(tryOmino(rotate(bss), x, r, c));
//			System.out.println("------------------");
			if (tryOmino(bss, x, r, c) && tryOmino(rotate(bss), x, r, c)) {
				return RICHARD;
			}
		}
		return GABRIEL;
	}

	private boolean[][] rotate(boolean[][] bss) {
		int n = bss.length;
		int m = bss[0].length;
		boolean[][] ret = new boolean[m][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ret[j][i] = bss[i][j];
		return ret;
	}

	private boolean tryOmino(boolean[][] bss, int x, int r, int c) {
		int n = bss.length;
		int m = bss[0].length;

		for (int i = 0; i + n <= r; i++)
			for (int j = 0; j + m <= c; j++) {
				boolean[][] matrix = new boolean[r][c];
				for (int ii = 0; ii < n; ii++)
					for (int jj = 0; jj < m; jj++) {
						matrix[i + ii][j + jj] |= bss[ii][jj];
					}
				if (!check(matrix, x)) {
					return false;
				}
			}
		return true;
	}

	private boolean check(boolean[][] matrix, int x) {
		int n = matrix.length;
		int m = matrix[0].length;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!matrix[i][j]) {
					if (dfs(matrix, i, j) % x != 0)
						return true;

				}
		return false;
	}

	private int dfs(boolean[][] matrix, int r, int c) {
		int ret = 1;
		matrix[r][c] = true;
		for (int k = 0; k < 4; k++) {
			int rr = r + dr[k];
			int cc = c + dc[k];
			if (0 <= rr && rr < matrix.length && 0 <= cc
					&& cc < matrix[0].length && !matrix[rr][cc]) {
				ret += dfs(matrix, rr, cc);
			}
		}
		return ret;
	}

	private void print(boolean[][] bss) {
		for (boolean[] bs : bss) {
			for (boolean b : bs) {
				if (b) {
					System.out.print(1);
				} else {
					System.out.print(0);
				}
			}
			System.out.println();

		}
	}

	static int[] dr = { 0, 1, 0, -1 };
	static int[] dc = { 1, 0, -1, 0 };

	private List<boolean[][]> getOminos(int x) {
		Set<Omino> curr = new HashSet<Omino>();
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++) {
				Omino om = new Omino();
				om.set(i, j);
				curr.add(om);
			}
		Set<Omino> next = new HashSet<Omino>();
		for (int iter = 2; iter <= x; iter++) {
			for (Omino o : curr) {
				for (int r = 0; r < 6; r++)
					for (int c = 0; c < 6; c++) {
						Omino toAdd = o.maybeAdd(r, c);
						if (toAdd != null) {
							next.add(toAdd);
						}
					}
			}
			Set<Omino> tmp = curr;
			curr = next;
			next = tmp;
			next.clear();
		}
		List<boolean[][]> ret = new ArrayList<boolean[][]>();
		for (Omino o : curr) {
			boolean[][] check = o.toBooleanMatrix();
			if (check != null) {
				ret.add(check);
			}
		}
		return ret;
	}

	static class Omino {
		private int[] arr;

		public Omino() {
			this.arr = new int[6];
		}

		public Omino(int[] arr) {
			this.arr = arr.clone();
		}

		public void set(int r, int c) {
			this.arr[r] |= 1 << c;
		}

		public Omino maybeAdd(int r, int c) {
			if ((arr[r] & (1 << c)) != 0) {
				return null;
			}
			for (int k = 0; k < 4; k++) {
				int rr = r + dr[k];
				int cc = c + dc[k];

				if (0 <= rr && rr < 6 && 0 <= cc && cc < 6
						&& (arr[rr] & (1 << cc)) != 0) {
					Omino ret = new Omino(this.arr);
					ret.set(r, c);
					return ret;
				}
			}
			return null;
		}

		public boolean[][] toBooleanMatrix() {
			if (arr[0] == 0)
				return null;
			boolean any = false;
			for (int c = 0; c < 6; c++) {
				if ((arr[0] & 1) == 1)
					any = true;
			}
			if (!any)
				return null;
			int n = 0;
			int m = 0;
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					if ((arr[i] & 1 << j) != 0) {
						n = Math.max(n, i + 1);
						m = Math.max(m, j + 1);
					}
			boolean[][] ret = new boolean[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					ret[i][j] = (arr[i] & (1 << j)) != 0;
				}
			return ret;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(arr);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			Omino other = (Omino) obj;
			return Arrays.equals(arr, other.arr);
		}

	}

	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "D"; //
	static String loc = "/home/miguel/workspace/CodeJam/qualy/src"; //

	static void configure() throws Exception {

		File file = new File(loc);
		File[] paths = file.listFiles();
		List<File> input = new ArrayList<File>();
		for (File f : paths) {
			String s = f.getName();
			if (s.startsWith(name_class) && s.endsWith(".in"))
				input.add(f);
		}

		if (input.isEmpty()) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		} else {
			File last_file = input.get(0);
			for (File f : input) {
				if (f.lastModified() > last_file.lastModified())
					last_file = f;
			}

			in = new BufferedReader(new FileReader(last_file.toString()));
			System.err.println("LEYENDO DE ARCHIVO");

		}
		FileWriter fw = new FileWriter(loc + "/output.txt");
		out = new PrintWriter(fw);

	}

	static StringTokenizer strTok = new StringTokenizer("");

	static String nextToken() throws IOException {
		while (!strTok.hasMoreTokens())
			strTok = new StringTokenizer(in.readLine());
		return strTok.nextToken();
	}

	static int ni() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nl() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nd() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int[] nia(int size) throws IOException {
		int[] ret = new int[size];
		for (int i = 0; i < size; i++)
			ret[i] = ni();
		return ret;
	}

	static long[] nla(int size) throws IOException {
		long[] ret = new long[size];
		for (int i = 0; i < size; i++)
			ret[i] = nl();
		return ret;
	}

	static double[] nda(int size) throws IOException {
		double[] ret = new double[size];
		for (int i = 0; i < size; i++)
			ret[i] = nd();
		return ret;
	}

}