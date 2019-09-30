import java.io.*;
import java.util.*;

public class SecondRoundProbD {
	public static final String problemType = "small";
	public static void main(String[] args) {
		try {
			String input = problemType.startsWith("s") ? "D-" + problemType + "-attempt0.in" : "D-" + problemType + ".in";
			
			BufferedReader br = new BufferedReader(new FileReader(input));
			PrintWriter pw = new PrintWriter(new FileWriter(input + "Res.txt"));

			String s = br.readLine();

			int NR_CASES = Integer.parseInt(s);
			for(int CASE = 1; CASE <= NR_CASES; CASE++) {
				s = br.readLine();
				String[] strs = s.split(" ");
				int N = Integer.parseInt(strs[0]);
				int M = Integer.parseInt(strs[1]);
				
				int[] px = new int[N];
				int[] py = new int[N];
				int[] mx = new int[M];
				int[] my = new int[M];
				
				for(int i = 0; i < N; i++) {
					s = br.readLine();
					strs = s.split(" ");
					px[i] = Integer.parseInt(strs[0]);
					py[i] = Integer.parseInt(strs[1]);
				}
				for(int i = 0; i < M; i++) {
					s = br.readLine();
					strs = s.split(" ");
					mx[i] = Integer.parseInt(strs[0]);
					my[i] = Integer.parseInt(strs[1]);
				}
				
				String res = "";
				
				double d = Math.sqrt((px[1] - px[0]) * (px[1] - px[0]) + (py[1] - py[0]) * (py[1] - py[0]));
				for(int i = 0; i < M; i++) {
					int r1sq = (px[0] - mx[i]) * (px[0] - mx[i]) + (py[0] - my[i]) * (py[0] - my[i]);
					double r1 = Math.sqrt(r1sq);
					int r2sq = (px[1] - mx[i]) * (px[1] - mx[i]) + (py[1] - my[i]) * (py[1] - my[i]);
					double r2 = Math.sqrt(r2sq);
					
					double x = ((r1sq - r2sq) / d + d) / 2.0;
					double y = d - x;
					double alpha = 2 * Math.acos(x / r1);
					double betta = 2 * Math.acos(y / r2);
					
					double area = (alpha * r1sq - r1sq * Math.sin(alpha) + betta * r2sq - r2sq * Math.sin(betta)) / 2.0;
					res += " " + area;
				}

				pw.println("Case #" + CASE + ": " + res.trim());
			}

			pw.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
