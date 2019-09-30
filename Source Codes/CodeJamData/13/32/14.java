import java.io.*;
import java.util.*;

public class Round1C_2013_B {

	private static void check(String inFile) throws Exception {
		BufferedReader brIn = new BufferedReader(new FileReader(inFile));
		String sLine; 
		int ca=1;
		brIn.readLine(); // skip first line
		while((sLine = brIn.readLine())!=null) {
			String [] fields = sLine.split(" ");
			System.out.print(fields[0] + " " + fields[1] + " ");
			int x =0;
			int y = 0;
			for(int i=0; i<fields[2].length(); i++) {
				char c = fields[2].charAt(i);
				if(c=='N') {
					y+=i+1;
				}
				else if(c=='S') {
					y -= i+1;
				}
				else if(c=='W') {
					x -= i+1;
				}
				else {
					x += i+1;
				}
			}
			System.out.println(x + "," + y);
		}
	}

	private static void jam(String inFile, String outFile) throws Exception {
		BufferedReader brIn = new BufferedReader(new FileReader(inFile));
		BufferedWriter bwOut = new BufferedWriter(new FileWriter(outFile));
	
		String sLine; 
		int ca=1;
		brIn.readLine(); // skip first line
		while((sLine = brIn.readLine())!=null) {
			String [] fields = sLine.split(" ");
			int xO = Integer.parseInt(fields[0]);
			int yO = Integer.parseInt(fields[1]);
			int tot = Math.abs(xO)+Math.abs(yO);
			//find number of moves:
			int start = (int)Math.floor(Math.sqrt((double)(2*tot)));
			int dist = start * (start + 1) / 2;
			int moves = start;
			while((dist - tot) % 2 != 0) {
				moves++;
				dist += moves;
			}
			//can always solve with greedy when dist - tot even (?)
			StringBuffer b = new StringBuffer();
			int curmove = moves;
			int x = xO;
			int y = yO;
			while(true) {
				while(curmove > 0) {
					if(Math.abs(x) > Math.abs(y)) {
						if(x > 0) {
							x -= curmove;
							b.append("E"); //W in reverse...
						}
						else {
							x += curmove;
							b.append("W");
						}
					}
					else {
						if(y > 0) {
							y -= curmove;
							b.append("N");
						}
						else {
							y += curmove;
							b.append("S");
						}
					}
					curmove--;
				}
				if(x != 0 || y != 0) {
					b = new StringBuffer();
					moves++;
					curmove = moves;
					x= xO;
					y = yO;
				}
				else
					break;
			}
			String msg = b.reverse().toString();
			bwOut.write("Case #" + ca + ": " + msg + "\r\n");
			ca++;
		}
		brIn.close();
		bwOut.close();	
	}
	
	/**
	 * Assumes input/output file names passed on command line
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		jam(args[0], args[1]);
		//check(args[1]);
	}

}
