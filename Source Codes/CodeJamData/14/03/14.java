import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static BufferedReader in;
	public static PrintWriter out;

	public static void main(String... args) throws Exception {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			System.err.println("LEYENDO DE ARCHIVO");
		} catch (Exception e) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		}
		out = new PrintWriter("output.txt");

		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) {
			out.println("Case #" + i + ":");
			solve();
		}
		out.close();
	}

	private static void solve() throws Exception {
		int R = ni();
		int C = ni();
		int M = ni();

		if (R == 1) {
			out.print('c');
			for (int i = 1; i < C - M; i++)
				out.print('.');
			for (int i = 0; i < M; i++)
				out.print('*');
			out.println();
			return;
		}

		if (C == 1) {
			out.println('c');
			for (int i = 1; i < R - M; i++)
				out.println('.');
			for (int i = 0; i < M; i++)
				out.println('*');
			return;
		}
		int REM = R*C - M;
		if(REM ==1){
			char[][] matrix = new char[R][C];
			for(char[] cs : matrix)
				Arrays.fill(cs, '*');
			matrix[0][0]='c';
			for(char[] cs : matrix)
				out.println(new String(cs));
			return;
		}
		if (REM <= 3) {
			out.println("Impossible");
			return;
		}

		for (int r = 2; r <= R; r++)
			for (int c = 2; c <= C; c++) {
				int borde = r + c - 1;
				int min_zero = r + c - 3;
				int max_zero = (r - 1) * (c - 1);
				if(borde+min_zero<= REM && REM<= borde+max_zero){
					char[][] matrix = new char[R][C];
					for(char[] cs : matrix)
						Arrays.fill(cs, '*');
					
					for(int i =0;i<r-1;i++)
						matrix[i][0]='.';
					for(int j =0;j<c-1;j++)
						matrix[0][j]='.';
					int rem = REM - borde - min_zero;
					for(int i=1;i<r-1 && rem>0;i++)
						for(int j =1;j<c-1 && rem>0;j++){
							matrix[i][j]='.';
							rem--;
						}
					for(int i =0;i<R;i++)
						for(int j =0;j<C;j++)
							if(neigh(matrix,i,j))
								matrix[i][j]='X';
					
					for(int i =0;i<R;i++)
						for(int j =0;j<C;j++)
							if(matrix[i][j]=='X')
								matrix[i][j]='.';
					matrix[0][0]='c';
					for(char[] cs : matrix)
						out.println(new String(cs));
					return;
							
				}
			}
		out.println("Impossible");
	}

	static int[] dr = {0,1,1,1,0,-1,-1,-1};
	static int[] dc = {1,1,0,-1,-1,-1,0,1}; 	
	
	private static boolean neigh(char[][] matrix, int i, int j) {
		if(matrix[i][j]=='.')
			return false;
		int n = matrix.length;
		int m = matrix[0].length;
		
		for(int k =0;k<8;k++){
			int r = i+dr[k];
			int c = j+dc[k];
			if(0<=r && r < n && 0<=c && c<m && matrix[r][c]=='.')
				return true;
		}
			
		return false;
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
