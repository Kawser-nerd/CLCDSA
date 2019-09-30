import java.util.Scanner;

public class Main {
	static int H = 10;
	static int W = 10;
	static int sx;
	static int sy;
	static boolean[][] spot = new boolean[H][W];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[][] island = new String[H][W];
		boolean[][] searched = new boolean[H][W];
		for (int i = 0; i < H; i++) {
			island[i] = sc.nextLine().split("");
		}
		boolean ans = false;
		searchSpot(island,searched,0,0);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (spot[i][j]) {
					island[i][j] = "o";
					boolean[][] reached = new boolean[H][W];
					searchIsland(island,reached,i,j);
					ans = checkOneIsland(island, reached);
					if (ans) {
						System.out.println("YES");
						return;
					} else {
						island[i][j] = "x";
					}
				}
			}
		}
		System.out.println("NO");
	}

	//??????????
	static void searchSpot(String[][] island, boolean[][] searched, int x, int y) {
		if (x < 0 || H <= x || y < 0 || W <= y ) {
			return;
		}
		if (searched[x][y]) {
			return;
		}
		if (island[x][y].equals("o")) {
			spot[x][y] = false;
		}
		if (island[x][y].equals("x")) {
			int dx[] = {1,0,-1,0};
			int dy[] = {0,1,0,-1};
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || H <= nx) {
					continue;
				}
				if (ny < 0 || W <= ny) {
					continue;
				}
				if ("o".equals(island[nx][ny])) {
					cnt ++;
				}
			}
			if (cnt >= 2) {
				spot[x][y] = true;
			} else {
				spot[x][y] = false;
			}
		}
		searched[x][y] = true;
		searchSpot(island,searched,x+1,y);
		searchSpot(island,searched,x-1,y);
		searchSpot(island,searched,x,y+1);
		searchSpot(island,searched,x,y-1);
	}
	//????
	public static void searchIsland(String[][] island,boolean[][] reached, int x, int y){
		if (x < 0 || H <= x || y < 0 || W <= y ) return;
		if (island[x][y].equals("x")) return;
		if (reached[x][y]) return;
		reached[x][y] = true;

		searchIsland(island, reached, x+1, y);
		searchIsland(island, reached, x-1, y);
		searchIsland(island, reached, x, y+1);
		searchIsland(island, reached, x, y-1);
	}
	//???????????????
	public static boolean checkOneIsland(String[][] island, boolean[][]reached) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if ("x".equals(island[i][j])) {
					continue;
				}
				if (!reached[i][j] && "o".equals(island[i][j])) {
					return false;
				}
			}
		}
		return true;
	}
}