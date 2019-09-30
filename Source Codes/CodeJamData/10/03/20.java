package code10.qualification;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class C {
	public static String solve(long R, long k, int n, int[] g) {
		long money = 0;
		int oldIndex = 0;
		int index = 0;
		long gSum = 0;
		long temp = 0;
		
		for (long i = 0; i < R; i++) {
			gSum = 0;
			oldIndex = index;
			while (true) {
				temp = gSum + g[index];
				if (temp <= k) {
					gSum = temp;
					index++;
					if (index >= g.length) {
						index = 0;
					}
					if (index == oldIndex) {
						break;
					}
				} else {
					break;
				}
			}
			money += gSum;
		}

		return money + "";
	}

	public static void main(String[] args) throws Exception {
//		String fileName = "Sample";
//		String fileName = "C-small";
		String fileName = "C-large";
		
		File inputFile = new File(fileName + ".in");
		File outputFile = new File(fileName + ".out");
		FileReader reader = new FileReader(inputFile);
		FileWriter writer = new FileWriter(outputFile);
		StringBuilder inputLine = new StringBuilder();
		String[] inputPart;

		int totalCase;
		char c = 0;
		
		long R = 0;
		long k = 0;
		int N = 0;
		int[] g;

		// get total case
		while ((c = (char)reader.read()) != '\n') {
			inputLine.append(c);
		}
		totalCase = Integer.parseInt(inputLine.toString());

		for (int caseIndex = 1; caseIndex <= totalCase; caseIndex++) {
			// get R, k, N
			inputLine = new StringBuilder();
			while ((c = (char)reader.read()) != '\n') {
				inputLine.append(c);
			}
			inputPart = inputLine.toString().split(" ");
			R = Long.parseLong(inputPart[0]);
			k = Long.parseLong(inputPart[1]);
			N = Integer.parseInt(inputPart[2]);
			g = new int[N];
			
			// get gi
			inputLine = new StringBuilder();
			while ((c = (char)reader.read()) != '\n') {
				inputLine.append(c);
			}
			inputPart = inputLine.toString().split(" ");
			for (int i = 0; i < N; i++) {
				g[i] = Integer.parseInt(inputPart[i]);
			}

			String output = "Case #" + caseIndex + ": " + solve(R, k, N, g);
			System.out.println(output);
			writer.write(output + "\n");
		}
		reader.close();
		writer.close();
	}
}
