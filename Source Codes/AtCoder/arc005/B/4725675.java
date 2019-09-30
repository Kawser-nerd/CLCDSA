import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		final int x = sc.nextInt();
		final int y = sc.nextInt();
		final String w = sc.next();

		String c[][]=new String[9][9];

		for(int i=0;i<9;i++)
		{
			String tmp = sc.next();
			for(int j=0;j<9;j++)
			{
				c[i][j]=""+tmp.charAt(j);
			}
		}
		System.out.println(getNum(w,x,y,c));
	}
	static String getNum(String w,int x,int y,String c[][])
	{
		int spx=0;
		int spy=0;
		int nx=x-1;
		int ny=y-1;
		if(w.indexOf("R")!=-1)
		{
			spx++;
		}
		if(w.indexOf("L")!=-1)
		{
			spx--;
		}
		if(w.indexOf("U")!=-1)
		{
			spy--;
		}
		if(w.indexOf("D")!=-1)
		{
			spy++;
		}
		String pnum=c[ny][nx];
		for(int i=0;i<3;i++)
		{
			if((nx+spx)>8||(nx+spx)<0)
			{
				spx=spx*-1;
			}
			if((ny+spy)>8||(ny+spy)<0)
			{
				spy=spy*-1;
			}
			nx+=spx;
			ny+=spy;

			pnum+=c[ny][nx];
		}
		return pnum;
	}
}