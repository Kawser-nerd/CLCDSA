import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException
	{	
		Scanner sc = new Scanner(System.in);
		int candies_a = 0;
		int candies_b = 0;
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		a[0] = sc.nextInt();
		for(int i=1;i<n;i++)
		{	int tmp = sc.nextInt();
			a[i] = a[i-1]+tmp;
			//candies_a+=tmp;
		}
		//candies_b+=a[0];
		b[0] = sc.nextInt();
		for(int i=1;i<n;i++)
		{
			int tmp = sc.nextInt();
			b[i] = b[i-1]+tmp;
			//candies_b +=b[i];
		}
		//for(int i =0;i<n;i++)
			//System.out.println(a[i]+" "+b[i]);
		
		int candies =a[0]+b[n-1];
		//candies = a[0];
		
		for(int i=1;i<n;i++)
		{
			int tmp = a[i]+(b[n-1]-b[i-1]);
			if(tmp>candies)
			{
				candies = tmp;
			}
		}
		System.out.print(candies);
	}
	
}