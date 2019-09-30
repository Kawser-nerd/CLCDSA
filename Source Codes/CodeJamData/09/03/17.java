import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C {
	static char[] wel, text;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("testin"));
		FileWriter fw = new FileWriter("testout");
		wel = "welcome to code jam".toCharArray();
		int N = new Integer(in.readLine());
		
		for (int cases = 1; cases <= N; cases++) {
			text = in.readLine().toCharArray();
//			System.out.println(pad(f(0,0)));
			dp = new int[wel.length +1][text.length +1];
			for (int i = 0; i < dp.length; i++) {
				for (int j = 0; j < dp[0].length; j++) {
					dp[i][j] = -1;
				}
			}
			fw.write("Case #" + cases + ": " + pad(f(0,0)%10000) + "\n");
		}
		fw.flush();
		fw.close();
	}
	static String pad(int n)
	{
		String s = "" + n;
		if(s.length() == 1)
			return "000"+n;
		if(s.length() == 2)
			return "00"+n;
		if(s.length() == 3)
			return "0"+n;
		return s;
	}
	static int[][] dp;
	static int f(int i, int j)
	{
		
		if(i == wel.length)
			return 1;
		if(j == text.length)
			return 0;
		if(dp[i][j] != -1)
			return dp[i][j];
		int r = f(i, j+1) % 10000;
		if(text[j] == wel[i])
			r += (f(i+1, j+1) % 10000);
		return dp[i][j] = r;
	}
}

