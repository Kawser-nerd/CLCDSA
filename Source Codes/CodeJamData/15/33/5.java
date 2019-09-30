package c_2015;

import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int kases = in.nextInt();
		
		for(int kas = 1; kas<=kases; kas++)
		{
			int C = in.nextInt();
			int D = in.nextInt();
			int V = in.nextInt();
			if (kas == 31)
			{
				C = C;
			}
			long max = 0;
			int added = 0;
			
			for (int i = 0; i<D; i++)
			{
				long coin = in.nextLong();
				while (max + 1 < coin)
				{
					max += C * (max + 1);
					added++;
				}
				
				max += C * coin;
			}
			
			while (max < V)
			{
				max += C * (max + 1);
				added++;
			}
			
			System.out.println("Case #"+ kas + ": " + added);
		}
	}

}
