using System;

class WelcomeToCodejam
{
	public string getInputsAndRun()
	{
		string text = Console.ReadLine();
		return solve(text);
	}

	const int MOD = 10000;
	string pat, text;
	bool[,] vis;
	int[,] dp;
	int n;

	public string solve(string text)
	{
		pat = "welcome to code jam";
		this.text = text;
		n = text.Length;

		vis = new bool[pat.Length, n];
		dp = new int[pat.Length, n];

		return String.Format("{0:D4}", rec(0, 0));
	}

	private int rec(int ppos, int tpos)
	{
		if (ppos == pat.Length)
			return 1;
		if (tpos == n)
			return 0;
		if (vis[ppos, tpos])
			return dp[ppos, tpos];

		vis[ppos, tpos] = true;

		int res = 0;
		res = (res + rec(ppos, tpos + 1)) % MOD;
		if (pat[ppos] == text[tpos])
			res = (res + rec(ppos + 1, tpos + 1)) % MOD;

		return dp[ppos, tpos] = res;
	}
}