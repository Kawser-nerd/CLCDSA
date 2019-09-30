package pl.helman.codejam.dancing;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Dancing {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\dancing.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\dancing.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {
			System.out.println();
			
			line = br.readLine();
			String[] elems = line.split(" ");

			// number of dancers
			int n = Integer.parseInt(elems[0]);

			// number od surprises
			int s = Integer.parseInt(elems[1]);

			// points
			int p = Integer.parseInt(elems[2]);

			System.out.println("  n:"+n+" p:"+p+" s:"+s);
			
			int ret = 0;

			for (int i = 0; i < n; i++) {
				int w = Integer.parseInt(elems[3 + i]);

				
				// max not surprising note
				int m = (w + 2) / 3;
				
				System.out.print("  w:"+w+" m:"+m+" m%3:"+m%3+" s:"+s);
				
				if (m >= p) {
					ret++;
					System.out.print(" +1");
				} else if (w>0 && (m == p - 1) && ((w % 3) != 1) && (s > 0)) {
					s--;
					ret++;
					System.out.print(" +2");
				}
				System.out.println();
				
			}
			
			

			System.out.println("Case #" + c + ": " + ret);
			f0.write("Case #" + c + ": " + ret + "\r\n");
		}

		fr.close();
		f0.close();

	}

}
