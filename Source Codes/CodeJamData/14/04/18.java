import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Exe4 {
	public static void main (String[] args) throws Exception
	{
		Scanner input = new Scanner(new File("input"));
		BufferedWriter output = new BufferedWriter(new FileWriter(new File("output")));
		int T = input.nextInt();
		for ( int i = 0; i<T ; i++)
		{
			int N = input.nextInt();
			double[] Noemi = new double[N];
			double[] Ken = new double[N];
			
			for( int j = 0; j < N; j++)
			{
				Noemi[j] = input.nextDouble();
			}
			for( int j = 0; j < N; j++)
			{
				Ken[j] = input.nextDouble();
			}
			Arrays.sort(Noemi);
			Arrays.sort(Ken);
			
			int ans1 = 0;
			int ans2 = 0;
			
			int k;
			int j;
			
			k = 0;
			j = 0;
			
			while ( k < N)
			{
				while( k < N && Noemi[j] > Ken[k])
				{
					k++;
				}
				if ( k < N)
				{
					j++;
					k++;
				}
			}
			ans1 = N - j;
			
			
			k = 0;
			j = 0;
			while ( j < N )
			{
				while(j < N && Noemi[j] < Ken[k])
				{
					j++;
				}
				if ( j < N )
				{
					j++;
					k++;
				}
			}
			
			ans2 = k;
			output.write("Case #"+(i+1)+": "+ans2+" "+ans1);
			
			output.newLine();
			output.flush();
		}
		output.flush();
		input.close();
		output.close();
	}
}


