import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

public class Program implements Runnable{
	private static BufferedReader br;
	private static PrintWriter out;
	private static StringTokenizer stk;
	
	public static void main(String[] args) throws FileNotFoundException {
		br = new BufferedReader(new FileReader("D:\\A-large.in"));
		out = new PrintWriter(new File("D:\\A-out.txt"));
		(new Thread(new Program())).start();
	}
	
	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private String nextLine() {
		try {
			return br.readLine();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	private Integer nextInt() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	private Long nextLong() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	private Double nextDouble() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	private String nextWord() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return stk.nextToken();
	}
	
	public void run() {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			int n = nextInt();
			int[] arr = new int[n];
			int[] arr2 = new int[n];
			for (int i = 0; i < n; ++i) {
				String str = nextLine();
				arr[i] = str.lastIndexOf('1');
			}
			
			int res = 0;
			for (int i = 0; i < n; ++i) {
				if (arr[i] > i) {
					int mini = i;
					for (int j = i; j < n; ++j) {
						if (arr[j] <= i) {
							mini = j;
							break;
						}
					}
				
					res += mini - i;
					int tmp = arr[mini];
					for (int j = mini; j > i; --j) {
						arr[j] = arr[j-1];
					}
					arr[i] = tmp;
				}
			}
			
			out.println("Case #" + (tt+1) + ": " + res);
		}
		out.flush();
	}
	
}
