package qualification.lawnmower;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class LawnMower
{
	private static void calculate( int N, int M, int[][] map, BufferedWriter bw, int n ) throws Exception
	{
		boolean possible = true;
		
		int[] xMax = new int[N];
		int[] yMax = new int[M];
		
		for ( int x = 0; x < N; x++ )
			for ( int y = 0; y < M; y++ )
			{
				if ( xMax[x] < map[x][y] )
					xMax[x] = map[x][y];
				
				if ( yMax[y] < map[x][y] )
					yMax[y] = map[x][y];
			}
		
		for ( int x = 0; x < N; x++ )
			for ( int y = 0; y < M; y++ )
				if ( map[x][y] != Math.min( xMax[x], yMax[y] ) )
					possible = false;
		
		bw.append( "Case #"+n+": " + ( possible ? "YES" : "NO" ) + "\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/qualification/lawnmower/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/lawnmower/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String[] nm = br.readLine().split( " " );
			int N = Integer.parseInt( nm[0] );
			int M = Integer.parseInt( nm[1] );
			
			int[][] map = new int[N][M];
			for ( int x = 0; x < N; x++ )
			{
				String[] squares = br.readLine().split( " " );
				for ( int y = 0; y < M; y++ )
					map[x][y] = Integer.parseInt( squares[y] );
			}
			
			calculate( N, M, map, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
