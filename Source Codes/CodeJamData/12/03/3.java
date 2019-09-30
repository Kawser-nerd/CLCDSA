
import java.io.*;
import java.util.*;

public class CodeJam2012_Q_C {

	public int calc(int A, int B) {
		boolean[] checked = new boolean[B-A+1];
		int cnt = 0;
		int D = String.valueOf(A).length();
		int unit =1;
		for(int i=1; i<D; i++) unit*=10;
		
		for(int i=A; i<=B; i++) {
			if(!checked[i-A]) {
				checked[i-A] = true;
				int groupNum = 1;
				int cycled = i;
				for(int j=1; j<D; j++) {
					cycled = cycled/10+(cycled%10)*unit;
					if(A<=cycled && cycled<=B && !checked[cycled-A]) {
						groupNum++;
						checked[cycled-A] = true;
					}
				}
				cnt += groupNum*(groupNum-1)/2;
			}
		}
				
		return cnt;
	}
	
	public static void main(String[] args) {
		try{
//			(new CodeJam2012_Q_C()).exec("C-small-attempt0.in", "2012_Q_C-small.out");
			(new CodeJam2012_Q_C()).exec("C-large.in", "2012_Q_C-large.out");
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
			int A = Integer.valueOf(input[0]);
			int B = Integer.valueOf(input[1]);
			int outStr = calc(A, B);

			String fmtOutStr="Case #" + (i+1) + ": " + outStr;	
			outWriter.println(fmtOutStr);
			System.out.println(fmtOutStr);
		}
		System.out.println(caseNums + " cases complete");

		outWriter.close();
		inReader.close();
	}
}
