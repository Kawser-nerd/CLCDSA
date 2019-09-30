import java.io.*;
import java.net.Inet4Address;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] ia = in.readLine().split(" ");
		int x = Integer.parseInt(ia[0]) - 1;
		int y = Integer.parseInt(ia[1]) - 1;
		int dx = 0, dy = 0;
		if (ia[2].contains("L")) {
			dx = -1;
		} else if (ia[2].contains("R")) {
			dx = 1;
		}
		if (ia[2].contains("U")) {
			dy = -1;
		} else if (ia[2].contains("D")) {
			dy = 1;
		}
		char[][] c = new char[9][];
		for (int i = 0; i < 9; ++i) {
			c[i] = in.readLine().toCharArray();
		}

		for (int i = 0; i < 4; ++i) {
			System.out.print(c[y][x]);
			int tx = x + dx;
			int ty = y + dy;
			if (tx < 0 || 9 <= tx) {
				dx *= -1;
			}
			if (ty < 0 || 9 <= ty) {
				dy *= -1;
			}
			x += dx;
			y += dy;
		}
		System.out.println();
	}
}