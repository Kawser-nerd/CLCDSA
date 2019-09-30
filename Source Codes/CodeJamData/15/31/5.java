package c_2015;

import java.util.Scanner;

public class A {
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		
		int kases = in.nextInt();
		
		for(int kas = 1; kas<=kases; kas++)
		{
			int R = in.nextInt();
			int C = in.nextInt();
			int W = in.nextInt();
			
			int ans = C / W * R + W - 1;
			
			if (C % W != 0)
				ans++;
			
			System.out.println("Case #"+ kas + ": " + ans);
		}
	}
}
