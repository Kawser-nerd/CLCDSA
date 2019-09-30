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
		boolean[] isp = new boolean[1000001];
		Arrays.fill(isp, true);
		isp[0] = isp[1] = false;
		for(int i = 2; i < isp.length; i++) {
			if(isp[i]) {
				for(int j = i + i; j < isp.length; j += i)
					isp[j] = false;
			}
		}
		int tN = sc.nextInt();
		for (int tn = 1; tn <= tN; tn++) {
			int res = 0;
			long n = sc.nextLong();
			System.out.println(n);
			for(long i = 0; i * i <= n; i++) {
				if(isp[(int)i]) {
					long tmp = i * i;
					while(tmp <= n ) {
//						System.out.println(i);
						tmp *= i;
						res++;
					}
				}
			}
			if(n > 1)
				res++;
			pw.format("Case #%d: %d\n", tn, res);
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
