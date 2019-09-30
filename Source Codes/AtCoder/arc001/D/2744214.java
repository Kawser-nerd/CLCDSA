import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);

		int H = 8;
		int W = 8;

		String[][] field = new String[H][W];

		for (int i = 0; i < H; i++) {
			field[i] = sc.next().split("");
		}

		if (dfs(0, 8, field)) {
			output(field);
		} else {
			pln("No Answer");
		}

	}

	boolean dfs(int pos, int nokori, String[][] field) {

		if (nokori == 0) {
			return true;

		}

		if (pos == 64) {
			return false;

		}

		int y = pos / 8;
		int x = pos % 8;

		if (field[y][x].equals("Q")) {

			if (canPut(y, x, field)) {
				if (dfs(pos + 1, nokori - 1, field)) {
					return true;
				}
			}

		} else {

			if (canPut(y, x, field)) {
				field[y][x] = "Q";
				if (dfs(pos + 1, nokori - 1, field)) {
					return true;
				}
				field[y][x] = ".";

			}

			if (dfs(pos + 1, nokori, field)) {
				return true;
			}

		}

		return false;
	}

	boolean isIn(int y, int x) {
		return y >= 0 && y < 8 && x >= 0 && x < 8;
	}

	boolean canPut(int y, int x, String[][] field) {

		for (int dy = -1; dy <= 1; dy++) {
			for (int dx = -1; dx <= 1; dx++) {

				if (dy == 0 && dx == 0) {
					continue;
				}

				int ty = y;
				int tx = x;

				while (true) {
					ty += dy;
					tx += dx;

					if (!isIn(ty, tx)) {
						break;
					}

					if (field[ty][tx].equals("Q")) {
						return false;

					}
				}

			}
		}

		return true;
	}

	//????????
	static <T> void output(List<T> list) {

		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i));

			if (i != list.size() - 1) {
				System.out.print(" ");
			} else {
				nl();
			}
		}

	}

	static void output(String[][] str) {

		for (int i = 0; i < str.length; i++) {
			for (int j = 0; j < str[i].length; j++) {
				print(str[i][j]);
			}

			nl();
		}

	}

	static void output(boolean flg, String Yes, String No) {

		if (flg) {
			pln(Yes);
		} else {
			pln(No);
		}

	}

	static void output(String[][] str, int digit) {

		String dig = "%" + String.valueOf(digit) + "s";

		for (int i = 0; i < str.length; i++) {
			for (int j = 0; j < str[i].length; j++) {
				System.out.printf(dig, str[i][j]);
			}
			nl();
		}

	}

	static void pln(String str) {
		System.out.println(str);
	}

	static void pln(int x) {
		System.out.println(x);
	}

	static void print(String str) {
		System.out.print(str);
	}

	static void print(int x) {
		System.out.print(x);
	}

	static void print(String str, int times) {
		for (int i = 0; i < times; i++) {
			print(str);
		}
	}

	static void print(int x, int times) {
		for (int i = 0; i < times; i++) {
			print(x);
		}
	}

	static void nl() {
		System.out.println();
	}

	static int makebit(int digit) {

		int bit = 0;

		while (digit > 0) {

			bit |= (1 << digit % 10);

			digit /= 10;
		}

		return bit;
	}

}