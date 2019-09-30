import java.io.*;
import java.util.*;

import static java.lang.Math.*;
public class SnapperChain {
	public static void main(String[] args)throws IOException {
		// Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    StringTokenizer st = new StringTokenizer(f.readLine());
							  // Get line, break into tokens
	    int t = Integer.parseInt(st.nextToken());    // first integer
	    for (int i = 0; i < t; i++) {
			st=new StringTokenizer(f.readLine());
			long n=Long.parseLong(st.nextToken());
			long k=Long.parseLong(st.nextToken());
			boolean on=true;
			for (int j = 0; j < n; j++) {
				long mask=1<<j;
				mask&=k;
				if(mask==0)on=false;
			}
			
			String s=on?"ON":"OFF";
			out.println("Case #"+(i+1)+": "+s);
		}                       
	    out.close();                                  // close the output file
	    System.exit(0);                               // don't omit this!
	}
}
