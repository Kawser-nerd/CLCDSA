import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	Scanner sc;
	
	int INF = 1 << 29;
	void solve() {
		int n = sc.nextInt(), m = sc.nextInt(), f = sc.nextInt();
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++) map[i] = sc.next().toCharArray();
		int[][][][] min = new int[n][m][m][m];//pos*left*right
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < m; k++) fill(min[i][j][k], INF);
		min[0][0][0][0] = 0;
		for (int i = 0; i + 1 < n; i++) {
			for (int left = 0; left < m; left++) {
				for (int right = 0; right < m; right++) {
					for (int j = 0; j < m; j++) if (min[i][j][left][right] < INF) {
						int v = min[i][j][left][right];
						int left2 = j;
						int right2 = j;
						while (left2 > 0 && (map[i][left2 - 1] == '.' || left <= left2 - 1 && left2 - 1 <= right) && map[i + 1][left2 - 1] == '#') {
							left2--;
						}
						while (right2 + 1 < m && (map[i][right2 + 1] == '.' || left <= right2 + 1 && right2 + 1 <= right) && map[i + 1][right2 + 1] == '#') {
							right2++;
						}
						//down left2-1
						int j2 = left2 - 1;
						if (0 <= j2 && j2 < m && (map[i][j2] == '.' || left <= j2 && j2 <= right) && map[i + 1][j2] == '.') {
							int i2 = to(map, i, j2);
							if (i2 - i <= f) {
								min[i2][j2][j2][j2] = min(min[i2][j2][j2][j2], v);
							}
						}
						//down right2+1
						j2 = right2 + 1;
						if (0 <= j2 && j2 < m && (map[i][j2] == '.' || left <= j2 && j2 <= right) && map[i + 1][j2] == '.') {
							int i2 = to(map, i, j2);
							if (i2 - i <= f) {
								min[i2][j2][j2][j2] = min(min[i2][j2][j2][j2], v);
							}
						}
						//dig many left
						for (int left3 = left2 + 1; left3 <= right2; left3++) {
							for (int right3 = left3; right3 <= right2; right3++) {
								int i2 = to(map, i, left3);
								if (i2 - i == 1) {
									min[i2][left3][left3][right3] = min(min[i2][left3][left3][right3], v + right3 - left3 + 1);
								} else if (i2 - i <= f) {
									min[i2][left3][left3][left3] = min(min[i2][left3][left3][left3], v + right3 - left3 + 1);
								}
							}
						}
						//dig many right
						for (int left3 = left2; left3 < right2; left3++) {
							for (int right3 = left3; right3 < right2; right3++) {
								int i2 = to(map, i, right3);
								if (i2 - i == 1) {
									min[i2][right3][left3][right3] = min(min[i2][right3][left3][right3], v + right3 - left3 + 1);
								} else if (i2 - i <= f) {
									min[i2][right3][right3][right3] = min(min[i2][right3][right3][right3], v + right3 - left3 + 1);
								}
							}
						}
					}
				}
			}
		}
		int res = INF;
		for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) for (int k = 0; k < m; k++) res = min(res, min[n - 1][i][j][k]);
		if (res == INF) {
			System.out.println("No");
		} else {
			System.out.println("Yes " + res);
		}
	}
	
	int to(char[][] map, int i, int j) {
		i++;
		while (i + 1 < map.length && map[i + 1][j] == '.') i++;
		return i;
	}
	
	void run() {
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			solve();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
