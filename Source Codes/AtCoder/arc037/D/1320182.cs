using System;
    class P
    {
    	static long M = 1000000007;
    	static void Main()
    	{
    		var L = int.Parse(Console.ReadLine());
    		var x = new Tuple<long, long, long>(2, 1, 1);
    		for (var i = 0; i < L; i++) x = F(x);
    		Console.WriteLine(x.Item3);
    	}
    	static Tuple<long, long, long> F(Tuple<long, long, long> x)
    	{
    		var a = x.Item1;
    		var b = x.Item2;
    		var c = x.Item3;
    		var p = ((a + b) * (a - b)) % M;
    		if (p < 0) p += M;
    		return new Tuple<long, long, long>((a * (a + p)) % M, (b * p) % M, ((((a * a) % M) * a) % M + 3 * c) % M);
    	}
    }