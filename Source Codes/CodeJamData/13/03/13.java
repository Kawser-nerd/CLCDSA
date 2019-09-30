package qualification.fairandsquare;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.TreeSet;

public class FairAndSquare
{
	private static TreeSet<BigInteger> FAIR_AND_SQUARE_NUMBERS = new TreeSet<BigInteger>();
	
	private static void initCache() {
		initCache( "", 0 );
	}
	
	private static void initCache( String numPart, int sqSumSoFar )
	{
		String traPmun = new StringBuffer( numPart ).reverse().toString();
		if ( !"".equals( numPart ) )
		{
			BigInteger bi = new BigInteger( numPart + traPmun );
			FAIR_AND_SQUARE_NUMBERS.add( bi.pow( 2 ) );
		}
		if ( numPart.length() < 25 )
		{
			for ( int d = 0; sqSumSoFar + d*d < 10; d++  )
			{
				BigInteger bi = new BigInteger( numPart + d + traPmun );
				FAIR_AND_SQUARE_NUMBERS.add( bi.pow( 2 ) );
			}
			
			for ( int d = 0; sqSumSoFar + 2*d*d < 10; d++ )
			{
				if ( d > 0 || numPart.length() > 0 ) 
					initCache( numPart + d, sqSumSoFar + d*d*2 );
			}
		}
	}
	
	private static void calculate( BigInteger A, BigInteger B, BufferedWriter bw, int n ) throws Exception
	{
		int num = 0;
		for ( BigInteger bi : FAIR_AND_SQUARE_NUMBERS )
		{
			if ( ( bi.compareTo( A ) >= 0 ) && ( bi.compareTo( B ) <= 0 ) )
				num++;
			if ( bi.compareTo( B ) > 0 )
				break;
		}

		bw.append( "Case #"+n+": " + num + "\n" );
		bw.flush();
	}
	
	public static void main( String[] args ) throws Exception
	{
		initCache();
		
		File inputFile = new File( "inputfiles/qualification/fairandsquare/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/fairandsquare/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String[] ab = br.readLine().split( " " );
			BigInteger A = new BigInteger( ab[0] );
			BigInteger B = new BigInteger( ab[1] );
			
			calculate( A, B, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
