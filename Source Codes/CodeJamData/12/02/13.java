package j2012qualifier;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {
	public static String inputDirectory="src/j2012qualifier/";
	public static String inputFile="B.in";
	public static String outputFile="B.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		for(int Case=1;Case<=cases;Case++){
			s.nextLine();
			int googlers = s.nextInt();
			int maxSupriseScores = s.nextInt();
			int targetScore = s.nextInt();
			int normalScores = 0;
			int surpriseScores = 0;
			for(int i=0;i< googlers; i++) {
				int score = s.nextInt();
				if (targetScore > score) {
					continue;
				}
				int otherScore = (score - targetScore) / 2;
				if (otherScore >= targetScore - 1) {
					normalScores++;
				} else if(otherScore >= targetScore - 2) {
					surpriseScores++;
				}
			}
			int answer = normalScores + Math.min(surpriseScores, maxSupriseScores);
			out("Case #"+Case+": "+answer);
		}
		output.flush();
	}
	
	public static void out(String s){
		output.println(s);
		//System.out.println(s);
	}
}