import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static boolean debug = true;
	static Scanner sc = new Scanner(System.in);

	static long max = Long.MIN_VALUE;

	public static void main(String[] args) throws Exception {
		long H = sc.nextLong();
		long W = sc.nextLong();
		long res = Long.MAX_VALUE;
		long[] arr = new long[3];
		arr[0] = H / 3;
		arr[1] = (H - arr[0]) / 2;
		arr[2] = H - arr[0] - arr[1];
		res = Math.min(res, helper(arr) * W);
		arr[0] = W / 3;
		arr[1] = (W - arr[0]) / 2;
		arr[2] = W - arr[0] - arr[1];
		res = Math.min(res, helper(arr) * H);
		long k = W / 2;
		long l = W - W / 2;

		boolean tag = true;
		for (int i = 1; i < H; i++) {
			arr[0] = i * W;
			arr[1] = (H - i) * k;
			arr[2] = (H - i) * l;
			res = Math.min(res, helper(arr));
		}

		k = H / 2;
		l = H - H / 2;
		for (int i = 1; i < W; i++) {
			arr[0] = i * H;
			arr[1] = (W - i) * k;
			arr[2] = (W - i) * l;
			res = Math.min(res, helper(arr));
		}
		System.out.println(res);
	}

	private static long helper(long[] arr) {
		// TODO Auto-generated method stub
		Arrays.sort(arr);
		return arr[2] - arr[0];
	}

	private static void print(String string) {
		// TODO Auto-generated method stub
		if (debug)
			System.out.println(string);
	}

	private static void print(int[] data) {
		if (debug) {
			for (int i = 0; i < data.length; i++)
				System.out.println(i + ":" + data[i]);
		}
	}

	private static void print(String[] data) {
		if (debug) {
			for (int i = 0; i < data.length; i++)
				System.out.println(i + ":" + data[i]);
		}
	}

	private static void print(char[] data) {
		if (debug) {
			for (int i = 0; i < data.length; i++)
				System.out.println(i + ":" + data[i]);
		}
	}

	private static void print(double[] data) {
		if (debug) {
			for (int i = 0; i < data.length; i++)
				System.out.println(i + ":" + data[i]);
		}
	}
	private static void print(long[] data) {
		if (debug) {
			for (int i = 0; i < data.length; i++)
				System.out.println(i + ":" + data[i]);
		}
	}

	private static void print(int[][] data) {

		if (debug) {
			for (int i = 0; i < data.length; i++) {
				for (int j = 0; j < data[0].length; j++) {
					System.out.print(data[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
	private static void print(long[][] data) {

		if (debug) {
			for (int i = 0; i < data.length; i++) {
				for (int j = 0; j < data[0].length; j++) {
					System.out.print(data[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

	private static void print(char[][] data) {

		if (debug) {
			for (int i = 0; i < data.length; i++) {
				for (int j = 0; j < data[0].length; j++) {
					System.out.print(i + " " + j + ":" + data[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

	private static void print(String[][] data) {

		if (debug) {
			for (int i = 0; i < data.length; i++) {
				for (int j = 0; j < data[0].length; j++) {
					System.out.print(i + " " + j + ":" + data[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

	private static void print(double[][] data) {

		if (debug) {
			for (int i = 0; i < data[0].length; i++) {
				for (int j = 0; j < data.length; j++) {
					System.out.print(i + " " + j + ":" + data[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

	public static void inPutData(char[][] c) {
		for (int i = 0; i < c.length; i++) {
			c[i] = sc.nextLine().toCharArray();
		}
	}

}