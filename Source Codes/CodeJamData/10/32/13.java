import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.LinkedList;
import java.util.List;


public class LoadTesting {

	/**
	 * @param args
	 */
	public static List<Integer> ans = new LinkedList<Integer>();
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		ans.clear();
		for(int i = 0; i < 40; i++)
		{
			ans.add(pToTestCount(i));
			System.out.println(i+":"+pToTestCount(i));
		}
		
		RandomAccessFile in = new RandomAccessFile(args[0], "r");
		RandomAccessFile out = new RandomAccessFile(args[1], "rw");
	
		int caseCount = Integer.parseInt(in.readLine());
		for(int i = 1; i <= caseCount; i++)
		{
			
			long L, P, C;
			String temp[] = in.readLine().trim().split(" ");
			L = Integer.parseInt(temp[0]);
			P = Integer.parseInt(temp[1]);
			C = Integer.parseInt(temp[2]);
			
			int p = 0;
			while(L < P)
			{
				p++;
				L = L * C;
			}
			p--;
			
			
			//output result
			String result = "Case #";
			int retCode = ans.get(p);
			result = result + i + ": " + retCode + "\n";
			out.writeBytes(result);
		}
		
		

	}
	
	public static int pToTestCount(int p)
	{
		if(p == 0)
			return 0;
		int ret = 1;
		return ret + pToTestCount(p / 2);
	}

}
