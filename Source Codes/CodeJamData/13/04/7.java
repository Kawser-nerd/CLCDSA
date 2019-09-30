package qualification.treasure;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Treasure
{
	private static void calculate( Collection<Integer> initKeys, TreasureChest[] tcs, BufferedWriter bw, int n ) throws Exception
	{
		Map<Integer, Integer> keyMap = group( initKeys, null );
		
		Map<Integer, Integer> fullKeyMap = new HashMap<Integer, Integer>( keyMap );
		Collection<Integer> locks = new ArrayList<Integer>();
		for ( TreasureChest tc : tcs )
		{
			locks.add( tc.getLock() );
			group( tc.getKeys(), fullKeyMap );
		}
		
		Map<Integer, Integer> fullLockMap = group( locks, null );
		for ( Map.Entry<Integer, Integer> lockCount : fullLockMap.entrySet() )
		{
			int key = lockCount.getKey();
			int lCount = lockCount.getValue();
			Integer keyCount = fullKeyMap.get( key );
			if ( keyCount == null || keyCount < lCount )
			{
				bw.append( "Case #"+n+": IMPOSSIBLE\n" );
				bw.flush();
				return;
			}
			
		}
		
		boolean[] isOpened = new boolean[tcs.length];
		String s = check( keyMap, tcs, isOpened, "", 0 );
		if ( s != null )
			bw.append( "Case #"+n+": " + s.trim() + "\n" );
		else
			bw.append( "Case #"+n+": IMPOSSIBLE\n" );
		bw.flush();
	}
	
	private static String check( Map<Integer, Integer> keyMap, TreasureChest[] tcs, boolean[] isOpened, String s, int oc )
	{
		Set<Integer> availableKeys = new HashSet<Integer>( keyMap.keySet() );
		boolean more = true;
		while ( more )
		{
			more = false;
			for ( int i = 0; i < tcs.length; i++ )
			{
				if ( !isOpened[i] && availableKeys.contains( tcs[i].getLock() ) )
				{
					for ( int key : tcs[i].getKeys()  )
						if ( availableKeys.add( key ) )
							more = true;
				}
			}
		}

		Set<Integer> keysNeeded = new HashSet<Integer>();
		for ( int i = 0; i < tcs.length; i++ )
			if ( !isOpened[i] )
				keysNeeded.add( tcs[i].getLock() );
		
		keysNeeded.removeAll( availableKeys );
		if ( !keysNeeded.isEmpty() )
			return null;
			
		
		if ( oc == tcs.length )
			return s;
		
		for ( int i = 0; i < tcs.length; i++ )
		{
			if ( isOpened[i] )
				continue;
			
			TreasureChest tc = tcs[i];
			if ( keyMap.containsKey( tc.getLock() ) )
			{
				Map<Integer, Integer> newKeyMap = new HashMap<Integer, Integer>( keyMap );
				for ( int key : tc.getKeys() )
				{
					Integer c = newKeyMap.containsKey( key ) ? newKeyMap.get( key ) : 0;
					newKeyMap.put( key, c+1 );
				}
				
				int c = newKeyMap.get( tc.getLock() );
				if ( c == 1 )
					newKeyMap.remove( tc.getLock() );
				else
					newKeyMap.put( tc.getLock(), c-1 );
			
				boolean[] newIsOpened = new boolean[isOpened.length];
				System.arraycopy( isOpened, 0, newIsOpened, 0, newIsOpened.length );
				newIsOpened[i] = true;
				
				String r = check( newKeyMap, tcs, newIsOpened, s + " " + (i+1), oc+1 );
				if ( r != null )
					return r;
			}
		}
		
		return null;
	}
	
	private static Map<Integer, Integer> group( Collection<Integer> keys, Map<Integer, Integer> start )
	{
		Map<Integer, Integer> map = start == null ? new HashMap<Integer, Integer>() : start;
		
		for ( int key : keys )
		{
			Integer c = map.containsKey( key ) ? map.get( key ) : 0;
			map.put( key, c+1 );
		}
		
		return map;
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/qualification/treasure/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/treasure/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String[] kn = br.readLine().split( " " );
			int K = Integer.parseInt( kn[0] );
			int N = Integer.parseInt( kn[1] );
			
			Collection<Integer> initKeys = new ArrayList<Integer>();
			String[] keyTokens = br.readLine().split( " " );
			for ( int j = 0; j < K; j++ )
				initKeys.add( Integer.parseInt( keyTokens[j] ) );
			
			TreasureChest[] tcs = new TreasureChest[N];
			for ( int j = 0; j < N; j++ )
			{
				String[] tcTokens = br.readLine().split( " " );
				int lock = Integer.parseInt( tcTokens[0] );
				int kNum = Integer.parseInt( tcTokens[1] );
				Collection<Integer> keys = new ArrayList<Integer>();
				for ( int k = 0; k < kNum; k++ )
					keys.add( Integer.parseInt( tcTokens[k+2] ) );
				
				tcs[j] = new TreasureChest( lock, keys );
			}
			
			calculate( initKeys, tcs, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
	
	private static class TreasureChest
	{
		private final int   lock;
		private final Collection<Integer> keys;
		
		public TreasureChest( int lock, Collection<Integer> keys )
		{
			this.lock = lock;
			this.keys = keys;
		}

		public int getLock() {
			return lock;
		}

		public Collection<Integer> getKeys() {
			return keys;
		}
	}
}
