import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> primes = getPrimes(n);
		int[][] powerIndexes;
		int[] nFactorialPowerIndexes = new int[primes.size()];
		int cnt = 0;
		int[][] pattern = {
			{ 3, 3, 5, 5 },
			{ 3, 5, 3, 5 },
			{ 3, 5, 5, 3 },
			{ 2, 3, 25, 0 },
			{ 2, 25, 3, 0 },
			{ 2, 5, 15, 0 },
			{ 2, 15, 5, 0 },
			{ 1, 75, 0, 0 }
		};

		powerIndexes = new int[n + 1][];
		for(int i = 1; i <= n; ++i)
		{
			powerIndexes[i] = factor(primes, i);
		}

		//System.out.print(n + "! = ");
		for(int i = 0; i < primes.size(); ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				nFactorialPowerIndexes[i] += powerIndexes[j][i];
			}

			/*
			if(nFactorialPowerIndexes[i] != 0)
			{
				System.out.print(primes.get(i) + "^" + nFactorialPowerIndexes[i] + " * ");
			}
			*/
		}
		//System.out.println();

		for(int i = 0; i < pattern.length; ++i)
		{
			cnt += countSevenFiveThree(nFactorialPowerIndexes, pattern[i], 0, pattern[i][0]);
		}

		System.out.println(cnt);
	}

	private static int countSevenFiveThree(int[] powerIndexes, int[] pattern, int primeIdx, int patternIdx)
	{
		if(patternIdx == 0)
		{
			return 1;
		}

		if(primeIdx == powerIndexes.length)
		{
			return 0;
		}
		
		int ret = countSevenFiveThree(powerIndexes, pattern, primeIdx + 1, patternIdx);

		if(powerIndexes[primeIdx] >= pattern[patternIdx] - 1)
		{
			ret += countSevenFiveThree(powerIndexes, pattern, primeIdx + 1, patternIdx - 1);
		}

		return ret;
	}

	private static ArrayList<Integer> getPrimes(int n)
	{
		boolean[] isNotPrime = new boolean[n + 1];
		ArrayList<Integer> primeList = new ArrayList<>();

		for(int i = 2; i * i <= n; ++i)
		{
			if(!isNotPrime[i])
			{
				for(int j = i * 2; j <= n; j += i)
				{
					isNotPrime[j] = true;
				}
			}
		}

		for(int i = 2; i <= n; ++i)
		{
			if(!isNotPrime[i])
			{
				primeList.add(i);
			}
		}

		return primeList;
	}

	private static int[] factor(ArrayList<Integer> primes, int n)
	{
		int[] powerIndexes = new int[primes.size()];

		for(int i = 0; i < primes.size(); ++i)
		{
			int power = 0;
			while(n % primes.get(i) == 0)
			{
				n /= primes.get(i);
				++power;
			}
			powerIndexes[i] = power;
		}
		
		return powerIndexes;
	}
}