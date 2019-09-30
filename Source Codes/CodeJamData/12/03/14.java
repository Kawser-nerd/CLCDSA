package j2012qualifier;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static String inputDirectory="src/j2012qualifier/";
	public static String inputFile="C.in";
	public static String outputFile="C.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		for(int Case=1;Case<=cases;Case++){
			s.nextLine();
			int A = s.nextInt();
			int B = s.nextInt();
			
			long result = 0;
			for(int n = A; n< B; n++) {
				result+= count(n, B);
			}

			out("Case #"+Case+": "+result);
		}
		output.flush();
	}
	
	public static long count(long n, long max) {
		//out("testing " + n);
		long digit = 10;
		long pow10 = 10 * (long)Math.pow(10, Math.floor(Math.log10(n)));
		long count = 0;
		Set<Long> found = new HashSet<Long>();
		//out("pow" + pow10);
		while(digit <= n) {
			long m = n/digit + (n%digit) * pow10 / digit;
			//out("choice 1 " + m);
			digit *= 10;
			if (m > n && m <= max && !found.contains(m)) {
				//out(n + " , " + m);
				count++;
				found.add(m);
			}
		}
		return count;
	}
	
	public static void out(String s){
		output.println(s);
		//System.out.println(s);
	}
}
