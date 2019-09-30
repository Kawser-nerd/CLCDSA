import java.io.*;
import java.util.*;

public class THREE
{
	public static int[] HEX2BITS(char c)
	{
		int[] out = new int[4];
		if('0' <= c && c <= '9')
			c -= '0';
		else
			c -= 'A' - 10;
		for(int i = 0; i < 4; i++, c/=2)
			out[3-i] = c%2;
		return out;
	}
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			String[] line = br.readLine().split(" ");
			int M = Integer.parseInt(line[0]);
			int N = Integer.parseInt(line[1]);
			int[][] board = new int[514][514];
			for(int i = 0; i < 514; i++)
				for(int j = 0; j < 514; j++)
					board[i][j] = -1;
			for(int i = 1; i <= M; i++)
			{
				String bl = br.readLine();
				for(int j = 0; j < N/4; j++)
					System.arraycopy(HEX2BITS(bl.charAt(j)),0,board[i],4*j+1,4);
			}
			/*for(int i = 1; i <= M; i++)
			{
				for(int j = 1; j <= N; j++)
				{
					System.out.print(board[i][j]+" ");
				}
				System.out.println();
			}*/
			int count = 0;
			int[] counts = new int[513];
			for(int i = 0; i <= 512; i++)
				counts[i] = 0;
			int last_large = 513;
			while(true)
			{
				int largest, starti, startj;
				largest = starti = startj = 0;
				for(int i = 1; i <= M && largest != last_large; i++)
				{
					for(int j = 1; j <= N && largest != last_large; j++)
					{
						if(board[i][j] != -1)
						{
							int corner = board[i][j], k;
							boolean done = false;
							for(k = 1;!done;k++)
								for(int l = 0; l <= k && !done; l++)
								{
									//System.out.println(i+" "+j+" "+k+" "+l+" "+corner);
									//System.out.println(board[i+k][j+l]);
									//System.out.println(board[i+l][j+k]);
									//System.out.println((corner+k+l)%2);
									done = ((board[i+k][j+l] != board[i+l][j+k]) || (board[i+k][j+l] != (corner+k+l)%2));
									//System.out.println(done);
								}
							if(k-1 > largest)
							{
								largest = k-1;
								starti = i;
								startj = j;
							}
						}
					}
				}
				if(largest == 0)
					break;
				if(largest != last_large)
				{
					last_large = largest;
					count++;
				}
				//System.out.println(largest +" "+ starti+" "+startj);
				counts[largest]++;
				for(int i = 0; i < largest; i++)
					for(int j = 0; j < largest; j++)
						board[i+starti][j+startj] = -1;
			}
			int squares = 0;
			System.out.println("Case #"+t+": "+count);
			for(int i = 512; i > 0; i--)
				if(counts[i] > 0)
				{
					squares += i*counts[i];
					System.out.println(i+" "+counts[i]);
				}
			assert(squares == M*N);
		}
	}
}