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

	static int a, b, c, d, e, f;
	static double ee;
	static double resDens=0;
	static int resWater=0;
	static int resSugar=0;
	public static void main(String[] args) {
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		d = sc.nextInt();
		e = sc.nextInt();
		ee=(double)e/(double)(e+100);

		f = sc.nextInt();
		for (int i = 0; i <= 30; i++) {
			for (int j = 0; j <= 30; j++) {
				for (int k = 0; k <= 100; k++) {
					for (int l = 0; l <=100; l++) {
						helper(i, j, k, l);
					}
				}
			}
		}
		System.out.print(resWater+resSugar);
		System.out.print(" "+resSugar);
		
		
	}

	private static void helper(int i, int j, int k, int l) {
		// TODO Auto-generated method stub
		int water=100*i*a+100*j*b;
		int sugar=k*c+l*d;
		if(water==0)
			return;
		if(water+sugar>f)
			return;
		double dens=(double)sugar/(double)(sugar+water);

		if(dens>ee) return;
		if(dens>resDens){
			resDens=dens;
			resWater=water;
			resSugar=sugar;
		}
		if(dens==resDens){
			if(water>resWater){
				resSugar=sugar;
				resWater=water;
			}

		}

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