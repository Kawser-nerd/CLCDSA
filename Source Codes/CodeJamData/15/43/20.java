package world2015.round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.TreeMap;

public class Bilingual {

	public int solveForSmall(int N, String[] sentences) {
		TreeMap<String, Integer> words = new TreeMap<>();
		for (int i=0; i<N; i++) {
			String[] tokens = sentences[i].split(" ");
			for (int j=0; j<tokens.length; j++) {
				Integer status = words.get(tokens[j]);
				if (status==null)
					status = new Integer(0);
				status |= 1<<i;
				words.put(tokens[j], status);
			}
		}
		int min = -1;
		for (int s=0; s<(1<<(N-2)); s++) {
			int ss = (s<<2) | 2;
			int num = solve(words, ss);
			if (min==-1 || num<min)
				min = num;
		}
		return min;
	}
	
	private int solve(TreeMap<String, Integer> words, int s) {
		int cnt = 0;
		for (int status : words.values())
			if ((status&s)!=0 && (status&~s)!=0)
				cnt++;
		return cnt;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round2/C-small-attempt1.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			int N = Integer.parseInt(tokens[0]);
			String[] sentences = new String[N];
			for (int j=0; j<N; j++)
				sentences[j] = br.readLine().trim();
			int res = new Bilingual().solveForSmall(N, sentences);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
