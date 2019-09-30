import java.io.*;
import java.util.*;

public class vect{
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("vect.in"));

		String in = fin.readLine();

		int T = Integer.parseInt(in);
		
		for(int casenum=1; casenum<=T; casenum++){
			in = fin.readLine();
			int n = Integer.parseInt(in);

			in = fin.readLine();
			String[] sp = in.split(" ");
			long[] vect1 = new long[n];
			for(int c1=0; c1<n; c1++){
				vect1[c1] = Long.parseLong(sp[c1]);
			}

			in = fin.readLine();
			sp = in.split(" ");
			long[] vect2 = new long[n];
			for(int c1=0; c1<n; c1++){
				vect2[c1] = Long.parseLong(sp[c1]);
			}

			Arrays.sort(vect1);
			Arrays.sort(vect2);

			long res = 0;
			for(int c1=0; c1<n; c1++){
				res += vect1[c1] * vect2[n-c1-1];
			}

			System.out.println("Case #" + casenum + ": " + res);
		}
	}
}