import java.io.*;
import java.util.*;

public class Snaps {
	
	static Scanner in;
	static PrintWriter out;
	
	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		int T = in.nextInt();
		for (int cas=1; cas<=T; cas++) {
			int n = in.nextInt();
			int k = in.nextInt();
			boolean ok = true;
			for (int i=0; i<n; i++) {
				if ((1 << i & k) == 0) {
					ok = false;	
				} 
			}
			out.printf("Case #%d: %s%n", cas, ok ? "ON" : "OFF");
		}

		out.close();	
	}
}