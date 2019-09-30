import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;


public class Brattleship {

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
			System.out.println("Case #"+i+": " + solve(buffer.readLine().trim()));
		}
	}
	
	public static int solve(String data) throws NumberFormatException, IOException
	{
		String[] split = data.split("\\s+");
		int R = Integer.parseInt(split[0]);
		int C = Integer.parseInt(split[1]);
		int W = Integer.parseInt(split[2]);
		
		if(W == 1)
		{
			return R * C;
		}
		if(C%W == 0)
		{
			return R * (C/W) + W - 1;
		} else {
			return R * (C/W) + W;
		}
	}
}
