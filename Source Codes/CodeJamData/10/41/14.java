import java.util.*;

public class Diamond
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			System.out.println("Case #"+i+": "+solveCase());
		}
	}
	static int solveCase()
	{
		int K = sc.nextInt();
		char[][] dia = new char[2*K-1][2*K-1];
		for(int i=0;i<dia.length;i++)
		{
			Arrays.fill(dia[i], ' ');
			int first = getLower(i, K);
			for(int j=0;j<getMax(i, K);j++)
				dia[i][first+2*j] = (char)(sc.nextInt()+'0');
		}
		/*
		for(char[] ch:dia)
			A.spr(new String(ch));
		*/
		

		for(int size=K;;size++)
		{
			//A.spr("Size:"+size);
			boolean ok = false;
			for(int row=0;row<2*size-1 && !ok;row++)
			{
				for(int col=0;col<2*size-1 && !ok;col++)
				{
					//A.spr("Trying "+row+":"+col);
					boolean match = true;
					for(int i=0;i<2*K-1 && match;i++)
					{
						for(int j=getLower(i,K);j<=getUpper(i,K);j+=2)
						{
							int r = i+row, c = j+col;
							if(valid(r,c,size))
							{
								int cInv = 2*size-2 - c;
								int rInv = 2*size-2 - r;
								//A.spr(r+":"+c + " <---> "+rInv+":"+cInv);
								
								if(test(i,cInv-col,K,dia[i][j],dia) &&
									test(rInv-row,j,K,dia[i][j],dia) &&
									test(rInv-row,cInv-col,K,dia[i][j],dia))
									continue;
								//A.spr("Mismatch");
							}
							else
							{
								//A.spr("Placed out of position");
							}
							match = false;
							break;
						}
					}
					ok = match;
				}
			}
			if(ok)
				return size*size - K*K;
		}
		//return -1;
	}
	static boolean test(int r, int c, int s, char ch, char[][] dia)
	{
		return !valid(r,c,s) || dia[r][c]==ch;
	}
	static boolean valid(int r, int c, int s)
	{
		return r>=0 && r<2*s-1 && c>=getLower(r,s) && c<=getUpper(r,s) && (c-getLower(r,s))%2==0;
	}
	static int getLower(int row, int size)
	{
		return size - getMax(row,size);
	}
	static int getUpper(int row, int size)
	{
		return size+getMax(row,size)-1;
	}
	static int getMax(int row, int size)
	{
		if(row < size)
			return row+1;
		return 2*size-row-1;
	}
}
