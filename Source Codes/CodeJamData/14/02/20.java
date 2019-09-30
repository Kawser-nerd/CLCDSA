package world2014.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CookieClickerAlpha {

	public double solve(double C, double F, double X) {
		double cc = 2.0;
		double time = 0.0;
		for (;;) {
			double t1 = X/cc;
			double t2 = C/cc + X/(cc+F);
			if (t1<t2)
				return time+t1;
			else {
				time += C/cc;
				cc += F;
			}
		}
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2014/qualification_round/B-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			String[] splitted = line.split(" ");
			double C = Double.parseDouble(splitted[0]);
			double F = Double.parseDouble(splitted[1]);
			double X = Double.parseDouble(splitted[2]);
			double res = new CookieClickerAlpha().solve(C, F, X);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
