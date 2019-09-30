import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class A {
	
	public static void main(String[] args) throws Exception {
		Scanner in;
		PrintStream out;
		if (new File("a-large.in").exists()) {
			in = new Scanner(new File("a-large.in"));
			out = new PrintStream(new File("a-large.out"));
		} else if (new File("a-small.in").exists()) {
			in = new Scanner(new File("a-small.in"));
			out = new PrintStream(new File("a-small.out"));
		} else {
			in = new Scanner(new File("a-test.in"));
			out = System.out;
		}
		
		int T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int R = in.nextInt();
			int C = in.nextInt();
			char[][] grid = new char[R][];
			for (int i = 0; i < R; i++) {
				grid[i] = in.next().toCharArray();
			}
			solve(R, C, grid);
			
			out.printf("Case #%d:%n", caseNum);
			for (int i = 0; i < R; i ++) {
				out.printf("%s\n", new String(grid[i]));
			}
		}
		
		
		in.close();
		out.close();
	}
	
	private static void solve(int R, int C, char[][] grid) {
		for (int rep = 0; rep < 2; rep++) {
			for (int r = 1; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if (grid[r][c] == '?') {
						grid[r][c] = grid[r-1][c];
					}
				}
			}
			for (int r = R - 2; r >= 0; r--) {
				for (int c = 0; c < C; c++) {
					if (grid[r][c] == '?') {
						grid[r][c] = grid[r+1][c];
					}
				}
			}
			for (int r = 0; r < R; r++) {
				for (int c = 1; c < C; c++) {
					if (grid[r][c] == '?') {
						grid[r][c] = grid[r][c-1];
					}
				}
			}
			for (int r = 0; r < R; r++) {
				for (int c = C - 2; c >= 0; c--) {
					if (grid[r][c] == '?') {
						grid[r][c] = grid[r][c+1];
					}
				}
			}
		}
	}
	
	private static void solveBrute(int R, int C, char[][] grid) {
		TreeSet<Character> names = new TreeSet<Character>();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (grid[i][j] != '?') {
					names.add(grid[i][j]);
				}
			}
		}
		int N = names.size();
		List<Integer>[] masks = new List[N];
		List<Character> nameList = new ArrayList<Character>(); 
		for (int i = 0; i < N; i++) {
			char name = names.pollFirst();
			nameList.add(name);
			masks[i] = new ArrayList<Integer>();
			for (int r1 = 0; r1 < R; r1++) {
				for (int r2 = r1; r2 < R; r2++) {
					for (int c1 = 0; c1 < C; c1++) {
						for (int c2 = c1; c2 < C; c2++) {
							int mask = 0;
							boolean ok = true;
							boolean has = false;
							for (int r = r1; r <= r2; r++) {
								for (int c = c1; c <= c2; c++) {
									mask |= (1 << (r + c * R));
									if (grid[r][c] != name && grid[r][c] != '?') {
										ok = false;
									}
									if (grid[r][c] == name) {
										has = true;
									}
								}
							}
							if (ok && has) {
								masks[i].add(mask);
							}
						}
					}
				}
			}
		}
		solveRecurse(grid, R, C, masks, nameList, new int[N], 0, 0);
		return;
	}
	
	private static void solveRecurse(char[][] grid, int R, int C, List<Integer>[] masks, List<Character> names, int[] selected, int curMask, int i) {
		int expectedMask = (1 << (R * C)) - 1;
		int N = masks.length;
		if (i == N) {
			if (curMask != expectedMask) return;
			for (int j = 0; j < N; j++) {
				int mask = selected[j];
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						if ((mask & (1 << (r + c * R))) != 0) {
							grid[r][c] = names.get(j);
						}
					}
				}
			}
			return;
		}
		for (int mask : masks[i]) {
			if ((mask & curMask) != 0) {
				continue;
			}
			selected[i] = mask;
			solveRecurse(grid, R, C, masks, names, selected, mask | curMask, i + 1);
		}
	}
}
