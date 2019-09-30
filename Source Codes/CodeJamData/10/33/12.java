package gcj2010r1c.c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {

			BufferedReader reader;
			if (args.length > 0) {
				reader = new BufferedReader(new FileReader(args[0]));
			} else {
				reader = new BufferedReader(new InputStreamReader(System.in));
			}
			String line = null;
			line = reader.readLine();
			int caseCount = Integer.parseInt(line);

			long startTime = System.currentTimeMillis();

			for (int i = 0; i < caseCount; i++) {
				line = reader.readLine();
				String[] nums = line.split(" ");
				int m = Integer.parseInt(nums[0]);
				int n = Integer.parseInt(nums[1]);
				int[][] board = new int[n][m];
				for (int j = 0; j < m; j++) {
					line = reader.readLine();
					for (int k = 0; k < n / 4; k++) {
						char ch = line.charAt(k);
						int v = 0;
						if ('0' <= ch && ch <= '9') {
							v = ch - '0';
						} else {
							v = 10 + ch - 'A';
						}
						board[k * 4][j] = (v & 0x8) > 0 ? 1 : 0;
						board[k * 4 + 1][j] = (v & 0x4) > 0 ? 1 : 0;
						board[k * 4 + 2][j] = (v & 0x2) > 0 ? 1 : 0;
						board[k * 4 + 3][j] = (v & 0x1) > 0 ? 1 : 0;
					}
				}

				List<int[]> partCounts = countParts(n, m, board);

				System.out.print("Case #");
				System.out.print(i + 1);
				System.out.print(": ");
				System.out.println(partCounts.size());
				for (int j = 0; j < partCounts.size(); j++) {
					System.out.print(partCounts.get(j)[0]);
					System.out.print(" ");
					System.out.println(partCounts.get(j)[1]);
				}
			}

			System.err.println("Elasped Time : "
					+ (System.currentTimeMillis() - startTime));
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static List<int[]> countParts(int w, int h, int[][] board) {
		Map<Integer, int[]> countMap = new HashMap<Integer, int[]>();
		List<int[]> result = new ArrayList<int[]>();

		while (true) {
			// find the largest
			int[][] count = new int[w][h];
			boolean changes = false;
			for (int y = 0; y < h - 1; y++) {
				for (int x = 0; x < w - 1; x++) {
					if (board[x][y] >= 0 && board[x + 1][y] >= 0
							&& board[x][y + 1] >= 0 && board[x + 1][y + 1] >= 0) {

						if (board[x][y] != board[x + 1][y]
								&& board[x][y] != board[x][y + 1]
								&& board[x][y] == board[x + 1][y + 1]) {
							count[x][y] = 2;
							changes = true;
						}
					}
				}
			}
			if (!changes) {
				// count 1
				int c = 0;
				for (int y = 0; y < h; y++) {
					for (int x = 0; x < w; x++) {
						if (board[x][y] >= 0)
							c++;
					}
				}
				if (c > 0) {
					int[] item = new int[2];
					item[0] = 1;
					item[1] = c;
					countMap.put(1, item);
				}
				result.addAll(countMap.values());
				Collections.sort(result, new Comparator<int[]>() {
					@Override
					public int compare(int[] o1, int[] o2) {
						if (o1[0] > o2[0])
							return -1;
						if (o1[0] < o2[0])
							return 1;
						return 0;
					}

				});
				return result;
			}
			int size = 1;
			while (changes) {
				size++;
				changes = false;
				for (int y = 0; y < h - size; y++) {
					for (int x = 0; x < w - size; x++) {
						if (count[x][y] == size && count[x + 1][y] == size
								&& count[x][y + 1] == size
								&& count[x + 1][y + 1] == size) {
							count[x][y] = size + 1;
							changes = true;
						}
					}
				}
			}
			for (int y = 0; y < h - size + 1; y++) {
				for (int x = 0; x < w - size + 1; x++) {
					if (count[x][y] == size) {
						int[] item = countMap.get(size);
						if (item == null) {
							item = new int[2];
							item[0] = size;
							item[1] = 0;
							countMap.put(size, item);
						}
						item[1]++;

						for (int y2 = y; y2 < y + size; y2++) {
							for (int x2 = x; x2 < x + size; x2++) {
								board[x2][y2] = -1;
							}
						}

						y = h;
						break;
					}
				}
			}
		}
	}
}
