import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class Round17
{
	static HashMap<Integer, BigInteger> found = new HashMap<Integer, BigInteger>();
		
	public static void main(String [] args)
	{
		try 
		{
			Scanner input = new Scanner(new File("in.txt"));
			FileWriter out = new FileWriter("out.txt");
			int cases = input.nextInt();
			for(int caseNum = 0; caseNum < cases; caseNum++)
			{
				found = new HashMap<Integer, BigInteger>();
				int n = input.nextInt();
				int m = input.nextInt();
				long X = input.nextLong();
				long Y = input.nextLong();
				long Z = input.nextLong();
				long [] arr = new long[n];
				long [] gen = new long[m];
				for(int i = 0; i < m; i++)
				{
					gen[i] = input.nextLong();
					arr[i] = gen[i];
				}
				for(int i = 0; i < n; i++)
				{
					arr[i] = gen[i % m];
					gen[i % m] = (X * gen[i % m] + Y * (i + 1)) % Z ;
				}
				
				//System.out.println(Arrays.toString(arr));
				BigInteger answer = new BigInteger("0");
				for(int i = 0; i < n; i++)
				{
					answer = answer.add(sequences(i, arr));
				}
				answer = answer.mod(new BigInteger("1000000007"));
				out.write("Case #" + (caseNum + 1) + ": " + answer + "\n" );
				System.out.println(answer);
			}
			out.close();
		}
		catch (FileNotFoundException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static BigInteger sequences(int n, long[] arr)
	{
		if(found.containsKey(n))
		{
			return found.get(n);
		}
		BigInteger ret = new BigInteger("1");
		for(int i = n + 1; i < arr.length; i++)
		{
			if(arr[i] > arr[n])
			{
			//	System.out.println(i + " is larger");
				ret = ret.add(sequences(i, arr));
			}
		}
		found.put(n, ret);
	//	System.out.println(n + " " + ret);
		return ret;
	}
}
