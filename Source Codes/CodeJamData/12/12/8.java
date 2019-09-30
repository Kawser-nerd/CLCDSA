import java.util.*;
public class Main
{
	public static void main(String[]args)
	{
		Scanner in = new Scanner(System.in);
		int inputs = in.nextInt();
		Q: for(int _ = 1; _ <= inputs; _++)
		{
			int starcount = 0;
			int lvls = in.nextInt();
			int turns = 0;
			int[][] needed = new int[lvls][2];
			for(int i = 0; i < lvls; i++)
			{
				for(int j = 0; j < 2;j++)
				{
					needed[i][j] = in.nextInt();
				}
			}
			int[] got = new int[lvls];
			I: while(starcount < lvls*2)
			{
				turns++;
				for(int i = 0; i < lvls; i++)
				{
					if(needed[i][1] <= starcount && got[i] != 2)
					{
						starcount += 2-got[i];
						got[i] = 2;
						continue I;
					}
				}
				int bestChoice = -1;
				for(int i = 0; i < lvls; i++)
				{
					if(needed[i][0] <= starcount && got[i] == 0)
					{
						if(bestChoice == -1)
							bestChoice = i;
						else
						{
							if(needed[bestChoice][1] < needed[i][1])
								bestChoice = i;
						}
					}
					
				}
				if(bestChoice == -1)
				{
					System.out.println("Case #" + _ + ": Too Bad");
					continue Q;
				}
				starcount++;
				got[bestChoice] = 1;
			}
			System.out.println("Case #" + _ + ": " +turns);
		}
	}

}
