package src.code;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Writer;

public class King {

		static int rows, cols;
		static int me_r, me_c;
		static boolean forever = false;

		enum Action { N, W, E, S, NW, NE, SW, SE };
		static int[] dr = { -1, 0, 0, 1, -1, -1, 1, 1 };
		static int[] dc = { 0, -1, 1, 0, -1, 1, -1, 1 };

		static class State {
			boolean[][] str;
			int k_r, k_c;

			State(int rows, int cols) {
				this.str = new boolean[rows][cols];
			}

			void setKing(int r, int c) {
				k_r = r;
				k_c = c;
			}

			void burn(int r, int c) {
				str[r][c] = true;
			}

			State(State rhs) {
				this.str = new boolean[rows][cols];
				for (int r = 0; r < rows; ++r)
					for (int c = 0; c < cols; ++c)
						str[r][c] = rhs.str[r][c];
				k_r = rhs.k_r;
				k_c = rhs.k_c;
			}

			void print() {
				for (int r = 0; r < rows; ++r) {
					for (int c = 0; c < cols; ++c)
						if (r == k_r && c == k_c)
							System.out.print("K");
						else
							System.out.print(str[r][c] ? "#" : ".");
					System.out.println();
				}
			}
		}

		static void reset() {}

		static void applyMove(State start, State end, Action a) {
			int rr = start.k_r + dr[a.ordinal()];
			int cc = start.k_c + dc[a.ordinal()];

			end.setKing(rr, cc);
			end.burn(start.k_r, start.k_c);
		}

		static boolean canWin(State startState, boolean alicesMove) {

			boolean winningStrategy = false;
			boolean moveExists = false;

			for (Action a : Action.values()) {
				State endState = new State(startState);

				int rr = startState.k_r + dr[a.ordinal()];
				int cc = startState.k_c + dc[a.ordinal()];

				if (rr < 0 || rr >= rows) continue;
				if (cc < 0 || cc >= cols) continue;
				if (startState.str[rr][cc]) continue;

				moveExists = true;
				applyMove(startState, endState, a);

				if (!canWin(endState, !alicesMove)) winningStrategy = true;
			}

			if (!moveExists) return false;

			return winningStrategy;
		}

		public static void solve(int cas, State init, Writer wr) throws Exception {
			init.print();
			String output = "Case #" + cas + ": " + (canWin(init, true) ? "A" : "B");
			System.out.println(output);
			wr.write(output + "\n");
		}

		public static void main(String[] args) {
			try {
				FileInputStream fstream = new FileInputStream("c:\\in.txt");
				DataInputStream in = new DataInputStream(fstream);

				FileOutputStream out = new FileOutputStream("c:\\out.txt");
				PrintWriter pw = new PrintWriter(out);

				runOnInput(in, pw);

				pw.close();
			} catch (Exception e) {
				System.err.println("Error: " + e.getMessage());
			}
		}

		public static void runOnInput(InputStream in, Writer w) throws Exception {
			try {
				BufferedReader br = new BufferedReader(new InputStreamReader(in));
				int testCount = Integer.parseInt(br.readLine());
				for (int i = 1; i <= testCount; ++i) {
					reset();
					String l = br.readLine();
					String[] prt = l.split(" ");
					cols = Integer.parseInt(prt[1]);
					rows = Integer.parseInt(prt[0]);
					State initialState = new State(rows, cols);
					for (int r = 0; r < rows; ++r) {
						l = br.readLine();
						for (int c = 0; c < cols; ++c) {
							if (l.charAt(c) == '#')
								initialState.burn(r, c);
							else if (l.charAt(c) == 'K')
								initialState.setKing(r, c);
						}
					}
					solve(i, initialState, w);
				}
				in.close();
			} catch (Exception e) {
				e.printStackTrace();
				System.err.println("Error: " + e.getMessage());
			}
		}
}
