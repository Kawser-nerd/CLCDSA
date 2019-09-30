import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;


public class TypewriterMonkey {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer));
		}
	}
	
	public static double solve(BufferedReader buffer) throws NumberFormatException, IOException
	{
		//read input
		String[] split = buffer.readLine().trim().split("\\s+");
		int K = Integer.parseInt(split[0]);
		int L = Integer.parseInt(split[1]);
		int S = Integer.parseInt(split[2]);
		
		String keys = buffer.readLine().trim();
		String target = buffer.readLine().trim();

		int differentStrings = (int)Math.pow(K,S);
		
		int max = 0;
		int sum = 0;
		
		for(int i = 0; i < differentStrings; i++)
		{
			int number = i;
			String result = new String();
			for(int j = 0; j < S; j++)
			{
				result = result.concat("" + keys.charAt(number%K));
				number /= K;
			}
			int count = 0;
			int from = 0;
			while((from = result.indexOf(target, from) + 1) > 0)
			{
				count++;
			}
			sum += count;
			if(count > max)
				max = count;
		}
		
		return 1.0 * max - 1.0 * sum / differentStrings;
		
	}
}