import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws Exception {
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-b-large.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-b-large.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		int EMPTY = 0;
		int WALL = 1;
		int[] dr = new int[] { 1, -1, 0, 0 };
		int[] dc = new int[] { 0, 0, 1, -1 };
		
		for (int test = 0; test < tests; test++) {
			int height = scan.nextInt();
			int width = scan.nextInt();
			int[][] map = new int[height+2][width+2];
			for ( int c = 0; c < width+2; c++) {
				map[0][c] = WALL;
				map[height+1][c] = WALL;
			}
			for ( int r = 0; r < height+2; r++) {
				map[r][0] = WALL;
				map[r][width+1] = WALL;
			}
			int startRow = 0, startCol = 0;
			int targetRow = 0, targetCol = 0;
			for ( int r = 0; r < height; r++) {
				String s = scan.next();
				for ( int c = 0; c < width; c++) {
					char a = s.charAt(c);
					if (a == '.' ) map[r+1][c+1] = EMPTY;
					if ( a == '#') map[r+1][c+1] = WALL;
					if ( a == 'O') { map[r+1][c+1] = EMPTY; startRow = r+1; startCol = c+1; }
					if ( a == 'X') { map[r+1][c+1] = EMPTY; targetRow = r+1; targetCol = c+1; }
				}
			}
			height += 2; width += 2;
			int[][][][] shoot = new int[height][width][4][2];
			int nr, nc;
			for ( int r = 1; r < height-1; r++)
				for ( int c = 1; c < width-1; c++) {
					if ( map[r][c] == WALL ) continue;
					for ( int i = 0; i < 4; i++) {
						nr = r; nc = c;
						while ( map[nr + dr[i]][nc + dc[i]] != WALL	) { nr += dr[i]; nc += dc[i]; }
						shoot[r][c][i] = new int[] { nr, nc };
					}
				}
			HashMap<Integer, Integer> done = new HashMap<Integer, Integer>();
			LinkedList<Integer> list = new LinkedList<Integer>();
			LinkedList<Integer> next = new LinkedList<Integer>();
			int col = startCol, row = startRow, yc = 0, yr = 0, bc = 0, br = 0;
			int nyc, nyr, nbc, nbr;
			int pos = row | (col << 5) | (yr << 10) | ( yc << 15) | ( br << 20 ) | (bc << 25);
			int ALL = (1<<5)-1;
			list.add(pos);
			done.put(pos,0);
			int result = -1;
			int distance = 0;
			int npos;
			int INF = 1000000000;
			while ( list.size() > 0 && result == -1) {
				next = new LinkedList<Integer>();
				while ( list.size() > 0 && result == -1) {
					pos = list.poll();
					row = pos & ALL;
					col = (pos >> 5) & ALL;
					yr = (pos >> 10) & ALL;
					yc = (pos >> 15) & ALL;
					br = (pos >> 20) & ALL;
					bc = (pos >> 25) & ALL;
//					System.out.printf("row, col = %d %d, yellow row, col = %d %d, blue row col = %d %d\n", row, col, yr, yc, br,yc);
					if ( row == targetRow && col == targetCol) result = distance;
					// fire yellow gun
					for ( int i = 0; i < 4; i++) {
						nyr = shoot[row][col][i][0];
						nyc = shoot[row][col][i][1];
						npos = row | (col << 5) | (nyr << 10) | ( nyc << 15) | ( br << 20 ) | (bc << 25);
						if ( done.containsKey(npos)) continue;
						done.put(npos, distance);
						list.add(npos);
					}
					// fire blue gun
					for ( int i = 0; i < 4; i++) {
						nbr = shoot[row][col][i][0];
						nbc = shoot[row][col][i][1];
						npos = row | (col << 5) | (yr << 10) | ( yc << 15) | ( nbr << 20 ) | (nbc << 25);
						if ( done.containsKey(npos)) continue;
						done.put(npos, distance);
						list.add(npos);
					}
					// go through yellow portal
					if ( row == yr && col == yc ) {
						nr = br; nc = bc;
						npos = nr | (nc << 5) | (yr << 10) | ( yc << 15) | ( br << 20 ) | (bc << 25);
						int dist = done.containsKey(npos) ? done.get(npos) : INF;
						if ( distance +1 >= dist ) continue; 
						done.put(npos, distance+1);
						next.add(npos);
					}
					// go through blue portal
					if ( row == br && col == bc ) {
						nr = yr; nc = yc;
						npos = nr | (nc << 5) | (yr << 10) | ( yc << 15) | ( br << 20 ) | (bc << 25);
						int dist = done.containsKey(npos) ? done.get(npos) : INF;
						if ( distance +1 >= dist ) continue; 
						done.put(npos, distance+1);
						next.add(npos);
					}
					// ordinary move
					for ( int i = 0; i < 4; i++) {
						nr = row + dr[i];
						nc = col + dc[i];
						if ( map[nr][nc] == EMPTY ){
							npos = nr | (nc << 5) | (yr << 10) | ( yc << 15) | ( br << 20 ) | (bc << 25);
							int dist = done.containsKey(npos) ? done.get(npos) : INF;
							if ( distance +1 >= dist ) continue; 
							done.put(npos, distance+1);
							next.add(npos);
						}
					}
				}
				distance++;
				list = next;
			}
			String answer = String.format("Case #%d: ", test + 1);
			if ( result == -1) answer += "THE CAKE IS A LIE\n";
			else answer += result + "\n";
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
}
