/*
PROBLEM: All Your Base
LANGUAGE: Java
CONTESTANT: Aram Ebtekar
*/

import java.io.*;
import java.util.*;

public class AllYourBase
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		
		int T = Integer.parseInt(in.readLine());
		
		for (int caseNum = 1; caseNum <= T; caseNum++)
		{
			char[] message = in.readLine().toCharArray();
			int[] charValue = new int[36];
			int baseCount = 2;
			boolean zeroUsed = false;
			
			for (int i = 0; i < charValue.length; i++)
			{
				charValue[i] = -1;
			}
			charValue[charToIndex(message[0])] = 1;
			
			for (int i = 1; i < message.length; i++)
			{
				if (charValue[charToIndex(message[i])] == -1)
				{
					if (!zeroUsed)
					{
						charValue[charToIndex(message[i])] = 0;
						zeroUsed = true;
					}
					else
					{
						charValue[charToIndex(message[i])] = baseCount;
						baseCount++;
					}
				}
			}
			
			long value = charValue[charToIndex(message[0])];
			
			for (int i = 1; i < message.length; i++)
			{
				value *= (long) baseCount;
				value += (long) charValue[charToIndex(message[i])];
			}
			
			out.println("Case #" + caseNum + ": " + value);
		}

		in.close();
		out.close();
		System.exit(0);
	}
	
	public static int charToIndex(char digit)
	{
		if (Character.isDigit(digit))
			return (digit - 48);
		else
			return (digit - 87);
	}
}