/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: May 7, 2010
 * 
 * Copyright 2010 by Greg Dougherty
 */

package net.molsoft.snapper;

import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class SnapSolver
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
			int				i, numCases = new Integer (line).intValue ();
			
			// Load all the alien words into the tree
			for (i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				
				numbers = line.split (" ");
				int		numSnappers = new Integer (numbers[0]).intValue ();
				int		numSnaps = new Integer (numbers[1]).intValue ();
				int		tester = 0;
				
				for (int j = 0; j < numSnappers; ++j)
					tester += 1 << j;
				
				System.out.print ("Case #" + (i + 1) + ": ");
				if ((numSnaps & tester) == tester)
					System.out.println ("ON");
				else
					System.out.println ("OFF");
			}
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
}
