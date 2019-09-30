package c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.text.NumberFormat;
import java.util.Date;
import java.util.Locale;

public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Date start = new Date();

		try {
			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-in.txt"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-out.txt"), "utf8"));

			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-small.in"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-small.out"), "utf8"));

			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-large.in"), "utf8"));
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-large.out"), "utf8"));

			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

			String line = reader.readLine();
			int caseCount = Integer.valueOf(line);
			for (int index = 0; index < caseCount; index++) {
				line = reader.readLine();
				if (line != null) {
					writer.write("Case #" + (index + 1) + ": ");
					String[] params = line.split(" ");
					N = Integer.valueOf(params[0]);

					x = new double[N];
					y = new double[N];
					z = new double[N];
					p = new double[N];
					for (int i = 0; i < N; i++) {
						line = reader.readLine();
						params = line.split(" ");
						x[i] = Double.valueOf(params[0]);
						y[i] = Double.valueOf(params[1]);
						z[i] = Double.valueOf(params[2]);
						p[i] = Double.valueOf(params[3]);
					}

					NumberFormat formatter = NumberFormat.getInstance(new Locale("en"));
					formatter.setGroupingUsed(false);
					formatter.setMinimumFractionDigits(6);
					formatter.setMaximumFractionDigits(6);
					writer.write(formatter.format(calculate()));
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

	static int N;

	static double x[];
	static double y[];
	static double z[];
	static double p[];

	private static double calculate() {
		double maxP = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				double p = calc(i, j);

				if (maxP == 0 || maxP < p) {
					maxP = p;
				}
			}
		}

		return maxP;
	}

	private static double calc(int i, int j) {
		double ratio = p[i] / (p[i] + p[j]);
		double xx = (x[j] - x[i]) * ratio + x[i];
		double yy = (y[j] - y[i]) * ratio + y[i];
		double zz = (z[j] - z[i]) * ratio + z[i];
		double pp = power(i, xx, yy, zz);
		return pp;
		// return Math.max(power(i, xx, yy, zz), power(j, xx, yy, zz));
	}

	private static double dist2(int i, int j) {
		return Math.abs(x[i] - x[j]) * Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]) * Math.abs(y[i] - y[j]) + Math.abs(z[i] - z[j]) * Math.abs(z[i] - z[j]);
	}

	private static double dist2(int i, double xx, double yy, double zz) {
		return Math.abs(x[i] - xx) * Math.abs(x[i] - xx) + Math.abs(y[i] - yy) * Math.abs(y[i] - yy) + Math.abs(z[i] - zz) * Math.abs(z[i] - zz);
	}

	private static double power(int i, double xx, double yy, double zz) {
		return (Math.abs(x[i] - xx) + Math.abs(y[i] - yy) + Math.abs(z[i] - zz)) / p[i];
	}

}
