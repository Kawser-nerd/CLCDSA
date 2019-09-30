import java.io.*;
import java.util.*;


public class Solution {

	public static BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer tok = null;
	
	public static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(cin.readLine());
		}
		return tok.nextToken();
	}
	
	public static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	
	public static int H, W;
	public static int[][] map;
	public static char[][] used;
	public static final int[] dy = {-1, 0, 0, 1};
	public static final int[] dx = {0, -1, 1, 0};
	
	public static char dfs(int y, int x, char color) {
		if (used[y][x] != '.') return used[y][x];
		int mdir = -1;
		for (int i = 0; i < 4; i++) {
			if ((y + dy[i] >= 0 && y + dy[i] < H && x + dx[i] >= 0 && x + dx[i] < W) &&
					(mdir == -1 || map[y + dy[i]][x + dx[i]] < map[y + dy[mdir]][x + dx[mdir]])) {
				mdir = i;
			}
		}
		if (mdir > -1 && map[y + dy[mdir]][x + dx[mdir]] < map[y][x]) {
			used[y][x] = dfs(y + dy[mdir], x + dx[mdir], color);
			return used[y][x];
		} else { // sink
			used[y][x] = color;
			return color;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = nextInt();
		for (int i = 0; i < T; i++) {
			H = nextInt();
			W = nextInt();
			map = new int[H][W];
			used = new char[H][W];
			
			for (int j = 0; j < H; j++) {
				for (int k = 0; k < W; k++) {
					map[j][k] = nextInt();
					used[j][k] = '.';
				}
			}
			
			System.out.println("Case #" + (i + 1) + ":");
			char last = 'a';
			for (int j = 0; j < H; j++) {
				for (int k = 0; k < W; k++) {
					if (used[j][k] == '.') {
						dfs(j, k, last);
						if (used[j][k] == last)
							last++;
					}
					System.out.print(used[j][k] + (k < W - 1 ? " " : ""));
				}
				System.out.println();
			}
		}

	}

}
