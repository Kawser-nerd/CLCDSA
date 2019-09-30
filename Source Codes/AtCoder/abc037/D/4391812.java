import java.util.*;
import java.io.*;

public class Main {
	static final int MOD = 1000000007;
	static int h;
	static int w;
	static int[][] field;
	static int[][] sums;
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] firstLine = br.readLine().split(" ", 2);
		h = Integer.parseInt(firstLine[0]);
		w = Integer.parseInt(firstLine[1]);
		field = new int[h][w];
		sums = new int[h][w];
		for (int i = 0; i < h; i++) {
			String[] line = br.readLine().split(" ", w);
			for (int j = 0; j < w; j++) {
				field[i][j] = Integer.parseInt(line[j]);
				sums[i][j] = -1;
			}
		}
		
		long count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (sums[i][j] == -1) {
					get(i, j, -1);
				}
				count += sums[i][j];
				count %= MOD;
			}
		}
		System.out.println(count);
	}
	
	static int get(int y, int x, int value) {
		if (y < 0 || y >= h || x < 0 || x >= w) {
			return 0;
		}
		if (field[y][x] <= value) {
			return 0;
		}
		if (sums[y][x] != -1) {
			return sums[y][x];
		}
		int ans = get(y - 1, x, field[y][x]);
		ans %= MOD;
		ans += get(y, x - 1, field[y][x]);
		ans %= MOD;
		ans += get(y + 1, x, field[y][x]);
		ans %= MOD;
		ans += get(y, x + 1, field[y][x]) + 1;
		ans %= MOD;
		sums[y][x] = ans;
		return ans;
	}
}