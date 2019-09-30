package facebook;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class Qual {

	private static BufferedReader br = null;
	private static int readInt() {
		try {
			return Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
	private static double readDouble() {
		try {
			return Double.parseDouble(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
	private static long[] readIntArr() {
		long[] ret = null;
		String[] tmp;
		try {
			String str = br.readLine();
			tmp = str.split(" ");
			ret = new long[tmp.length];
			for (int i = 0; i < tmp.length; i++)
				ret[i] = Long.parseLong(tmp[i]);//Integer.parseInt(tmp[i]);
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	
	
	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner(System.in);
		br = new BufferedReader(new FileReader(new File("input.txt")));
		System.setOut(new PrintStream(new File("output.txt")));
		int T = readInt();
		
		for (int ind = 1; ind<=T; ind++) {
			System.out.print("Case #" + ind + ": ");
			long sen[];
			sen = readIntArr();
			long B = sen[0];
			long M = sen[1];
			
			boolean pos = false;
			long count = 1;
			if (M == 1L) {
				pos = true;
			}
			for (long i = 2; i < B; i++) {
				count *= 2L;
				if (count >= M) {
					pos = true;
					break;
				}
				
			}
			System.out.println(pos ? "POSSIBLE" : "IMPOSSIBLE");
			int b = (int) B;
			long max = 1 << (b - 2);
			if (pos) {
				String ans[] = new String[b];
				
				for (int i = 0; i < b; i++) {
					
					String tmp = "";
					for (int j = 0; j < b; j++) {
						if (j <= i) tmp += "0";
						else tmp += "1";
					}
					
					ans[i] = tmp;
					
				}
				
				
				String x = Long.toBinaryString(M - 1L);
				if (x.length() > b - 2) x ="";
				while (x.length() < b - 2) x = "0" + x;
				
				ans[0] = "0" + x + "1";
				
				for (int i = 0; i < b; i++)
					System.out.println(ans[i]);
			}
			
			
			
		}
		

	}

}
