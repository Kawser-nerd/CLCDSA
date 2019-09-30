import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int test = 1; test <= t; ++test)
		{
			int k = in.nextInt();
			int l = in.nextInt();
			int s = in.nextInt();
			String keyboard = in.next();
			String target = in.next();
			System.out.printf("Case #%d: %.10f\n", test, solve(keyboard, target, s));
		}
	}
	
	public static double solve(String keyboard, String target, int s)
	{
		// dp[i][j] = probability we match the first i characters of 'target' by character 'j' of monkey typing
		double[][] dp = new double[target.length()+1][s+1];
		dp[0][0] = 1.0;
		// precalc[len][i] = if we match first len chars of target and then type keyboard[i], how many chars of target do we match now
		int[][] precalc = new int[target.length()+1][keyboard.length()];
		int maxSave = 0;
		for (int curMatchLen = 0; curMatchLen <= target.length(); ++curMatchLen)
		{
			for (int keyboardIdx = 0; keyboardIdx < keyboard.length(); ++keyboardIdx)
			{
				String word = target.substring(0, curMatchLen);
				word += keyboard.charAt(keyboardIdx);
				for (int resultLen = word.length(); resultLen >= 0; --resultLen)
				{
					if (target.startsWith(word.substring(word.length() - resultLen, word.length())))
					{
						precalc[curMatchLen][keyboardIdx] = resultLen;
						if (curMatchLen == target.length())
							maxSave = Math.max(maxSave, resultLen);
						break;
					}
				}
			}
		}
		
		int extraToType = target.length() - maxSave + 1;
		int maxBanana = 1 + (s - target.length()) / extraToType;
		if (extraToType > target.length())
			maxBanana = 0;
		//System.out.printf("max banana = %d\n", maxBanana);
		
		double multiplier = 1.0 / keyboard.length();
		
		for (int curChar = 1; curChar <= s; ++curChar)
		{
			for (int curMatchLen = 0; curMatchLen <= target.length(); ++curMatchLen)
			{
				for (int keyboardIdx = 0; keyboardIdx < keyboard.length(); ++keyboardIdx)
				{
					dp[precalc[curMatchLen][keyboardIdx]][curChar] += dp[curMatchLen][curChar-1] * multiplier;
				}
			}
		}
		
		double totalBanana = maxBanana;
		for (int charsTyped = 1; charsTyped <= s; ++charsTyped)
		{
			//System.out.printf("dp[%d][%d] = %.6f\n", target.length(), charsTyped, dp[target.length()][charsTyped]);
			totalBanana -= dp[target.length()][charsTyped];
		}
		
		return totalBanana;
	}
}