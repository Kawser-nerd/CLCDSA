package a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.Date;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Date start = new Date();

		try {
			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-in.txt"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("A-out.txt"), "utf8"));

			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("A-small.out"), "utf8"));

			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in"), "utf8"));
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("A-large.out"), "utf8"));

			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

			String line = reader.readLine();
			int caseCount = Integer.valueOf(line);
			for (int index = 0; index < caseCount; index++) {
				line = reader.readLine();
				if (line != null) {
					writer.write("Case #" + (index + 1) + ": ");
					String[] parts = line.split(" ");
					N = Integer.valueOf(parts[0]);

					A = new int[N];
					B = new int[N];
					for (int i = 0; i < N; i++) {
						line = reader.readLine();
						parts = line.split(" ");
						A[i] = Integer.valueOf(parts[0]);
						B[i] = Integer.valueOf(parts[1]);
					}

					writer.write(new Long(calculate()).toString());
					writer.newLine();
					writer.flush();
				} else {
					throw new RuntimeException("Fewer testcases (" + index + ") than expected (" + caseCount + ")!");
				}
			}

			reader.close();
			writer.close();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		Date end = new Date();
		System.err.println("Finished in " + (end.getTime() - start.getTime()) + "ms.");
	}

	private static int N;
	private static int A[];
	private static int B[];

	private static long calculate() {
		long intersections = 0;

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (((A[j] > A[i]) && (B[j] < B[i])) || ((A[j] < A[i]) && (B[j] > B[i]))) {
					intersections++;
				}
			}
		}

		return intersections;
	}

}
