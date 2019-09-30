import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;


public class MakeingChessBoard {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		RandomAccessFile in = new RandomAccessFile(args[0], "r");
		RandomAccessFile out = new RandomAccessFile(args[1], "rw");
	
		int caseCount = Integer.parseInt(in.readLine());
		
		for(int i = 1; i <= caseCount; i++)
		{
			int M, N;
			String[] temp = in.readLine().trim().split(" ");
			M = Integer.parseInt(temp[0]);
			N = Integer.parseInt(temp[1]);
			bark = new int[M][N];
			for(int ii = 0; ii < M; ii++)
			{
				String line = in.readLine().trim();
				for(int jj = 0; jj < N / 4; jj++)
				{
					int tttt = Integer.parseInt(line.substring(jj, jj + 1), 16);
					int test = tttt & 8;
					bark[ii][jj * 4 + 0] = (tttt & 8 )/ 8;
					bark[ii][jj * 4 + 1] = (tttt & 4) / 4;
					bark[ii][jj * 4 + 2] = (tttt & 2) / 2;
					bark[ii][jj * 4 + 3] = tttt & 1;
					
				}
			}
			
			int MaxSize = Math.min(M, N);
			int[] result = new int[MaxSize + 1];
			for(int ii = MaxSize; ii > 0; ii-- )
			{
				for(int iii = 0; iii < M - ii + 1; iii++)
					for(int jjj = 0; jjj < N - ii + 1; jjj++)
					{
						if(testCut(iii, jjj, ii))
						{
							result[ii]++;
							removeBark(iii, jjj, ii);
						}
					}
			}
			
			int resultCount = 0;
			for(int ii = 1; ii < MaxSize + 1; ii++)
			{
				if(result[ii] > 0)
				{
					resultCount++;
				}
			}
			
			//result
			String resultStr = "Case #" + i + ": " + resultCount + "\n";
			for(int ii = MaxSize; ii > 0; ii--)
			{
				if(result[ii] > 0)
				{
					resultStr += ii + " " + result[ii] + "\n";
				}
			}
			
			out.writeBytes(resultStr);
			
			
			
			
			
		}
	

	}
	
	public static int[][] bark;
	
	public static boolean testCut(int a, int b, int size)
	{
		int start1 = 0, start2 = 0;

		
		for(int i = a; i < a + size; i++)
		{
			if(bark[i][b] == -1)
				return false;
			if(i == a)
				start1 = bark[i][b];
			else
			{
				if(bark[i][b] != ((start1 + 1) % 2))
				{
					return false;
				}
				start1 = (start1 + 1) % 2;
			}
			for(int j = b; j < b + size; j++)
			{
				if(bark[i][j] == -1)
				{
					return false;
				}
				if(j == b)
					start2 = start1;
				else
				{
					if(bark[i][j] != (start2 + 1) % 2)
					{
						return false;
					}
					start2 = (start2 + 1) % 2;
				}
				
			}
		}
		
		return true;
	}

	public static void removeBark(int a, int b, int size)
	{
		for(int i = a; i < size + a; i++)
			for(int j = b; j < size + b; j++)
				bark[i][j] = -1;
	}
}
