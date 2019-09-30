using System;


public class D{
	
	public static void Main(){
	
		string[] args;
		
		args = Console.ReadLine().Split(' ');
		int N = Int32.Parse( args[0] );
		int M = Int32.Parse( args[1] );
		int Q = Int32.Parse( args[2] );
		
		int[,] train = new int[N+1, N+1];
		int[,] csum = new int[N+1, N+1];
		for( int i = 0; i <= N; i++ ){
			for( int j = 0; j <= N; j++ ){
				train[i,j] = 0;
				csum[i,j] = 0;
			}
		}
		
		for( int i = 0; i < M; i++ ){
			args = Console.ReadLine().Split(' ');
			int L = Int32.Parse( args[0] );
			int R = Int32.Parse( args[1] );
			train[L,R]++;
		}
				
		for( int i = 1; i <= N; i++ ){
			for( int j = 1; j <= N; j++ ){
				csum[i,j] = csum[i,j-1] + train[i,j];
			}
		}
		for( int i = 1; i <= N; i++ ){
			for( int j = 1; j <= N; j++ ){
				csum[i,j] += csum[i-1,j];
			}
		}
		
		int[] result = new int[Q];
		for( int i = 0; i < Q; i++ ){
			args = Console.ReadLine().Split(' ');
			int p = Int32.Parse( args[0] );
			int q = Int32.Parse( args[1] );
			result[i] = csum[q,q] + csum[p-1,p-1] - csum[p-1,q] - csum[q,p-1];
		}
		
		for( int i = 0; i < Q; i++ ){
			Console.WriteLine(result[i]);
		}
		
	}

}