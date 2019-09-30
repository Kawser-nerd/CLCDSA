package j2012qualifier;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	public static String inputDirectory="src/j2012qualifier/";
	public static String inputFile="A.in";
	public static String outputFile="A.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));

		Map<Character, Character> codeMap = new HashMap<Character, Character>();

		String source = "qzejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String result = "zqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

		for (int i = 0; i < source.length(); i++) {
			codeMap.put(source.charAt(i), result.charAt(i));
		}
		
		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			String code = s.nextLine();
			char[] uncoded = new char[code.length()];
			for(int i=0; i< uncoded.length; i++) {
				uncoded[i] = codeMap.get(code.charAt(i));
			}
			String answer = String.valueOf(uncoded);

			out("Case #"+Case+": " + answer);
		}
		output.flush();
	}
	
	public static void out(String s){
		output.println(s);
		//System.out.println(s);
	}
}
