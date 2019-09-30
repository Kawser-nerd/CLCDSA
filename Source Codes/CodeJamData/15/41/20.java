package world2015.round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Pegman {

	private static final int[][] DIRECTIONS = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0}
	};
	
	public int solve(int R, int C, String[] cells) {
		int[][] cs = parse(R, C, cells);
		int cnt = 0;
		for (int r=0; r<R; r++)
			for (int c=0; c<C; c++) {
				if (cs[r][c]<0 || valid(R, C, cs, r, c, cs[r][c]))
					continue;
				boolean impossible = true;
				for (int dir=0; dir<4; dir++)
					if (dir!=cs[r][c] && valid(R, C, cs, r, c, dir)) {
						cnt++;
						impossible = false;
						break;
					}
				if (impossible)
					return -1;
			}
		return cnt;
	}
	
	private int[][] parse(int R, int C, String[] cells) {
		int[][] cs = new int[R][C];
		for (int r=0; r<R; r++)
			for (int c=0; c<C; c++) {
				if (cells[r].charAt(c)=='.')
					cs[r][c] = -1;
				else if (cells[r].charAt(c)=='>')
					cs[r][c] = 0;
				else if (cells[r].charAt(c)=='v')
					cs[r][c] = 1;
				else if (cells[r].charAt(c)=='<')
					cs[r][c] = 2;
				else if (cells[r].charAt(c)=='^')
					cs[r][c] = 3;
			}
		return cs;
	}
	
	private boolean valid(int R, int C, int[][] cells, int r, int c, int dir) {
		int rr = r + DIRECTIONS[dir][0], cc = c + DIRECTIONS[dir][1];
		boolean valid = false;
		while (0<=rr && rr<R && 0<=cc && cc<C) {
			if (cells[rr][cc]>=0) {
				valid = true;
				break;
			}
			rr += DIRECTIONS[dir][0];
			cc += DIRECTIONS[dir][1];
		}
		return valid;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round2/A-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			int R = Integer.parseInt(tokens[0]);
			int C = Integer.parseInt(tokens[1]);
			String[] cells = new String[R];
			for (int r=0; r<R; r++)
				cells[r] = br.readLine().trim();
			int res = new Pegman().solve(R, C, cells);
			StringBuilder sb = new StringBuilder();
			if (res>=0)
				sb.append("Case #" + (i+1) + ": " + res);
			else
				sb.append("Case #" + (i+1) + ": IMPOSSIBLE");
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
