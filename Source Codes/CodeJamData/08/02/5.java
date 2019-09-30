import java.util.*;
import java.io.*;
public class MainB {
	
	static int find(int[][] ar, boolean done[], int start, int thres)
	{
		for(int i = start; i < ar.length; i++)
		{
			if(!done[i] && ar[i][0] >= thres)
				return i;
		}
		return -1;
	}
	
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter("B-large.out");
		int cas = in.nextInt();
		for(int iii = 0; iii < cas; iii++)
		{
			int T = in.nextInt();
			int NA = in.nextInt();
			int NB = in.nextInt();
			
			int A[][] = new int[NA][2];
			int B[][] = new int[NB][2];
			
			boolean AT[] = new boolean[NA];
			boolean BT[] = new boolean[NB];
			
			Arrays.fill(AT, false);
			Arrays.fill(BT, false);
			
			for(int i = 0; i < NA; i++)
			{
				String temp[] = in.next().trim().split(":");
				A[i][0] = 60*Integer.parseInt(temp[0]) + Integer.parseInt(temp[1]);
				temp = in.next().trim().split(":");
				A[i][1] = 60*Integer.parseInt(temp[0]) + Integer.parseInt(temp[1]);
			}
			
			for(int i = 0; i < NB; i++)
			{
				String temp[] = in.next().trim().split(":");
				B[i][0] = 60*Integer.parseInt(temp[0]) + Integer.parseInt(temp[1]);
				temp = in.next().trim().split(":");
				B[i][1] = 60*Integer.parseInt(temp[0]) + Integer.parseInt(temp[1]);
			}
			
			for(int i = NA-1; i > 0; i--)
				for(int j = 0; j < i; j++)
					if(A[j][0] > A[j+1][0] || (A[j][0] == A[j+1][0] && A[j][1] > A[j+1][1]))
					{
						int[] temp = A[j];
						A[j] = A[j+1];
						A[j+1] = temp;
					}

			for(int i = NB-1; i > 0; i--)
				for(int j = 0; j < i; j++)
					if(B[j][0] > B[j+1][0] || (B[j][0] == B[j+1][0] && B[j][1] > B[j+1][1]))
					{
						int[] temp = B[j];
						B[j] = B[j+1];
						B[j+1] = temp;
					}
			
			
			int Anext = 0;
			int Bnext = 0;
			boolean state;
			int answerA = 0;
			int answerB = 0;
			int currentTime;
			
			while(Anext < NA || Bnext < NB)
			{
				while(Anext < NA && AT[Anext]) Anext++;
				while(Bnext < NB && BT[Bnext]) Bnext++;
				
				if(Anext == NA)
				{
					if(Bnext == NB)
					{
						break;
					}
					state = true;
					currentTime = B[Bnext][0];
				}
				else
				{
					if(Bnext == NB)
					{
						state = false;
						currentTime = A[Anext][0];
					}
					else
					{
						if(A[Anext][0] < B[Bnext][0])
						{
							state = false;
							currentTime = A[Anext][0];							
						}
						else
						{
							state = true;
							currentTime = B[Bnext][0];						
						}
					}
				}
				
				if(state)
				{
					answerB++;
				}
				else answerA++;
				
				int Ap = Anext;
				int Bp = Bnext;
				
				while(true)
				{
					if(state)
					{
						int ind = find(B, BT, Bp, currentTime);
						if(ind < 0) break;
						BT[ind] = true;
						state = false;
						currentTime = B[ind][1]+T;
						Bp = ind+1;
					}
					else
					{
						int ind = find(A, AT, Ap, currentTime);
						if(ind < 0) break;
						AT[ind] = true;
						state = true;
						currentTime = A[ind][1]+T;
						Ap = ind+1;
						
					}
				}
			}
			
			out.println("Case #" + (iii+1) + ": " + answerA + " " + answerB);
		}
		out.close();
	}
}
