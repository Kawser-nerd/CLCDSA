import java.util.*;
public class a {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		int a = input.nextInt()-1;
		boolean[] possible = new boolean[17];
		int count = 0;
		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++)
			{
				int cur = input.nextInt();
				if(i == a) possible[cur] = true;
			}
		boolean[] poss2 = new boolean[17];
		int b = input.nextInt()-1;
		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++)
			{
				int cur = input.nextInt();
				if(i == b && possible[cur]) 
				{
					//System.out.println(cur);
					poss2[cur] = true;
					count++;
				}
			}
		//System.out.println(count);
		if(count > 1) System.out.println("Bad magician!");
		else if(count == 0) System.out.println("Volunteer cheated!");
		else
		{
			int res = 0;
			for(int i = 1; i<17; i++) if(poss2[i]) res = i;
			System.out.println(res);
		}
	}
}
}
