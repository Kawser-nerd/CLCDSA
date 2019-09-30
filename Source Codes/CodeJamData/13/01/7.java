package qualification.tictactoetomek;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class TicTacToeTomek
{
	private static void calculate( String testCase[], BufferedWriter bw, int n ) throws Exception
	{
		boolean xWon = false;
		boolean oWon = false;
		boolean finished = true;
		
		boolean[][] xPos = new boolean[4][4];
		boolean[][] oPos = new boolean[4][4];

		for ( int i = 0; i < 4; i++ )
		{
			String row = testCase[i];
			if ( row.contains( "." ) )
				finished = false;
			
			for ( int j = 0; j < 4; j++ )
			{
				switch ( row.charAt( j ) )
				{
					case 'X' :
						xPos[i][j] = true;
						break;
					case 'O' :
						oPos[i][j] = true;
						break;
					case 'T' :
						xPos[i][j] = true;
						oPos[i][j] = true;
						break;
				}
			}
		}
		
		for ( int i = 0; i < 4; i++ )
		{
			if ( xPos[i][0] && xPos[i][1] && xPos[i][2] && xPos[i][3] )
				xWon = true;
			if ( xPos[0][i] && xPos[1][i] && xPos[2][i] && xPos[3][i] )
				xWon = true;
			
			if ( oPos[i][0] && oPos[i][1] && oPos[i][2] && oPos[i][3] )
				oWon = true;
			if ( oPos[0][i] && oPos[1][i] && oPos[2][i] && oPos[3][i] )
				oWon = true;
		}

		if ( xPos[0][0] && xPos[1][1] && xPos[2][2] && xPos[3][3] )
			xWon = true;
		if ( xPos[0][3] && xPos[1][2] && xPos[2][1] && xPos[3][0] )
			xWon = true;
		
		if ( oPos[0][0] && oPos[1][1] && oPos[2][2] && oPos[3][3] )
			oWon = true;
		if ( oPos[0][3] && oPos[1][2] && oPos[2][1] && oPos[3][0] )
			oWon = true;

		bw.append( "Case #"+n+": " );
		if      ( xWon )     bw.append( "X won" );
		else if ( oWon )     bw.append( "O won" );
		else if ( finished ) bw.append( "Draw" );
		else                 bw.append( "Game has not completed" );
		bw.append( "\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/qualification/tictactoetomek/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/tictactoetomek/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String[] testCase = new String[4];
			testCase[0] = br.readLine();
			testCase[1] = br.readLine();
			testCase[2] = br.readLine();
			testCase[3] = br.readLine();
			br.readLine();
			calculate( testCase, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
