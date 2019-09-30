/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: May 7, 2010
 * 
 * Copyright 2010 by Greg Dougherty
 */

package net.molsoft.ThemePark;

import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class RollerCoaster
{
	
	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		File	dataFile = new File (args[0]);
		
		try
		{
			BufferedReader	dataReader = new BufferedReader (new FileReader (dataFile));
			String			line = dataReader.readLine ();	// Get first line
			String[]		numbers;
			int				numCases = new Integer (line).intValue ();
			
			// Load all the alien words into the tree
			for (int i = 0; i < numCases; ++i)
			{
				// Get first line, Park info
				line = dataReader.readLine ();
				numbers = line.split (" ");
				
				int		numRides = new Integer (numbers[0]).intValue ();
				int		rideCapacity = new Integer (numbers[1]).intValue ();
				int		numGroups = new Integer (numbers[2]).intValue ();
				long	totalRiders = 0;
				
				// Get second line, group info
				line = dataReader.readLine ();
				numbers = line.split (" ");
				
				int[]	groups = new int[numGroups];
				for (int j = 0; j < numGroups; ++j)
					totalRiders += groups[j] = new Integer (numbers[j]).intValue ();
				
				long	riderCount = 0;
				
				if (totalRiders <= rideCapacity)
					riderCount = numRides * totalRiders;
				else
					riderCount = handleRides (numRides, rideCapacity, groups);
				
				System.out.println ("Case #" + (i + 1) + ": " + riderCount);
			}
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
	
	/**
	 * @param numRides
	 * @param rideCapacity
	 * @param groups
	 * @return
	 */
	private static long handleRides (int numRides, int rideCapacity, int[] groups)
	{
		long[][]	rideResults = calcRideResults (rideCapacity, groups);
		long	totalRiders = 0;
		int		whichGroup = 0;
		
		for (int i = 0; i < numRides; ++i)
		{
			long[]	rideInfo = rideResults[whichGroup];
			totalRiders += rideInfo[0];
			whichGroup = (int) rideInfo[1];
		}
		
		return totalRiders;
	}
	
	
	/**
	 * @param rideCapacity
	 * @param groups
	 * @return
	 */
	private static long[][] calcRideResults (int rideCapacity, int[] groups)
	{
		int			numGroups = groups.length;
		long[][]	rideResults = new long[numGroups][];
		
		for (int i = 0; i < numGroups; ++i)
		{
			boolean	done = false;
			int		riders = 0;
			int		group = i;
			
			while (!done)
			{
				int	rideTest = riders + groups[group];
				
				if (rideTest > rideCapacity)
					done = true;
				else
				{
					riders = rideTest;
					++group;
					if (group >= numGroups)
						group = 0;
				}
			}
			
			long[]	rideInfo = new long[2];
			rideInfo[0] = riders;
			rideInfo[1] = group;	// Always points to group that didn't make it
			
			rideResults[i] = rideInfo;
		}
		
		return rideResults;
	}
	
}
