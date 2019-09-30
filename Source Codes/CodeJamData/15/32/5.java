package c_2015;

import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int kases = in.nextInt();
		
		for(int kas = 1; kas<=kases; kas++)
		{
			int K = in.nextInt();
			int L = in.nextInt();
			int S = in.nextInt();
			
			String keyboard = in.next();
			String target = in.next();
			
			int [] keys = new int[26];
			
			for (int i = 0; i<K; i++)
				keys[keyboard.charAt(i) - 'A']++;
			
			boolean possible = true;
			for (int i = 0; i<L; i++)
				if (keys[target.charAt(i) - 'A'] == 0)
					possible = false;
			
			if (!possible)
			{
				System.out.println("Case #"+ kas + ": 0.0");
				continue;
			}
			int [] EV = new int[S];
			
			int p;
			outer: for (p = L-1; p > 0; p--)
			{
				for (int i = 0; i<p; i++)
				{
					if (target.charAt(i) != target.charAt(L - p + i))
						continue outer;
				}
				break;
			}
			
			int max = (S - p)/(L - p);
			
			double prob_word = 1;
			
			for (int i = 0; i<L; i++)
			{
				prob_word *= keys[target.charAt(i) - 'A']/(0.0+K);
			}
			
			System.out.println("Case #"+ kas + ": " + (max - prob_word * (S - L + 1)));
		}
	}

}
