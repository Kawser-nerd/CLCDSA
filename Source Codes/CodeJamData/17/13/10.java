import java.io.*;
import java.util.*;

public class A3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner input = new FastScanner();
		int n = input.nextInt();

		int[][][][] gameStates = new int[221][101][101][101];
		outer: for (int x = 0; x < n; x++) {
			int maxHP = input.nextInt();
			int attackdamage = input.nextInt();
			int knightHP = input.nextInt();
			int knightdamage = input.nextInt();
			int buffDragonDmg = input.nextInt();
			int debuffKnightDmg = input.nextInt();

			// Order of variables: Turn#, ATK, KnightATK, HP: KnightHP
			for (int b = 0; b < 221; b++) {
				for (int b2 = 0; b2 < 101; b2++) {
					for (int b3 = 0; b3 < 101; b3++) {
						for (int b4 = 0; b4 < 101; b4++) {
							gameStates[b][b2][b3][b4] = Integer.MAX_VALUE;
						}
					}
				}
			}
			gameStates[0][attackdamage][knightdamage][maxHP] = knightHP;
			int turn = 0;
			done: while (true) {
				if (turn >= 221 - 1) {
					break;
				}
				for (int a = 0; a < 101; a++) {
					for (int b = 0; b < 101; b++) {
						for (int c = 0; c < 101; c++) {
							if (gameStates[turn][a][b][c] < Integer.MAX_VALUE) {
//								System.err
//										.println(turn + ": " + a + " " + b + " " + c + " " + gameStates[turn][a][b][c]);
								if (c <= b) {
									// only debuff, cure, or 1shot.

									// debuff
									if (c > Math.max(0, b - debuffKnightDmg)) {
										gameStates[turn + 1][a][Math.max(0, b - debuffKnightDmg)][c
												- Math.max(0, b - debuffKnightDmg)] = Math
														.min(gameStates[turn + 1][a][Math.max(0, b - debuffKnightDmg)][c
																- Math.max(0, b - debuffKnightDmg)],
														gameStates[turn][a][b][c]);

									}
									// cure
									if (maxHP > b) {
										gameStates[turn + 1][a][b][maxHP - b] = Math
												.min(gameStates[turn + 1][a][b][maxHP - b], gameStates[turn][a][b][c]);
									}

									if (gameStates[turn][a][b][c] <= a) {
										turn++;
										break done;
									}
								} else {
									// move 1: attack
									gameStates[turn + 1][a][b][c - b] = Math.min(gameStates[turn + 1][a][b][c - b],
											Math.max(0, gameStates[turn][a][b][c] - a));
									if (gameStates[turn + 1][a][b][c - b] == 0) {
										turn++;
										break done;
									}
									// move 2: buff
									gameStates[turn + 1][a + buffDragonDmg][b][c - b] = Math.min(
											gameStates[turn + 1][a + buffDragonDmg][b][c - b],
											gameStates[turn][a][b][c]);
									// move 3: cure
									gameStates[turn + 1][a][b][maxHP - b] = Math
											.min(gameStates[turn + 1][a][b][maxHP - b], gameStates[turn][a][b][c]);
									// move 4: debuff
									gameStates[turn + 1][a][Math.max(0, b - debuffKnightDmg)][c
											- Math.max(0, b - debuffKnightDmg)] = Math
													.min(gameStates[turn + 1][a][Math.max(0, b - debuffKnightDmg)][c
															- Math.max(0, b - debuffKnightDmg)],
													gameStates[turn][a][b][c]);

								}

							}
						}
					}
				}

				turn++;
			}
			if (turn == 220) {
				System.out.println("Case #" + (x + 1) + ": " + "IMPOSSIBLE");
			} else {
				System.out.println("Case #" + (x + 1) + ": " + turn);
			}
		}
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(Reader in) {
			br = new BufferedReader(in);
		}

		public FastScanner() {
			this(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String readNextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextInt();
			}
			return a;
		}

		long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextLong();
			}
			return a;
		}
	}
}
