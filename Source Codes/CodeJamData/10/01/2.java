import java.io.*;
import java.util.*;


public class Snapper {


	public static void main(String args[]) throws Exception {
		//String inFile = args[0];
		//String inFile = "A-small-attempt0.in";
		String inFile = "A-large.in";
		String outFile = inFile + ".out";
		LineNumberReader lin = new LineNumberReader(new InputStreamReader(new FileInputStream(inFile)));
		PrintWriter out = new PrintWriter(new File(outFile));
		int NCASE = Integer.parseInt(lin.readLine());
		for(int CASE = 1; CASE <= NCASE; CASE++) {
			out.print("Case #" + CASE + ": ");
			String l = lin.readLine();
			int i = l.indexOf(' ');
			int N = Integer.parseInt(l.substring(0, i).trim());
			int K = Integer.parseInt(l.substring(i + 1).trim());
			int n = (1 << N) - 1;
			out.println(
				(K & n) == n ? "ON" : "OFF"
			);
		}
		lin.close();
		out.close();
	}
}