package code10.qualification;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class A {
	public static String solve(int N, long K, int[] times) {
		String result = "";
		int time = times[N];

		if (K < time) {
			result = "OFF";
		} else if (K == time) {
			result = "ON";
		} else {
			long remain = K - time;
			if (remain % (time + 1) == 0) {
				result = "ON";
			} else {
				result = "OFF";
			}
		}
		
		return result;
	}
	
	public static void initTimes(int[] times) {
		times[1] = 1;
		
		for (int i = 2; i < times.length; i++) {
			times[i] = times[i - 1] * 2 + 1;
		}
	}

	public static void main(String[] args) throws Exception {
//		String fileName = "Sample";
//		String fileName = "A-small";
		String fileName = "A-large";
		
		File inputFile = new File(fileName + ".in");
		File outputFile = new File(fileName + ".out");
		FileReader reader = new FileReader(inputFile);
		FileWriter writer = new FileWriter(outputFile);
		StringBuilder inputLine = new StringBuilder();
		String[] inputPart;

		int totalCase;
		char c = 0;
		
		int N = 0;
		long K = 0;
		
		int[] times = new int[31];
		initTimes(times);
		
		// get total case
		while ((c = (char)reader.read()) != '\n') {
			inputLine.append(c);
		}
		totalCase = Integer.parseInt(inputLine.toString());

		for (int caseIndex = 1; caseIndex <= totalCase; caseIndex++) {
			// get N and K
			inputLine = new StringBuilder();
			while ((c = (char)reader.read()) != '\n') {
				inputLine.append(c);
			}
			inputPart = inputLine.toString().split(" ");
			N = Integer.parseInt(inputPart[0]);
			K = Long.parseLong(inputPart[1]);

			String output = "Case #" + caseIndex + ": " + solve(N, K, times);
			System.out.println(output);
			writer.write(output + "\n");
		}
		reader.close();
		writer.close();
	}
}
