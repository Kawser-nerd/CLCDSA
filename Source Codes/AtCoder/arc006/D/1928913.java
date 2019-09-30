import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;

public class Main {
	public static void main(String[] args) throws IOException {
		Main main = new Main();
		main.solveD();
	}

	BitSet map;
	int[] diff;

	private void solveD() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String tokens[] = br.readLine().split(" ");
		int H = Integer.valueOf(tokens[0]).intValue();
		int W = Integer.valueOf(tokens[1]).intValue();
		diff = new int[8];
		diff[0] = -W-1;
		diff[1] = -W;
		diff[2] = -W+1;
		diff[3] = -1;
		diff[4] = 1;
		diff[5] = W-1;
		diff[6] = W;
		diff[7] = W+1;
		map = new BitSet(H * W);
		{
			for (int r = 0; r < H; r++) {
				String line = br.readLine();
				for (int c = 0; c < W; c++) {
					if (line.charAt(c) == 'o') {
						map.set(r * W + c);
					}
				}
			}
		}
		int[] ans = new int[3];
		{
			for (int r = 0; r < H; r++) {
				for (int c = 0; c < W; c++) {
					if (map.get(r * W + c)) {
						ans[judge(search(r * W + c))]++;
					}
				}
			}
		}
		System.out.println(ans[0] + " " + ans[1] + " " + ans[2]);
	}

	public int judge(int size) {
		for (int zoom = 1; zoom < 150; zoom++) {
			if (size % 12 == 0 && size / 12 == zoom * zoom) {
				return 0;
			}
			if (size % 16 == 0 && size / 16 == zoom * zoom) {
				return 1;
			}
			if (size % 11 == 0 && size / 11 == zoom * zoom) {
				return 2;
			}
		}
		return -1;
	}

	public int search(int rc) {
		int sum = 1;
		map.set(rc, false);
		for (int dir = 0; dir < 8; dir++) {
			if (map.get(rc + diff[dir])) {
				sum += search(rc + diff[dir]);
			}
		}
		return sum;
	}
}