package pl.helman.codejam.recycled;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

//Brute force attempt
public class Recycled {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\recycled.in");
		BufferedReader br = new BufferedReader(fr);
		String s = br.readLine();

		FileWriter f0 = new FileWriter("d:\\recycled.out");

		int t = Integer.parseInt(s.trim());

		for (int i = 1; i <= t; i++) {
			s = br.readLine();
			String[] elems = s.split(" ");
			int a = Integer.parseInt(elems[0]);
			int b = Integer.parseInt(elems[1]);

			int digs = 1;
			int mod = 1;

			int ret = 0;

			while (a >= mod * 10) {
				digs++;
				mod *= 10;
			}

			for (int n = a; n <= b; n++) {
//				System.out.println("  n:"+n);
				int m = n;
				m = (m % mod) * 10 + (m / mod);
				while (m != n) {
				
//					System.out.print("    m:" + m);
					if (m > n && m <= b) {
						ret++;
//						System.out.print(" +");
					}
//					System.out.println();
					
					m = (m % mod) * 10 + (m / mod);
				}

			}

			System.out.println("Case #" + i + ": " + ret);
//			System.out.println();

			f0.write("Case #" + i + ": " + ret + "\r\n");
		}

		fr.close();
		f0.close();

	}

}
