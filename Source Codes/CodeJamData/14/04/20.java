package world2014.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class DeceitfulWar {

	public int[] solve(int N, double[] naomi, double[] ken) {
		Arrays.sort(naomi);
		Arrays.sort(ken);
		return new int[]{this.winDeceitfulWar(N, naomi, ken), this.winWar(N, naomi, ken)};
	}
	
	private int winDeceitfulWar(int N, double[] naomi, double[] ken) {
		int win = 0;
		int kidx = 0;
		for (int i=0; i<N; i++)
			if (naomi[i]>ken[kidx]) {
				win++;
				kidx++;
			}
		return win;
	}
	
	private int winWar(int N, double[] naomi, double[] ken) {
		int win = 0;
		int kidx = N-1;
		for (int i=N-1; i>=0; i--)
			if (naomi[i]>ken[kidx])
				win++;
			else
				kidx--;
		return win;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2014/qualification_round/D-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			int N = Integer.parseInt(line);
			double[] naomi = new double[N];
			String[] splitted = br.readLine().split(" ");
			for (int j=0; j<N; j++)
				naomi[j] = Double.parseDouble(splitted[j]);
			double[] ken = new double[N];
			splitted = br.readLine().split(" ");
			for (int j=0; j<N; j++)
				ken[j] = Double.parseDouble(splitted[j]);
			int[] res = new DeceitfulWar().solve(N, naomi, ken);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res[0] + " " + res[1]);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
