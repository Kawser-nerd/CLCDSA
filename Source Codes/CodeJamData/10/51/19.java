package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public int num( int k)
	{
		return k*(k+1)/2 + k*(k-1)/2;
	}

	String [] dia = new String[ 2*100 ];
	int [][] aa = new int[400][400];
	int [][] diaa = new int[400][400];
	boolean checkaa( int a)
	{
		for(int i=1;i<a ;i++)
		{
			for(int j=0;j<=2*a;j++)
				if( aa[i][j] != aa[2*a-i][j] && aa[i][j]!=-1 && aa[2*a-i][j]!=-1 )
				{
					return false;
				}
		}
		for(int i=1;i<2*a;i++)
		{
			for(int j=0;j<a-1;j++)
				if( aa[i][j] != aa[i][ 2*(a-1) - j ] && aa[i][j]!=-1 && aa[i][2*(a-1)-j]!=-1 )
				{
					return false;
				}
		}
		return true;
	}
	boolean leftup(int a, int k)
	{
		for(int p=0;p<=a-k;p++)
		{
			for(int i=0;i<=2*a;i++)
				Arrays.fill(aa[i], -1);
			
			// i-> i+p;
			// j-> a - k - p + j;
			for(int i=1;i<=k;i++)
				for(int j=k-i;j<= k+i - 2; j+=2 )
				{
				//	System.out.println( a+" "+ k + " " + (i+p) + " " + ( j+a-k-p ) + " " + i + " " + j );
					aa[i+p][j+a-k-p] = diaa[i][j]; 
				}
			for(int i=k+1;i<=2*k-1;i++)
				for(int j=i-k;j<=i-k + (2*k-i)*2 - 2; j+=2 )
					aa[i+p][j+a-k-p] = diaa[i][j];
			
//			for(int i=1;i<2*a;i++)
//			{
//				for(int j=0;j<2*a;j++)
//					if( aa[i][j] == -1 )
//						System.out.print( "*" + " " );
//					else
//						System.out.print( aa[i][j] + " " );
//				System.out.println();
//			}
//			System.out.println();
			if( checkaa( a ) )
				return true;
		}
		return false;
	}
	boolean leftdown(int a, int k)
	{

		for(int p=0;p<=a-k;p++)
		{
			for(int i=0;i<=2*a;i++)
				Arrays.fill(aa[i], -1);

			// i-> i - p + 2*(a-k);
			// j-> a - k - p + j;
			for(int i=1;i<=k;i++)
				for(int j=k-i;j<= k+i - 2; j+=2 )
				{
					aa[ i-p+2*(a-k) ][ j + a-k-p ] = diaa[i][j]; 
				}
			for(int i=k+1;i<=2*k-1;i++)
				for(int j=i-k;j<=i-k + (2*k-i)*2 - 2; j+=2 )
					aa[ i-p+2*(a-k) ][ j + a-k-p ] = diaa[i][j]; 
			if( checkaa( a ) )
				return true;
		}
		return false;
	}
	boolean rightup(int a, int k)
	{
		for(int p=0;p<=a-k;p++)
		{
			for(int i=0;i<=2*a;i++)
				Arrays.fill(aa[i], -1);
			boolean flag = true;
			
			// i-> i+p;
			// j-> a - k + p + j;
			for(int i=1;i<=k;i++)
				for(int j=k-i;j<= k+i - 2; j+=2 )
				{
					aa[i+p][j+a-k+p] = diaa[i][j]; 
				}
			for(int i=k+1;i<=2*k-1;i++)
				for(int j=i-k;j<=i-k + (2*k-i)*2 - 2; j+=2 )
					aa[i+p][j+a-k+p] = diaa[i][j]; 
			if( checkaa( a ) )
				return true;
		}
		return false;
	}
	boolean rightdown(int a, int k)
	{

		for(int p=0;p<=a-k;p++)
		{
			for(int i=0;i<=2*a;i++)
				Arrays.fill(aa[i], -1);
			boolean flag = true;
			
			// i-> i - p + 2*(a-k);
			// j-> a - k + p + j;
			for(int i=1;i<=k;i++)
				for(int j=k-i;j<= k+i - 2; j+=2 )
				{
					aa[i-p+2*(a-k)][j+a-k+p] = diaa[i][j]; 
				}
			for(int i=k+1;i<=2*k-1;i++)
				for(int j=i-k;j<=i-k + (2*k-i)*2 - 2; j+=2 )
					aa[i-p+2*(a-k)][j+a-k+p] = diaa[i][j]; 
			if( checkaa( a ) )
				return true;
		}
		return false;
	}
	public void solve() throws FileNotFoundException{
		Scanner cin = new Scanner(new File("input.txt"));
		System.setOut(new PrintStream("AL.txt"));
		int T = cin.nextInt();
		for(int cas=1;cas<=T;cas++)
		{
			int k= cin.nextInt();
			cin.nextLine();
			for(int i=1;i<=2*k-1;i++)
			{
				dia[i] = cin.nextLine();
				for(int j=0;j<dia[i].length();j++)
					diaa[i][j] =  dia[i].charAt(j) - '0';
			}
//			System.out.println("K" + k);
//			for(int i=1;i<=2*k-1;i++)
//			{
//				for(int j=0;j<=2*(k-1);j++)
//					System.out.print( diaa[i][j]+ " " );
//				System.out.println();
//			}
			for(int a = k;;a++)
			{
				if( leftup(a,k)|| rightup(a,k) || leftdown(a,k) || rightdown(a,k) )
				{
					System.out.println("Case #"+cas+": " +  (num(a) - num(k)) );
					break;
				}
			}
		}
	}
	public static void main(String[] args) throws FileNotFoundException{
		A a = new A();
		a.solve();
	}
}
