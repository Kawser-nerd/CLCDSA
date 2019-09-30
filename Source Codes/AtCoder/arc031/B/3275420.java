import static java.lang.System.*;
import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static char[][] map = new char[10][10];
	static int area;
	public static void main(String[] args) {
		for (int i=0; i<10; i++) {
			map[i] = sc.next().toCharArray();
			for (int j=0; j<10; j++) {
				if (map[i][j]=='o') area++;
			}
		}
		
		int[] dx = {0,1,0,-1};
		int[] dy = {-1,0,1,0};
		boolean F = false;
		
		loop : for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				int landNum = 0;
				if (map[i][j]=='x') {
					for (int k=0; k<4; k++) {
						int y = i + dy[k];
						int x = j + dx[k];
						if (y<0 || x<0 || y>9 || x>9) continue;
						if (map[y][x]=='o') landNum++;
					}
				}
				
				if (landNum >= 2) {
					boolean[][] memo = new boolean[10][10];
					dfs(i,j,0,memo);
					int areaNum = 0;
					for (int k=0; k<10; k++) {
						for (int l=0; l<10; l++) {
							if (memo[k][l]) areaNum++;
						}
					}
					if (areaNum == area+1) {
						F = true;
						break loop;
					}
				}
			}
		}
		
		out.println(F?"YES":"NO");
	}

	static void dfs(int sy, int sx, int n, boolean[][] memo) {
		if (sy<0 || sx<0 || sy>9 || sx>9) return;
		if (n!=0 && map[sy][sx]=='x') return;
		if (memo[sy][sx]) return;
		memo[sy][sx] = true;
		dfs(sy-1,sx,n+1,memo);
		dfs(sy,sx+1,n+1,memo);
		dfs(sy+1,sx,n+1,memo);
		dfs(sy,sx-1,n+1,memo);
	}
}