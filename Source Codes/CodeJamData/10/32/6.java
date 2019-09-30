package b;

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

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Date start = new Date();

		try {
			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("B-in.txt"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("B-out.txt"), "utf8"));

			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("B-small.in"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("B-small.out"), "utf8"));

			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("B-large.in"), "utf8"));
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("B-large.out"), "utf8"));

			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

			String line = reader.readLine();
			int caseCount = Integer.valueOf(line);
			for (int index = 0; index < caseCount; index++) {
				line = reader.readLine().trim();
				if (line != null) {
					writer.write("Case #" + (index + 1) + ": ");
					String[] parts = line.split(" ");
					L = Long.valueOf(parts[0]);
					P = Long.valueOf(parts[1]);
					C = Long.valueOf(parts[2]);

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

	private static long L;
	private static long P;
	private static long C;

	private static long calculate() {
		long count = 0;

		double p = P;
		double l = L;
		double c = C;
		double x = Math.ceil(Math.log(p / l) / Math.log(c));
		count = new Double(Math.ceil(Math.log(x) / Math.log(2))).longValue();

		return count;
	}
}
