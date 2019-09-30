import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.LinkedList;
import java.util.List;


public class RopeIntranet {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		RandomAccessFile in = new RandomAccessFile(args[0], "r");
		RandomAccessFile out = new RandomAccessFile(args[1], "rw");
	
		int caseCount = Integer.parseInt(in.readLine());
		for(int i = 1; i <= caseCount; i++)
		{
			List<Integer> A = new LinkedList<Integer>();
			List<Integer> B = new LinkedList<Integer>();
			int N = Integer.parseInt(in.readLine().trim());
			for(int j = 0; j < N; j++)
			{
				String[] temp = in.readLine().trim().split(" ");
				A.add(Integer.parseInt(temp[0]));
				B.add(Integer.parseInt(temp[1]));
			}
			
			//output result
			String result = "Case #";
			int retCode = calculate(A, B);
			result = result + i + ": " + retCode + "\n";
			out.writeBytes(result);
			
		}

	}
	
	
	public static int calculate(List<Integer> A, List<Integer> B)
	{
		int ret = 0;
		int length  = A.size();
		for(int i = 1; i < length; i++)
			for(int j = 0; j < i; j++)
			{
				if( (A.get(i) - A.get(j)) * (B.get(i) - B.get(j)) < 0 )
				{
					ret++;
				}
			}
		return ret;
	}

}
