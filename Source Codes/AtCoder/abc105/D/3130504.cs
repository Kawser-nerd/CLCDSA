using System;
using System.Collections.Generic;
using System.Linq;


public class D{
	
	public static void Main(){
	
		string[] args;
		
		args = Console.ReadLine().Split(' ');
		long n = Int64.Parse( args[0] );
		long m = Int64.Parse( args[1] );
		
		args = Console.ReadLine().Split(' ');
		long[] a = new long[n+1L];
		for( long i = 1L; i <= n; i++ ){
			a[i] = Int64.Parse( args[i-1L] );
		}
		
		long[] b = new long[n+1L];
		b[0L] = 0L;
		for( long i = 1L; i <= n; i++ ){
			b[i] = b[i-1L] + a[i];
		}		
		
		Dictionary<long,long> dic = new Dictionary<long,long>();
		for( long i = 0L; i <= n; i++ ){
			long x = b[i] % m;
			if( dic.ContainsKey(x) ){
				dic[x]++;
			}else{
				dic[x] = 1L;
			}
		}
		
		long result = 0L;
		foreach( long key in dic.Keys ){
			result += (dic[key] * (dic[key]-1L)) / 2L;			
		}
		Console.WriteLine(result);
		
	}

}