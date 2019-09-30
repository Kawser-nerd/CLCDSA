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

class a {
	public a(int i, int j, int k) {
		p1 = i;
		p2 = j;
		length = k;
	}

	int p1;
	int p2;
	int length;
}

public class Main {
	static boolean debug = true;
	static Scanner sc = new Scanner(System.in);
	static int[][] map;

	public static void main(String[] args) {
		int n = sc.nextInt();
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		System.out.println(floyd(map));

	}

	private static long floyd(int[][] map) {
		// TODO Auto-generated method stub
		long count=0;
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map.length; j++) {
				boolean tag=true;
				for (int k = 0; k < map.length; k++) {
					if (k != i && k != j) {
						if (map[i][k] + map[k][j] < map[i][j])
							return -1;
						else if(map[i][k] + map[k][j] == map[i][j]){
							tag=false;
							break;
						}
					}
				}
				if(tag) count+=map[i][j];
			}
		}
		return count/2;
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