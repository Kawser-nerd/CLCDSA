import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;


public class LessMoneyMoreProblems {

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
	
	public static long solve(BufferedReader buffer) throws NumberFormatException, IOException
	{
		//read input
		String[] split = buffer.readLine().trim().split("\\s+");
		long C = Long.parseLong(split[0]);
		int D = Integer.parseInt(split[1]);
		long V = Long.parseLong(split[2]);
		
		String[] sCoins = buffer.readLine().trim().split("\\s+");
		long[] coins = new long[D];
		for(int i = 0; i < D; i++)
		{
			coins[i] = Long.parseLong(sCoins[i]);
		}
		int index = 0;
		long current = 0;
		long count = 0;
		while(current < V)
		{
			if(index < D && coins[index] <= current + 1 )
			{
				current += C * coins[index];
				index++;
			} else {
				current +=  C * (current + 1);
				count++;
			}
		}
				
		return count;
	}
}