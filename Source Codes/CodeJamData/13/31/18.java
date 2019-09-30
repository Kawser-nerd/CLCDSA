import java.io.*;
import java.util.*;

public class Prob1 {
	public static final String vowels = "aeiou";
	
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter("out1.txt"));
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		
		int nrTests = Integer.parseInt(br.readLine());
		for(int testNr = 1; testNr <= nrTests; testNr++) {
			String[] strs = br.readLine().split(" ");
			int res = 0;
			int n = Integer.parseInt(strs[1]);
			char[] chr = strs[0].toCharArray();
			for(int i = 0; i < chr.length; i++) {
				int nrC = 0;
				boolean isOk = false;
				for(int j = i; j < chr.length; j++) {
					if(vowels.indexOf(chr[j]) == -1) {
						nrC++;
						if(nrC >= n) {
							isOk = true;
						}
					} else {
						nrC = 0;
					}
					if(isOk) {
						res += chr.length - j;
						break;
					}
				}
			}
			
			pw.println("Case #" + testNr + ": " + res);
		}
		
		br.close();
		pw.close();
	}
}
