import java.io.*;
import java.util.*;

public class Round1C_2013_A {


	private static void jam(String inFile, String outFile) throws Exception {
		BufferedReader brIn = new BufferedReader(new FileReader(inFile));
		BufferedWriter bwOut = new BufferedWriter(new FileWriter(outFile));
	
		String sLine; 
		int ca=1;
		brIn.readLine(); // skip first line
		int [] starts = new int[1000000]; //inclusive
		int [] ends = new int[1000000]; //exclusive
		while((sLine = brIn.readLine())!=null) {
			String [] fields = sLine.split(" ");
			if(fields.length !=2) { //long line parsing?
				System.out.println("skipping mis-parse: " + sLine);
				continue;
			}
			String s = fields[0];
			int n = Integer.parseInt(fields[1]);
			int numSets = 0;
			int seqNum = 0;
			for(int i=0; i<s.length(); i++) {
				char c = s.charAt(i);
				if(c != 'a' && c != 'e' &&c != 'i' &&c != 'o' &&c != 'u') {
					seqNum++;
					if(seqNum >= n) {
						starts[numSets] = i+1-n;
						ends[numSets] = i+1;
						numSets++;
					}
				}
				else {
					seqNum = 0;
				}
			}
			int lastStart = -1;
			long sum = 0;
			for(int i=0; i<numSets; i++) {
				int choicesLeft = starts[i] - lastStart;
				int choicesRight = 1 + s.length() - ends[i];
				sum += (long)choicesLeft * (long)choicesRight;
				lastStart = starts[i];
			}
			String msg = "" + sum;
			System.out.println("" + s.length());
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
	}

}
