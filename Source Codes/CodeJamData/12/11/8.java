import java.util.*;
public class Main
{
	public static void main(String[]args)
	{
		Scanner in = new Scanner(System.in);
		int inputs = in.nextInt();
		Q: for(int _ = 1; _ <= inputs; _++)
		{
			int a = in.nextInt();
			int b = in.nextInt();
			double exp = 2+b;
			double[] prob = new double[a+1];
			prob[0] = 1;
			for(int i = 0; i < a; i++)
			{
				prob[i+1] = prob[i] * (in.nextDouble());
			}
			double exp2 = prob[a] * (b-a + 1) + (1-prob[a])*(2*b-a+2);
			//System.out.println(exp2);
			if(exp2 < exp) exp = exp2;
			exp2 = 0;
			for(int i = 0; i < a; i++)
			{
				exp2 = prob[i]* (2*(a-i) + (b-a)+1) + (1-prob[i])*((2*(a-i) + (b-a)+1)+b+1);
				if(exp2 < exp) exp = exp2;
				//System.out.println(exp2+"!");
			}
			System.out.printf("Case #" + _ + ": %.6f\n",exp);
		}
	}

}
