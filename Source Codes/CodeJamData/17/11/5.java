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


public class A2 {
	
	Object solve() {
		int R = sc.nextInt();
		int C = sc.nextInt();
		char[][] m = new char[R][C];
		String[] ms = new String[R];
		for (int i = 0 ; i < R; i++)
			ms[i] = sc.next();
		
		String lastNonEmptyLine = null;
		for (int i = 0; i < R; i++) {
			String sc = ms[i].replaceAll("\\?", "");
			if (sc.length() == 0) {
				if (lastNonEmptyLine != null) {
					ms[i] = lastNonEmptyLine;
				} else {
					String line = null;
					for (int j = i+1; j < R; j++) {
						String sc1 = ms[j].replaceAll("\\?", "");
						if (sc1.length() != 0) {
							line = ms[j];
							break;
						}
					}
					ms[i] = line;
					lastNonEmptyLine = ms[i];
				}
			} else {
				lastNonEmptyLine = ms[i];
			}
		}
		
		fw.println();
		for (int i = 0; i < R; i++) {
			String sc = ms[i].replaceAll("\\?", "");
			char c = sc.charAt(0);
			String r = "";
			for (int j = 0; j < C; j++) {
				if (ms[i].charAt(j) != '?')
					c = ms[i].charAt(j);
				r += c;
			}
			fw.println(r);
		}
		return "";
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A2().solve();
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
		fw.close();
		sc.close();
	}
}
