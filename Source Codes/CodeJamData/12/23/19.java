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


public class C {
	

	Object solve() {
		int N = sc.nextInt();
		s = new long[N];
		for (int i = 0; i < N; i++)
			s[i] = sc.nextLong();
		
		HashMap<Long,Integer> sums = new HashMap<Long, Integer>();
		
		for (int bm = 1; bm < (1<<20); bm++) {
			long summe = sum(bm);
			if (sums.containsKey(summe)) {
				String res = "\n";
				res += subset(sums.get(summe)) + "\n";
				res += subset(bm);
				return res;
			}
			sums.put(summe, bm);
		}
		
		return "\nImpossible";
	}
	
	String subset(int bm) {
		String res = "";
		for (int i = 0; i < 20; i++) {
			if (((bm>>i)&1) == 1)
				res += " " + s[i];
		}
		return res.substring(1);
	}
	
	long sum(int bm) {
		long sum = 0;
		for (int i = 0; i < 20; i++) {
			if (((bm>>i)&1) == 1)
				sum += s[i];
		}
		return sum;
	}
	

	private static Scanner sc; private static PrintWriter fw;

	private long[] s;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "C-small-attempt0.in";
//		inFile = "C-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new C().solve();
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
