import java.io.*;
import java.net.Inet4Address;
import java.util.*;


public class B
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.in"))));
		PrintWriter writer = new PrintWriter(new File("output.out"));


		int tc = Integer.parseInt(reader.readLine());

		for(int time = 1 ; time <= tc ; time++)
		{
			StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
			int k = Integer.parseInt(tokenizer.nextToken());
			int l = Integer.parseInt(tokenizer.nextToken());
			int s = Integer.parseInt(tokenizer.nextToken());

			String keypad = reader.readLine().toLowerCase();
			String target = reader.readLine().toLowerCase();

			double [] prob = new double[26];
			for(char c : keypad.toCharArray())
				prob[c-'a']++;
			for(int i = 0 ; i < 26 ; i++)
				prob[i] /= keypad.length();

			boolean haha = false;
			for(char c : target.toCharArray())
			{
				if(prob[c-'a'] < 1e-6)
					haha = true;
			}

			if(haha)
			{
				writer.println("Case #"+(time)+": 0.0");
				writer.flush();
				continue;
			}

			int [][] next = new int[l+1][26];
			for(int till = 0 ; till <= l ; till++)
				for(int a = 0 ; a < 26 ; a++)
				{
					String now = target.substring(0, till) + (char)('a'+a);

					for(int i = now.length() > l ? 1 : 0 ; i < now.length() ; i++)
						if(now.substring(i).equals(target.substring(0, now.length()-i)))
						{
							next[till][a] = now.length()-i;
							break;
						}
				}

			int max = 0;
			String curr = "";
			for(int v = 0 ; v < s ; v++)
			{
				int go = -1;
				for(int i = 0 ; i < 26 ; i++)
					if(keypad.contains(""+((char)(i+'a'))))
						if(go == -1 || next[curr.length()][i] > next[curr.length()][go])
							go = i;

				curr += (char)(go+'a');
				if(curr.length() == target.length())
				{
					max++;
					boolean found = false;
					for(int i = 1 ; i < curr.length() ; i++)
						if(curr.substring(i).equals(target.substring(0, curr.length()-i)))
						{
							curr = curr.substring(i);
							found = true;
							break;
						}
					if(!found)
						curr = "";
				}

			}

			int len = s+1;
			double [][][] dp = new double[s+1][l+1][len];
			;
			dp[0][0][0] = 1;

			for(int till = 0 ; till < s ; till++)
				for(int build = 0 ; build <= l ; build++)
					for(int cnt = 0 ; cnt < len ; cnt++)
						if(dp[till][build][cnt] > 0)
							for(int i = 0 ; i < 26 ; i++)
							{
								double p = prob[i];
								if(p < 1e-6)
									continue;

								int ncnt = cnt;
								if(next[build][i] == l)
									ncnt++;

								dp[till+1][next[build][i]][ncnt] += p*dp[till][build][cnt];
							}

			double res = 0;
			for(int i = 0 ; i <= l ; i++)
				for(int j = 0 ; j < len ; j++)
					res += dp[s][i][j]*j;

			writer.println("Case #"+(time)+": "+(max-res));
			writer.flush();
		}

		writer.flush();
		writer.close();
	}
}