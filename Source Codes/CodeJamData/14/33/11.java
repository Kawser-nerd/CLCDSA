import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class GCJ_2014_R1C_3 {
		
	public static void main(String[] args) throws Exception {
//		String fname = "C_example";
		String fname = "C_small";
//		String fname = "C_large";
	
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
		
		int T = scanner.nextInt();
		
		for (int i=1;i<=T;i++)
		{
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			int K = scanner.nextInt();
			
			int min = 9999;
			
			int[][] table = new int[N][];
			for (int j=0;j<N;j++)
				table[j] = new int[M];
			
			
			int xend = 1 << (N*M);
			for (int x = 0; x < xend; x++)
			{
				int stoneCnt = 0;
				for (int n=0;n<N;n++)
					for (int m=0;m<M;m++)
					{
						int s = ((x & (1 << (n*M+m))) != 0) ? 1 : 0;
						table[n][m] = s;
						stoneCnt += s;
					}
				
				for (int k=0;k<M;k++)
				{
					if (table[0][k] == 0)
						table[0][k] = 2; 
					if (table[N-1][k] == 0)
						table[N-1][k] = 2; 
				}
				
				for (int k=0;k<N;k++)
				{
					if (table[k][0] == 0)
						table[k][0] = 2; 
					if (table[k][M-1] == 0)
						table[k][M-1] = 2; 
				}
				
				boolean changed = true;
				while (changed)
				{
					changed = false;
					for (int n = 1; n < N-1; n++)
						for (int m = 1; m < M-1; m++)
							if (table[n][m] == 0)
							{
								if ((table[n-1][m] == 2) || (table[n+1][m] == 2) || (table[n][m-1] == 2) || (table[n][m+1] == 2))
								{
									table[n][m] = 2;
									changed = true;
								}
							}
				}
				
				int floodCnt = 0;
				for (int n=0;n<N;n++)
					for (int m=0;m<M;m++)
						if (table[n][m] != 2)
							floodCnt ++;
				if (floodCnt >= K)
					if (stoneCnt < min)
						min = stoneCnt;
			}
			
			System.out.println(i);
			outp.printf("Case #%d: %d\n",i,min);
			
		}
		
		outp.close();
	}

}
