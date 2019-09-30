import java.util.*;

public class A
{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);

		int tc = in.nextInt();

		for(int t = 1 ; t <= tc ; t++)
		{
			int n = in.nextInt();

			String [] strings = new String[n];

			for(int id = 0 ; id < n ; id++)
				strings[id] = in.next();

			String [] seq = new String[n];
			for(int i = 0 ; i < n ; i++)
			{
				String build = "";
				char last = 'A';

				for(int k = 0 ; k < strings[i].length() ; k++)
					if(strings[i].charAt(k) != last)
					{
						build += strings[i].charAt(k);
						last = strings[i].charAt(k);
					}
				seq[i] = build;
			}

			boolean can = true;
			for(int i = 1 ; i < n ; i++)
				if(!seq[i].equals(seq[0]))
					can = false;

			if(!can)
			{
				System.out.println("Case #" + t + ": Fegla Won");
				continue;
			}

			for(int i = 0 ; i < n ; i++)
				strings[i] += '*';

			int res = 0;

			String sequence = seq[0]+'*';
			for(int i = 0 ; i + 1 < sequence.length() ; i++)
			{
				ArrayList<Integer> cnt = new ArrayList<Integer>();
				for(int k = 0 ; k < n ; k++)
				{
					cnt.add(strings[k].indexOf(sequence.charAt(i+1)));
					strings[k] = strings[k].substring(strings[k].indexOf(sequence.charAt(i+1)));
				}
				Collections.sort(cnt);

				for(int k = 0 ; k < cnt.size() ; k++)
					res += Math.abs(cnt.get(k) - cnt.get(cnt.size()/2));
			}

			System.out.println("Case #"+t+": "+res);

		}
	}
}
