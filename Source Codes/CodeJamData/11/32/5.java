import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class B {
	

	Object solve() {
		int L = sc.nextInt();
		long t = sc.nextLong();
		int N = sc.nextInt();
		int C = sc.nextInt();
		
		int[] b = new int[C];
		for (int i = 0; i < C; i++)
			b[i] = sc.nextInt();
		
		long[] a = new long[N];
		loop:
		for (int i = 0;; i++) {
			for (int j = 0; j < C; j++) {
				int k = i*C + j;
				if (k >= N) break loop;
				a[k] = b[j]*2;
			}
		}

		long sum = 0;
		long time = 0;
		boolean add = false;
		ArrayList<Long> f = new ArrayList<Long>();
		for (int i = 0; i < N; i++) {
			if (add) {
				f.add(a[i]);
			} else {
				if (sum + a[i] > t) {
					f.add(sum + a[i] - t);
					add = true;
					sum = t;
				} else
					sum += a[i];
			}
		}
		
		sort(f, Collections.reverseOrder());
		
		for (int i = 0; i < L && i < f.size(); i++)
			sum += f.get(i)/2;
		
		for (int i = L; i < f.size(); i++)
			sum += f.get(i);
		
		return sum;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
//		inFile = "input.txt";
//		inFile = "B-small-attempt0.in";
		inFile = "B-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
