import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Collection;
import java.util.Scanner;

// https://code.google.com/codejam/contest/6254486/dashboard#s=p2

// not very optimised

public class JamCoin {
	private static final BigInteger TWO = BigInteger.valueOf( 2 );
	private static final BigInteger FASTLIMIT = BigInteger.valueOf( 100000 );

	private static BigInteger findFactor( final BigInteger value ) {
		// thanks, http://stackoverflow.com/a/16804552/1180785
		if( value.mod( TWO ).equals( BigInteger.ZERO ) ) {
			return TWO;
		}
		BigInteger f = BigInteger.valueOf( 3 );
		while( f.multiply( f ).compareTo( value ) <= 0 ) {
			if( value.mod( f ).equals( BigInteger.ZERO ) ) {
				return f;
			}
			f = f.add( TWO );
		}
		return null;
	}

	private static boolean isPrimeOrDifficult( final BigInteger value ) {
		// thanks, http://stackoverflow.com/a/16804552/1180785
		if( value.mod( TWO ).equals( BigInteger.ZERO ) ) {
			return false;
		}
		BigInteger f = BigInteger.valueOf( 3 );
		while( f.multiply( f ).compareTo( value ) <= 0 && f.compareTo( FASTLIMIT ) <= 0 ) {
			if( value.mod( f ).equals( BigInteger.ZERO ) ) {
				return false;
			}
			f = f.add( TWO );
		}
		return true;
	}

	private static boolean testJamcoinFast( final String jamcoin ) {
		for( int base = 2; base <= 10; ++ base ) {
			final BigInteger value = new BigInteger( jamcoin, base );
			if( isPrimeOrDifficult( value ) ) {
				return false;
			}
		}
		return true;
	}

	private static boolean testJamcoin( final String jamcoin ) {
		for( int base = 2; base <= 10; ++ base ) {
			final BigInteger value = new BigInteger( jamcoin, base );
			if( value.isProbablePrime( 5 ) ) {
				if( findFactor( value ) == null ) {
					return false;
				}
			}
		}
		return true;
	}

	private static Collection<String> mineJamcoins( final int N, final int limit ) {
		if( N < 2 || limit <= 0 ) {
			return Collections.emptyList( );
		}
		final int fill = N - 2;
		final Collection<String> jamcoins = new ArrayList<>( limit );

		char[] builder = new char[N];
		builder[0] = '1';
		for( int i = 0; i < fill; ++ i ) {
			builder[i+1] = '0';
		}
		builder[N-1] = '1';

		while( true ) {
			// test current value
			final String jamcoin = new String( builder );
			if( testJamcoinFast( jamcoin ) ) {
				jamcoins.add( jamcoin );
				System.err.println( "Found " + jamcoin + " (#" + jamcoins.size( ) + ")" );
				if( jamcoins.size( ) >= limit ) {
					return jamcoins; // limit reached
				}
			}

			// step to next test value
			int p = fill;
			while( builder[p] == '1' ) {
				builder[p] = '0';
				if( (-- p) == 0 ) {
					return jamcoins; // no more values to test
				}
			}
			builder[p] = '1';
		}
	}

	public static void main( final String[] args ) {
		final Scanner input = new Scanner( System.in );
		final int totalTests = input.nextInt( );
		for( int n = 0; n < totalTests; ++ n ) {
			final int N = input.nextInt( );
			final int J = input.nextInt( );
			final Collection<String> jamcoins = mineJamcoins( N, J );
			System.out.println( "Case #" + (n + 1) + ":" );
			for( final String jamcoin : jamcoins ) {
				System.out.print( jamcoin );
				for( int base = 2; base <= 10; ++ base ) {
					System.out.print( " " + findFactor( new BigInteger( jamcoin, base ) ) );
				}
				System.out.println( );
			}
		}
	}
}
