import java.util.*;

public class B
{
	static int n, m;
	static String[] d, l;

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for(int ca=0;ca < T;ca++)
		{
			n = scan.nextInt();
			m = scan.nextInt();

			d = new String[n];
			for(int i=0;i < n;i++)
				d[i] = scan.next();

			l = new String[m];
			for(int i=0;i < m;i++)
				l[i] = scan.next();


			System.out.print("Case #" + (ca+1) + ":");

			for(int i=0;i < m;i++) //each list...
			{
				int besti = -999999;
				String bests = null;



				for(int j=0;j < n;j++) //each word
				{
					int idx = 0; //What word to consider
					char[] guess = new char[d[j].length()];
					int correct = 0; //letters got
					int points = 0; //points gained

					for(int k=0;k < 26;k++)
					{
						//Try the kth letter
						char c = l[i].charAt(k);
						idx = 0; //TODO: BAD HACK
						while(idx < n && !good(guess, idx, i, k))
							idx++;

						if(idx == n)
							continue;

						//Guess it!
						boolean good = false;

						for(int ii=0;ii < d[j].length();ii++)
						{
							if(d[j].charAt(ii) == c)
							{
								good = true;
								guess[ii] = c;
								correct++;
							}
						}

						if(!good)
							points++;

						if(correct == d[j].length())
							break;
					}

					//System.out.println(l[i] + " " + d[j] + " " + points);

					if(points > besti)
					{
						besti = points;
						bests = d[j];
					}
				}

				System.out.print(" " + bests);
			}

			System.out.println();
		}
	}


	public static boolean good(char[] guess, int idx, int lidx, int cidx)
	{
		char c = l[lidx].charAt(cidx);

		//System.out.println(str(guess) + " " + d[idx] + " " + c);
		if(d[idx].length() != guess.length)
			return false;

		//Does char c exit in the word?
		if(d[idx].indexOf(c) == -1)
			return false;

		//Does guess mesh with the word?
		for(int i=0;i < guess.length;i++)
		{
			if(guess[i] != 0 && guess[i] != d[idx].charAt(i))
				return false;
		}

		//Does the word contain letters that have been skipped?
		for(int i=0;i < d[idx].length();i++)
			if(guess[i] == 0 && l[lidx].indexOf(d[idx].charAt(i)) < cidx)
				return false;
		
		//System.out.println(true);
		return true;
	}


	public static String str(char[] a)
	{
		String rtn = "";
		for(int i=0;i < a.length;i++)
			rtn += a[i];
		return rtn;
	}
}