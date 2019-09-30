using System;

class ARC026B
{
	static public void Main(string[] args)
	{
		long N = long.Parse(Console.ReadLine());
		long sum = 1;
		if(N == 1)
		{
			sum = 0;
		}

		long i = 2;
		while(i * i <= N)
		{
			if(N % i == 0)
			{
				//Console.WriteLine(i);
				sum += i;
				long j = N / i;
				//Console.WriteLine(j);
				if(j != i)
					sum += j;
			}
			i++;
		}

		if(sum < N)
		{
			Console.WriteLine("Deficient");
		}
		else if(sum > N)
		{
			Console.WriteLine("Abundant");
		}
		else
		{
			Console.WriteLine("Perfect");
		}
	}
}