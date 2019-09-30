import java.util.*;
import java.io.*;

public class Solution {
	class Testcase {
		public Testcase() {	
		}
		
		public Testcase(int seed) {
			Random rnd = new Random(seed);
		}
		
		int H, W, M;
		int[][] map;
		
		boolean canFlow;
		int[][] used;
		int compId;
		int[][] lev;
		
		int res;
		
		public void loadInput(Scanner sc) {
			H = sc.nextInt();
			W = sc.nextInt();
			M = sc.nextInt();
			map = new int[H][W];
			for (int i=0; i<H; i++)
				for (int j=0; j<W; j++)
					map[i][j] = sc.nextInt();
		}
		
		boolean over() {
			int sum = 0;
			for (int i=0; i<H; i++)
				for (int j=0; j<W; j++)
					sum += map[i][j];
			return sum==0;
		}
		
		final int[] dx = new int[] {-1, 1, 0, 0};
		final int[] dy = new int[] {0, 0, -1, 1};
		
		void dfs(int i, int j) {
			if (used[i][j] != 0) return;
			used[i][j] = compId;
			for (int dir=0; dir<4; dir++) {
				int newI = i + dx[dir];
				int newJ = j + dy[dir];
				if (newI < 0 || newI >= H || newJ < 0 || newJ >= W) {
					canFlow = true;
				} else {
					int h = lev[newI][newJ];
					if (h == lev[i][j]) {
						dfs(newI, newJ);
					} else if (h < lev[i][j]) {
						canFlow = true;
					}
				}
			}
		}
		
		public void solveSlow() {
			res = 0;
			while (!over()) {
				res++;
				lev = new int[H][W];
				for (int i=0; i<H; i++)
					for (int j=0; j<W; j++)
						lev[i][j] = map[i][j];
				for (int hh=0; hh <= 100; hh++) {
					used = new int[H][W];
					compId = 0;
					for (int i=0; i<H; i++)
						for (int j=0; j<W; j++)
							if (lev[i][j] == hh && used[i][j] == 0) {
								compId++;
								canFlow = false;
								dfs(i, j);
								if (!canFlow) {
									for (int ii=0; ii<H; ii++)
										for (int jj=0; jj<W; jj++)
											if (used[ii][jj] == compId)
												lev[ii][jj]++;
								}
							}
				}
				for (int i=0; i<H; i++)
					for (int j=0; j<W; j++) {
						int min = Integer.MAX_VALUE;
						for (int t=0; t<4; t++) {
							int newI = i + dx[t];
							int newJ = j + dy[t];
							if (newI < 0 || newI >= H || newJ < 0 || newJ >= W)
								min = 0;
							else
								min = Math.min(min, lev[newI][newJ]);
						}
						map[i][j] -= Math.min(lev[i][j] - min, M);
					}
			}
		}
		
		public void solveFast() {
		}
		
		public void printSelf(PrintWriter pw) {
			pw.println(res);
		}
		
		public boolean sameAnswers(Testcase other) {
			return false;
		}
	}
	
	final String AFTER_CASE = " ";
	
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("solving case " + caseNum);
			
			Testcase tc = new Testcase();
			
			tc.loadInput(sc);
			tc.solveSlow();
			
			pw.print("Case #" + (caseNum + 1) + ":");
			pw.print(AFTER_CASE);
			
			tc.printSelf(pw);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public void stresstest() {
		int it = 0;
		Random rnd = new Random();
		while (true) {
			it++;
			if (it % 1000 == 0)
				System.out.println(it + " iterations");
			
			int seed = rnd.nextInt();
			
			Testcase tc1 = new Testcase(seed);
			tc1.solveFast();
			
			Testcase tc2 = new Testcase(seed);
			tc2.solveSlow();
			
			if (!tc1.sameAnswers(tc2)) {
				System.out.println("ERROR: it failed");
				System.exit(0);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		new Solution().go();
	}
}
