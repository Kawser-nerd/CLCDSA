import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemC {
	public static void main(String[] args) throws Exception {
		new ProblemC();
	}

	public ProblemC() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-c.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-c.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			height = scan.nextInt();
			width = scan.nextInt();
			map = new int[height];
			for ( int r = 0; r < height; r++ ) {
				String s = scan.next();
				int mask = 0;
				for ( int c = 0; c < width; c++) {
					if ( s.charAt(c) == 'x') mask |= (1 << c);
				}
				map[r] = mask;
			}
			ArrayList<Integer> list = new ArrayList<Integer>();
			for ( int mask = 0; mask < (1<<width); mask++) {
				boolean ok = true;
				ok &= (mask & (mask<<1)) == 0;
				ok &= (mask & (mask>>1)) == 0;
				if ( ok) list.add(mask);
			}
			choice = new int[list.size()];
			int index = 0;
			for ( int a: list) choice[index++] = a;
			memo = new int[height][1<<width];
			for ( int[] a : memo )Arrays.fill(a,-1);
			ALL = (1<<width) -1;
			int result = go(0,0);

			String answer = String.format("Case #%d: %d\n", test + 1,result);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
	
	public int go(int row, int mask) {
		if ( row == height) return 0;
		if ( memo[row][mask] >= 0 ) return memo[row][mask];
		int result = 0;
		int nmask, z;
		for ( int c: choice) {
			if ( (mask&c) != 0) continue;
			if ( (c&map[row] ) != 0 ) continue;
			nmask = ( c << 1) | ( c >> 1);
			nmask &= ALL;
			z = Integer.bitCount(c) + go( row+1, nmask);
			if ( z > result) result = z;
		}
		return memo[row][mask] = result;
	}
	int ALL;
	int[][] memo;
	int[] choice;
	int height, width;
	int[] map;
}
