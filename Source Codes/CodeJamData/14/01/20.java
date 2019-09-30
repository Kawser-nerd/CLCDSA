package world2014.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class MagicTrick {

	public int solve(int r1, int[][] a1, int r2, int[][] a2) {
		Set<Integer> set = new HashSet<Integer>();
		for (int i=0; i<a1[r1].length; i++)
			for (int j=0; j<a2[r2].length; j++)
				if (a1[r1][i]==a2[r2][j])
					set.add(a1[r1][i]);
		if (set.size()==1)
			return set.iterator().next();
		else if (set.size()>1)
			return 0;
		else
			return -1;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2014/qualification_round/A-small-attempt0.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			int r1 = Integer.parseInt(line)-1;
			int[][] a1 = new int[4][4];
			for (int j=0; j<4; j++) {
				line = br.readLine();
				String[] splitted = line.split(" ");
				for (int k=0; k<4; k++)
					a1[j][k] = Integer.parseInt(splitted[k]);
			}
			line = br.readLine();
			int r2 = Integer.parseInt(line)-1;
			int[][] a2 = new int[4][4];
			for (int j=0; j<4; j++) {
				line = br.readLine();
				String[] splitted = line.split(" ");
				for (int k=0; k<4; k++)
					a2[j][k] = Integer.parseInt(splitted[k]);
			}
			int res = new MagicTrick().solve(r1, a1, r2, a2);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": ");
			if (res>0)
				sb.append(res);
			else if (res==0)
				sb.append("Bad magician!");
			else
				sb.append("Volunteer cheated!");
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
