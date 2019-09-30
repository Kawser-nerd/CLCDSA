import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemD {
	public static void main(String[] args) throws Exception {
		new ProblemD();
	}

	public ProblemD() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-d.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-d.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			height = scan.nextInt();
			width = scan.nextInt();
			int rocks = scan.nextInt();
			map = new boolean[height][width];
			for ( boolean[] a: map) Arrays.fill(a, false);
			for ( int i  = 0; i < rocks; i++) {
				int r = scan.nextInt() -1;
				int c = scan.nextInt() -1;
				map[r][c]	= true;
			}
			memo = new int[height][width];
			for ( int[] a: memo) Arrays.fill(a,-1);
			int result = go ( height-1, width-1);
			String answer = String.format("Case #%d: %d\n", test + 1, result);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
	
	public int go( int row, int col) {
		if ( row < 0 || col < 0 ) return 0;
		if ( memo[row][col] >= 0) return memo[row][col];
		if ( map[row][col] ) return memo[row][col] = 0;
		if ( row == 0 && col == 0) return memo[row][col] = 1;
		int result = go(row-2, col-1) + go(row-1, col-2);
		result %= MOD;
		return memo[row][col] = result;
	}
	
	int height, width;
	boolean[][] map;
	int MOD = 10007;
	int[][] memo;
}
