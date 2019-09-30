import java.util.*;

public class Yes{

	public static void main(String[] args){
	
		Scanner in = new Scanner(System.in);
		
		int cas = in.nextInt();
		
		for(int c = 1; c <= cas; c++)
		{
			System.out.print("Case #" + c + ": ");
				int num = in.nextInt();
				int as = (num * 2) - 1;
				as *= num;
				int exp = num;
				int[] h = new int[2501];
				for(int i = 0; i < as; i++)
				{
					h[in.nextInt()]++;
				}
				for(int i = 1; i <= 2500; i++)
				{
					if(h[i] % 2 == 1)
					{
						if(exp == 1)
						{
							System.out.println(i);
						} else {
							System.out.print(i + " ");
							exp--;
						}
					}
				}
		}
	}
}