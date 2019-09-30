package r1b2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int[] cnt = new int[256];
			char[] s = in.next().toCharArray();
			for (char c : s) {
				cnt[c]++;
			}
			
			int[] ans = new int[10];
			for (int i = 0; i < 10; i++) {
				while (cnt[oo[i]] > 0) {
					ans[dd[i]]++;
					for (int j = 0; j < ss[i].length(); j++) {
						cnt[ss[i].charAt(j)]--;
					}
				}
			}
			
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < ans[i]; j++) {
					out.print(i);
				}
			}
			out.println();
		}

		out.flush();
	}
	
	static char[] oo = {'X', 'G', 'U', 'W', 'Z', 'F', 'V', 'R', 'I', 'O'};
	static String[] ss = {"SIX", "EIGHT", "FOUR", "TWO", "ZERO", "FIVE", "SEVEN", "THREE", "NINE", "ONE"};
	static int[] dd = {6, 8, 4, 2, 0, 5, 7, 3, 9, 1};
}
