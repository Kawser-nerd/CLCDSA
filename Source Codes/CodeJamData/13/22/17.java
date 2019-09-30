package Rnd1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class FallingDiamonds {
	static int resX, resY;
	static double ans;
	static int[] X;
	static int[] Y;

	public static boolean exist(int i, int j) {
		for (int k = 0; k < X.length; k++)
			if (X[k] == i && Y[k] == j)
				return true;
		return false;
	}

	public static void rec(int index, int x, int y, double p) {
		if (index == -1) {
			boolean can = false;
			for (int j = 0; j < X.length; j++)
				can |= X[j] == resX && Y[j] == resY;
			if (can)
				ans += p;
			return;
		}
		if (y == 0) {
			X[index] = x;
			Y[index] = y;
			rec(index - 1, 0, 50, p);
			return;
		}
		if (!exist(x, y - 2) && y != 1)
			rec(index, x, y - 1, p);
		else {
			boolean left = exist(x - 1, y - 1);
			boolean right = exist(x + 1, y - 1);
			if (left && right) {
				X[index] = x;
				Y[index] = y;
				rec(index - 1, 0, 50, p);
			} else if (left)
				rec(index, x + 1, y - 1, p);
			else if (right)
				rec(index, x - 1, y - 1, p);
			else {
				rec(index, x + 1, y - 1, p * 0.5);
				rec(index, x - 1, y - 1, p * 0.5);
			}
		}
		X[index] = Y[index] = -10;
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("output.txt"));
		int t = in.nextInt();
		for (int m = 1; m <= t; m++) {
			int n = in.nextInt();
			X = new int[n];
			Y = new int[n];
			Arrays.fill(X, -10);
			Arrays.fill(Y, -10);
			X[n - 1] = Y[n - 1] = 0;
			resX = in.nextInt();
			resY = in.nextInt();
			ans = 0;
			rec(n - 2, 0, 50, 1);
			out.println("Case #" + m + ": " + ans);
		}
		out.flush();
		out.close();
	}
}
