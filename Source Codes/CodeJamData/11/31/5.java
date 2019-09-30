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
		int R = sc.nextInt(), C = sc.nextInt();
		char[][] m = new char[R][C];
		
		for (int i = 0; i < R; i++)
			m[i] = sc.next().toCharArray();
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (m[i][j] == '#') {
					if (j == C - 1 || i == R - 1)
						return "\nImpossible";
					
					if (m[i][j+1] == '#' && m[i+1][j] == '#'  && m[i+1][j+1] == '#') {
						m[i][j] = '/';
						m[i][j+1] = '\\';
						m[i+1][j] = '\\';
						m[i+1][j+1] = '/';
					} else return "\nImpossible";
				}
			}
		}
		
		String s = "";
		for (int i = 0; i < R; i++) {
			s += '\n' + new String(m[i]);
		}
		return s;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
//		inFile = "input.txt";
//		inFile = "A-small-attempt0.in";
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
