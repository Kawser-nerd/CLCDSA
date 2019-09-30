package CodeJam;

import java.util.*;
import java.io.*;


public class A {

	private static String inFilename = "A-large.in";

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("src/CodeJam/" + inFilename));
		PrintWriter out = new PrintWriter(new FileWriter("src/CodeJam/output.txt"));
		int T = in.nextInt();

		for (int t = 0; t < T; t++) {
			String result = "";

			int R = in.nextInt();
			int C = in.nextInt();
			in.nextLine();
			char[][] data = new char[R][C];
			for (int i = 0; i < R; i++) {
				data[i] = in.nextLine().toCharArray();
			}

			loop:
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (data[i][j] == '#') {
						data[i][j] = '/';
						if (j+1 < C && data[i][j+1] == '#') {
							data[i][j+1] = '\\';
						} else {
							result = "Impossible\n";
							break loop;
						}
						if (i+1 < R && data[i+1][j] == '#') {
							data[i+1][j] = '\\';
						} else {
							result = "Impossible\n";
							break loop;
						}
						if (i+1 < R && j+1 < C && data[i+1][j+1] == '#') {
							data[i+1][j+1] = '/';
						} else {
							result = "Impossible\n";
							break loop;
						}
					}
				}
			}

			if (result.equals("")) {
				for (int i = 0; i < R; i++) {
					result += new String(data[i]) + "\n";
				}
			}


			out.print("Case #" + (t+1) + ":\n" + result);
		}

		in.close();
		out.close();
	}

}