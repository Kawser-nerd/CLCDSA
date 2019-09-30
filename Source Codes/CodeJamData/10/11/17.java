import java.util.*;


public class Rotate
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			System.out.print("Case #"+i+": ");
			solveCase();
		}
	}
	static void solveCase()
	{
		int N = sc.nextInt(); int K = sc.nextInt();
		char[][] ch = new char[N][N];
		for(int i=0;i<N;i++)
		{
			String str = sc.next();
			for(int j=0;j<N;j++)
				ch[j][N-i-1] = str.charAt(j);
		}
		for(int j=0;j<N;j++)
		{
			for(int i=N-1,empty=0;i>=0;i--)
			{
				if(ch[i][j]=='.')
					empty++;
				else if(empty>0)
				{
					ch[i+empty][j] = ch[i][j];
					ch[i][j] = '.';
				}
			}
		}
		boolean blue = false, red = false;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!blue)
					blue = check(ch, i, j, K, 'B');
				if(!red)
					red = check(ch, i, j, K, 'R');
			}
		}
		String res;
		if(blue && red)
			res = "Both";
		else if(blue)
			res = "Blue";
		else if(red)
			res = "Red";
		else
			res = "Neither";
		System.out.println(res);
	}
	static boolean check(char[][] ch, int r, int c, int len, char x)
	{
		int n = ch.length;
		boolean row = r+len<=n, col = c+len<=n, prim = row&&col, sec = row&&c+1>=len;
		for(int i=0;i<len;i++)
		{
			if(row)
				row = ch[r+i][c] == x;
			if(col)
				col = ch[r][c+i] == x;
			if(prim)
				prim = ch[r+i][c+i] == x;
			if(sec)
				sec = ch[r+i][c-i] == x;
		}
		return row||col||prim||sec;
	}
}
