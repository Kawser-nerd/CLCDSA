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
		long L = sc.nextLong();
		long H = sc.nextLong();
		
		long[] a = new long[N];
		for (int i = 0; i < N; i++)
			a[i] = sc.nextLong();

		loop:
		for (long m = L; m <= H; m++) {
			for (int i = 0; i < N; i++) {
				if (a[i]%m != 0 && m%a[i] != 0)
					continue loop;
			}
			return m;
		}
		return "NO";
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
//		inFile = "input.txt";
		inFile = "C-small-attempt0.in";
//		inFile = "A-large.in";
		
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
