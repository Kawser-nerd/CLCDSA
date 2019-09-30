import java.util.Scanner;

public class Main {

	static String[][] country = new String[10][10];
	static boolean[][] done;
	static int islandArea=0, islandCnt;
	static int startX = -1, startY = -1;
	static boolean isOne;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String line, point;

		for(int i = 0; i < 10; i++) {
			line = sc.nextLine();
			for(int j = 0; j < 10; j++) {
				point = line.substring(j, j+1);
				country[i][j] = point;
				if(point.equals("o")) {
					islandArea++;
					if(startX < 0) {
						startX = i;
						startY = j;
					}
				}
			}
		}

		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				if(country[i][j].equals("x")) {
					country[i][j] = "o";
					done = new boolean[10][10];
					islandCnt = 0;
					dfs(i, j);
					if(isOne) break;
					country[i][j] = "x";
				}
			}
			if(isOne) break;
		}

		System.out.println(isOne ? "YES" : "NO");
	}

	static void dfs(int x, int y) {
		if(x < 0 || x > 9 || y < 0 || y > 9) return;
		if(country[x][y].equals("x")) return;
		if(done[x][y]) return;

		if(country[x][y].equals("o")) {
			islandCnt++;
			isOne = isOne || islandArea + 1 == islandCnt;
		}

		done[x][y] = true;

		dfs(x+1, y);
		dfs(x-1, y);
		dfs(x, y+1);
		dfs(x, y-1);
	}
}