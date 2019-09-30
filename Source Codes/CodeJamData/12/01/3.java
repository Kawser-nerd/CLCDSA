
import java.io.*;
import java.util.*;

public class CodeJam2012_Q_A {

	String map;
	public boolean init() {
		map = "**************************";
		String[] sampleIn  = {"y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
		String[] sampleOut = {"a zoo", "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
		
		for(int i=0; i<sampleIn.length; i++) {
			for(int j=0; j<sampleIn[i].length(); j++) {
				char in = sampleIn[i].charAt(j);
				if(in != ' ') {
					if(map.charAt(in-'a')=='*') {
						map = map.substring(0, in-'a') + sampleOut[i].charAt(j) + map.substring(in-'a'+1);
					} else {
						if(map.charAt(in-'a')!=sampleOut[i].charAt(j)) return false;
					}
				}
			}
		}
		
		int ast = map.indexOf('*');
		if(ast<0) {
			return true;
		} else {
			if(map.substring(ast+1).indexOf('*')>=0) {
				return false;
			} else {
				for(char c='a'; c<='z'; c++) {
					if(map.indexOf(c)<0) {
						map = map.substring(0, ast) + c + map.substring(ast+1);
						break;
					}
				}
				return true;
			}
		}
	}
	
	public String calc(String input) {
		String output = "";
		for(int i=0; i<input.length(); i++) {
			if(input.charAt(i) == ' ') output += ' ';
			else output += map.charAt(input.charAt(i)-'a');
		}
		
		return output;
	}
	
	public static void main(String[] args) {
		try{
			(new CodeJam2012_Q_A()).exec("2012_Q_A-small.in", "2012_Q_A-small.out");
			}catch(Exception ex) {
				
			}
	}

	public final void exec(String inFileName, String outFileName) throws Exception{
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));
		int caseNums=0;
		caseNums = Integer.parseInt(inReader.readLine());
		
		init();
		for(int i=0; i<caseNums; i++) {
			String input = inReader.readLine();
		
			String outStr = calc(input);

			String fmtOutStr="Case #" + (i+1) + ": " + outStr;	
			outWriter.println(fmtOutStr);
			System.out.println(fmtOutStr);
		}

		outWriter.close();
		inReader.close();
	}
}
