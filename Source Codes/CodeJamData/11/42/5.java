import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		Thread thread = new Thread(new Main());
		thread.start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (int) (st.nval);
	}

	long nextLong(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (long) (st.nval);
	}

	BigInteger nextBI(StreamTokenizer st) throws IOException {
		st.nextToken();
		return new BigInteger(st.sval);
	}

	String nextString(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.sval;
	}

	double nextDouble(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.nval;
	}

	Map<Long, double[]> res = new HashMap<Long, double[]>();

	public void run1() throws IOException {
		InputStream inputStream = new FileInputStream("input.txt");
		// InputStream inputStream = System.in;
		Scanner sc = new Scanner(new InputStreamReader(inputStream));
		// StreamTokenizer st = new StreamTokenizer(inputStream);
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(inputStream));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		for (int tn = 1; tn <= tN; tn++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			int[][] arr = new int[r][c];
			int[][] tmp1 = new int[r][c];
			int[][] tmp2 = new int[r][c];
			for (int i = 0; i < r; i++) {
				String tmp = sc.next();
				for (int j = 0; j < c; j++) {
					arr[i][j] = tmp.charAt(j) - '0';
					tmp1[i][j] = arr[i][j] * i;
					tmp2[i][j] = arr[i][j] * j;
				}
			}
			SumHolder sumh1 = new SumHolder(arr);
			SumHolder sumh2 = new SumHolder(tmp1);
			SumHolder sumh3 = new SumHolder(tmp2);
			int res = 0;
			oppa: for (int size = Math.min(r, c); size >= 3; size--) {
				for (int i = 0; i + size <= r; i++)
					for (int j = 0; j + size <= c; j++) {
//						int sumx = 0;
//						int sumy = 0;
//						int sum = 0;
//						for (int i1 = i; i1 < i + size; i1++)
//							for (int j1 = j; j1 < j + size; j1++) {
//								sumx += i1 * arr[i1][j1];
//								sumy += j1 * arr[i1][j1];
//								sum += arr[i1][j1];
//							}
						int sum = sumh1.get(i, i + size, j, j + size);
						int sumx = sumh2.get(i, i + size, j, j + size);
						int sumy = sumh3.get(i, i + size, j, j + size);
//						if(sum != sumh1.get(i, i + size, j, j + size)){
//							System.out.println("gopa");
//							System.out.println(i + " " + j + " " + size + " " + sum + " " + sumh1.get(i, i + size, j, j + size));
//						}
//						if(sumx != sumh2.get(i, i + size, j, j + size)){
//							System.out.println("gopa");
//							System.out.println(i + " " + j + " " + size + " " + sumx + " " + sumh2.get(i, i + size, j, j + size));
//						}
//						if(sumy != sumh3.get(i, i + size, j, j + size)){
//							System.out.println("gopa");
//							System.out.println(i + " " + j + " " + size + " " + sumy + " " + sumh3.get(i, i + size, j, j + size));
//						}
						sumx -= i * (arr[i][j] + arr[i][j + size - 1]);
						sumx -= (i + size - 1)
								* (arr[i + size - 1][j] + arr[i + size - 1][j
										+ size - 1]);
						sumy -= j * (arr[i][j] + arr[i + size - 1][j]);
						sumy -= (j + size - 1)
								* (arr[i][j + size - 1] + arr[i + size - 1][j
										+ size - 1]);
						sum -= arr[i][j] + arr[i][j + size - 1]
								+ arr[i + size - 1][j]
								+ arr[i + size - 1][j + size - 1];
						// System.out.println(sumx + " " + sumy);
						if (sumx * 2 == i * 2 * sum + (size - 1) * sum
								&& sumy * 2 == j * 2 * sum + (size - 1) * sum) {
							res = size;
							break oppa;
						}
					}
			}
			if (res != 0)
				pw.format("Case #%d: %d\n", tn, res);
			else
				pw.format("Case #%d: IMPOSSIBLE\n", tn);
		}
		pw.close();
	}

	private class SumHolder {
		int[][] arr;
		int n;
		int[][] first;
		int[][] second;

		SumHolder(int[][] arr1) {
			arr = arr1;
			int r = arr1.length;
			int c = arr1[0].length;
			first = new int[r + 1][c];
			second = new int[r + 1][c + 1];
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) {
					first[i + 1][j] = first[i][j] + arr[i][j];
				}
			for (int i = 0; i <= r; i++)
				for (int j = 0; j < c; j++) {
					second[i][j + 1] = second[i][j] + first[i][j];
//					System.out.println(i + " " + j + " " + second[i][j]);
				}
		}
		
		int get(int l1, int r1, int l2, int r2) {
			return second[r1][r2] + second[l1][l2] - second[l1][r2] - second[r1][l2];
		}
	}
}
