import java.io.*;
import java.math.*;
import java.util.*;

public class ReorderingTrainCars
{
	static Scanner sc = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);
	public static void main(String[] args)
	{
		for(int caseId=1,totalCases=sc.nextInt();caseId<=totalCases;caseId++)
		{
			out.println("Case #"+caseId+": "+solve());
			//Add logic here
			out.flush();
		}
	}
	
	static int solve() {
		int[] prefix = new int[26], suffix = new int[26];
		Arrays.fill(prefix, -1); Arrays.fill(suffix, -1);
		int[] enclosed = new int[26], filled = new int[26];
		Arrays.fill(enclosed, -1);
		
		int n = sc.nextInt();
		String[] cars = new String[n];
		boolean ok = true;
		for(int i=0;i<n;i++) {
			cars[i] = sc.next();
			for(char ch='a';ch <= 'z'; ch++)
				cars[i] = cars[i].replaceAll("" + ch + "+", "" +ch);
			if(cars[i].length()==1)
				filled[cars[i].charAt(0)-'a']++;
			else {
				int len = cars[i].length();
				if(cars[i].charAt(0) == cars[i].charAt(len-1))
					ok = false;
				else {
					ok &= update(suffix, cars[i].charAt(0), i);
					ok &= update(prefix, cars[i].charAt(len-1), i);
					for(int j=1;j+1<len;j++) {
						if(cars[i].charAt(j) != cars[i].charAt(j-1) &&
							cars[i].charAt(j) != cars[i].charAt(j+1))
						ok &= update(enclosed, cars[i].charAt(j), i);
					}
				}
			}
		}
		if (!ok)
			return 0;
		
		
		int[] fact = new int[n+1];
		fact[0] = 1;
		for(int i=1;i<=n;i++)
			fact[i] = (int)((long)fact[i-1] * i % MOD);
		
		boolean[] chosen = new boolean[26];
		boolean[] used = new boolean[n];
		int total = 1, chains = 0;
		while(true) {
			int index = -1;
			for(int i=0;i<26;i++) {
				if(!chosen[i] && prefix[i] == -1 && (filled[i]>0 || suffix[i] != -1)) {
					index = i;
					break;
				}
			}
			if(index==-1)
				break;
			int ways = 1;
			while(true) {
				// System.err.println("Choosing " + (char)(index+'a'));
				chosen[index] = true;
				ways = (int)((long)ways * fact[filled[index]] % MOD);
				for(int i=0;i<n;i++)
					if(cars[i].equals(""+(char)('a'+index)))
						used[i] = true;
				if(suffix[index]==-1)
					break;

				String next = cars[suffix[index]];
				used[suffix[index]] = true;
				for(char ch: cars[suffix[index]].toCharArray())
					chosen[ch-'a'] = true;
				
				index = next.charAt(next.length()-1) - 'a';
			}
			chains++;
			total = (int)((long)total * ways % MOD);
		}
		for(boolean usageValue: used)
			if(!usageValue)
				return 0;

		return (int)((long)total * fact[chains] % MOD);
	}

	static final int MOD = 1000000007;
	
	static boolean update(int[] array, int ch, int index) {
		ch -= 'a';
		if(array[ch]==-1) {
			array[ch] = index;
			return true;
		}
		return false;
	}
}
