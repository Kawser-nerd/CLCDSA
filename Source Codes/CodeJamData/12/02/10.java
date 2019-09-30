import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(new File("in.txt"));
		FileOutputStream fos = new FileOutputStream(new File("out.txt"));
		Scanner sc = new Scanner(fis);
		PrintWriter out = new PrintWriter(fos);
		int cases = sc.nextInt();
		for(int cs = 1; cs <= cases; cs++)
		{
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			int [] sums = new int[n];
			for(int i=0; i<n; i++)
				sums[i] = sc.nextInt();
			int notsup = 0;
			int supx = 0;
			for(int i=0; i<n; i++)
			{
				if(getMax(sums[i],1)>=p)
					notsup++;
				if(getMax(sums[i],2)<p)
					supx++;
				
			}
			int total = notsup+Math.min(n-notsup-supx, s);
			out.println("Case #"+cs+": "+total);
		}
		sc.close();
		out.close();
	}
	public static int getMax(int sum, int diff)
	{
		int max = Integer.MIN_VALUE;
		for(int i=0; i<=10; i++)
			for(int j=0; j<=10; j++)
			{
				int k=sum-i-j;
				if(k>=0 && k<=10)
				{
					int d = Math.abs(i-j);
					d = Math.max(d, Math.abs(k-j));
					d = Math.max(d, Math.abs(k-i));
					if(d<=diff)
					{
						max = Math.max(i, max);
						max = Math.max(j, max);
						max = Math.max(k, max);
						
					}
				}
			}
		return max;
	}
}
