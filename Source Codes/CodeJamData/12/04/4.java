package pl.helman.codejam.Hall;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Hall {

	private static int checkSpecialCases(boolean[][] map, int startX,
			int startY, int d) {
		int ret = 0;

		// horizontal to left
		int x = startX, y = startY;
		// traveled distance
		int a = 0;
		while (!map[x][y]) {
			x--;
			a++;
		}
		if (2 * a <= d) {
			ret++;
		}

		x = startX;
		y = startY;
		// traveled distance
		a = 0;
		while (!map[x + 1][y]) {
			x++;
			a++;
		}
		if (2 * a <= d) {
			ret++;
		}

		x = startX;
		y = startY;
		// traveled distance
		a = 0;
		while (!map[x][y]) {
			y--;
			a++;
		}
		if (2 * a <= d) {
			ret++;
		}

		x = startX;
		y = startY;
		// traveled distance
		a = 0;
		while (!map[x][y + 1]) {
			y++;
			a++;
		}
		if (2 * a <= d) {
			ret++;
		}

		return ret;
	}

	private static boolean checkRay(boolean[][] map, int startX, int startY,
			int d, int dirX, int dirY) {

		int den = Math.abs(dirX * dirY);
		int lx = startX * den;
		int ly = startY * den;

		int t = 0;

		while (true) {

			// seeking for next lines distance
			int lineDistX = dirX < 0 ? (lx % den) : (den - lx % den);
			if (lineDistX == 0) {
				lineDistX = den;
			}
			lineDistX = Math.abs(lineDistX / dirX);

			int lineDistY = dirY < 0 ? (ly % den) : (den - ly % den);
			if (lineDistY == 0) {
				lineDistY = den;
			}
			lineDistY = Math.abs(lineDistY / dirY);

			// moving to closest line
			if (lineDistX < lineDistY) {
				lx += lineDistX * dirX;
				ly += lineDistX * dirY;
			} else {
				lx += lineDistY * dirX;
				ly += lineDistY * dirY;
			}

			if (lx % den == 0 && ly % den == 0) {
				// full vector repetition

				// increase traveled distance
				t++;

				if (t * t * (dirX * dirX + dirY * dirY) > d * d) {
					return false;
				}

				// check if it's not starting point
				if (lx == startX * den && ly == startY * den) {

					return true;
				}

				// corners
				int x = lx / den;
				int y = ly / den;

				boolean wall = false;
				// vertical wall
				if ((map[x][y] && map[x][y + 1])
						|| (map[x + 1][y] && map[x + 1][y + 1])) {
					dirX = -dirX;
					wall = true;
				}

				// horizontal wall
				if ((map[x][y] && map[x + 1][y])
						|| (map[x][y + 1] && map[x + 1][y + 1])) {
					dirY = -dirY;
					wall = true;
				}

				if (!wall && map[dirX > 0 ? x + 1 : x][dirY > 0 ? y + 1 : y]) {
					// dead corner
					return false;
				}

			} else {
				// possible mirror
				if (lx % den == 0
						&& map[dirX < 0 ? (lx / den) : ((lx / den) + 1)][(ly / den) + 1]) {
					// vertical wall
					dirX = -dirX;
				} else if (ly % den == 0
						&& map[(lx / den) + 1][dirY < 0 ? (ly / den)
								: ((ly / den) + 1)]) {
					// horizontal wall
					dirY = -dirY;
				}
			}
		}
	}

	public static int egcd(int a, int b) {
		if (a == 0)
			return b;

		while (b != 0) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}

		return a;
	}

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\hall.in");
		BufferedReader br = new BufferedReader(fr);
		String s = br.readLine();

		FileWriter f0 = new FileWriter("d:\\hall.out");

		int t = Integer.parseInt(s.trim());

		for (int i = 1; i <= t; i++) {
			s = br.readLine();
			String[] elems = s.split(" ");
			int h = Integer.parseInt(elems[0]);
			int w = Integer.parseInt(elems[1]);
			int d = Integer.parseInt(elems[2]) * 2;

			int startX = -1;
			int startY = -1;

			int ret = 0;

			boolean[][] map = new boolean[2 * w][2 * h];

			// loading map
			for (int y = 0; y < h; y++) {
				s = br.readLine();
				for (int x = 0; x < w; x++) {
					if (s.charAt(x) == '#') {
						map[2 * x][2 * y] = true;
						map[2 * x + 1][2 * y] = true;
						map[2 * x][2 * y + 1] = true;
						map[2 * x + 1][2 * y + 1] = true;
					} else {
						map[2 * x][2 * y] = false;
						map[2 * x + 1][2 * y] = false;
						map[2 * x][2 * y + 1] = false;
						map[2 * x + 1][2 * y + 1] = false;
					}

					if (s.charAt(x) == 'X') {
						startX = 2 * x;
						startY = 2 * y;
					}
				}
			}

			// special cases
			ret = checkSpecialCases(map, startX, startY, d);

			// probable light directions
			for (int dirX = -d; dirX <= d; dirX++) {
				if (dirX == 0) {
					// special case
					continue;
				}
				for (int dirY = -d; dirY <= d; dirY++) {
					if (dirY == 0) {
						// special case
						continue;
					}

					if (dirX * dirX + dirY * dirY > d * d) {
						// too long
						continue;
					}

					if (egcd(Math.abs(dirX), Math.abs(dirY)) != 1) {
						// there is shorter version
						continue;
					}

					if (checkRay(map, startX, startY, d, dirX, dirY)) {
						//System.out.println("   dirX:" + dirX + " dirY:" + dirY);
						ret++;
					}
				}

			}

			System.out.println("Case #" + i + ": " + ret);
			// System.out.println();

			f0.write("Case #" + i + ": " + ret + "\r\n");
		}

		fr.close();
		f0.close();

	}
}
