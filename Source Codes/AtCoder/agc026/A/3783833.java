import java.util.Scanner;

public class Main {
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int mark=9999;
		int n;
		int i;
		int a[]=new int[10000];
		n=sc.nextInt();
		for(i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
		}
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				a[i]=mark;
				mark--;
			}
		}
		System.out.print(9999-mark);
	}
}