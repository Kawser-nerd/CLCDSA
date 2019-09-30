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


public class A {
	

	Object solve() {
		int N = sc.nextInt();
		int[] S = new int[N];
		int sum = 0;
		for (int i = 0; i < N; i++) {
			S[i] = sc.nextInt();
			sum += S[i];
		}
		
		String res = "";
		for (int i = 0; i < N; i++) {
			double low = 0, high = 1;
			for (int j = 0; j < 300; j++) {
				double m = (low + high)/2;
				double score = S[i] + sum*m;
				double rem = 0;
				for (int k = 0; k < N; k++) {
					if (k != i && S[k] < score) {
						rem += score - S[k];
					}
				}
				if (rem < sum*(1-m)) {
					low = m;
				} else {
					high = m;
				}
			}
			res = res + " " + low*100;
		}
		
		return res.substring(1);
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
		inFile = "input.txt";
		inFile = "A-small-attempt0.in";
		inFile = "A-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
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
