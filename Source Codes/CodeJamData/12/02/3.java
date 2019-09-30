
import java.io.*;
import java.util.*;

public class CodeJam2012_Q_B {

	public int calc(int N, int S, int p, int[] score) {
		int cnt=0;
		for(int i=0; i<N; i++) {
			if(score[i] >= p+Math.max(p-1, 0)*2) {
				cnt++;
			} else if(score[i]>=p+Math.max(p-2, 0)*2 && S>0) {
				cnt++;
				S--;
			}
		}
		
		return cnt;
	}
	
	public static void main(String[] args) {
		try{
			(new CodeJam2012_Q_B()).exec("B-large.in", "2012_Q_B-large.out");
			}catch(Exception ex) {
				
			}
	}

	public final void exec(String inFileName, String outFileName) throws Exception{
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));
		int caseNums=0;
		caseNums = Integer.parseInt(inReader.readLine());
		
		for(int i=0; i<caseNums; i++) {
			String[] input = inReader.readLine().split(" ");
			int N = Integer.valueOf(input[0]);
			int S = Integer.valueOf(input[1]);
			int p = Integer.valueOf(input[2]);
			int[] score = new int[N];
			for(int j=0; j<N; j++)
				score[j] = Integer.valueOf(input[j+3]);
			int outStr = calc(N, S, p, score);

			String fmtOutStr="Case #" + (i+1) + ": " + outStr;	
			outWriter.println(fmtOutStr);
			System.out.println(fmtOutStr);
		}
		System.out.println(caseNums + " cases complete");

		outWriter.close();
		inReader.close();
	}
}
