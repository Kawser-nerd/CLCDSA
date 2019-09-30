import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception
	{
		new B();
	}

	final int oo = (int) 1e9;

	int R, C;
	int[][] E = new int[100][100];
	char[][] L = new char[100][100];

	B() throws Exception
	{
		Scanner in = new Scanner(System.in);
		for (int T = in.nextInt(), ds = 1; T-- > 0; ++ds)
		{
			R = in.nextInt();
			C = in.nextInt();
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
				{
					E[i][j] = in.nextInt();
					L[i][j] = 0;
				}

			char sink = 'a';
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
					if (L[i][j] == 0)
					{
						char c = getLetter(i, j, (char) 0);
						if (c == 0)
							getLetter(i, j, sink++);
					}

			System.out.printf("Case #%d:%n", ds);
			for (int i = 0; i < R; ++i, System.out.println())
				for (int j = 0; j < C; ++j)
					System.out.printf("%c ", L[i][j]);
		}
	}

	int[] dr = { -1, 0, 0, 1 }, dc = { 0, -1, 1, 0 };

	char getLetter(int r, int c, char ch)
	{
		if (L[r][c] > 0)
			return L[r][c];

		int min = oo;
		int minD = -1;
		for (int d = 0; d < 4; ++d)
		{
			int nr = r + dr[d], nc = c + dc[d];
			if (ok(nr, nc))
				if (E[nr][nc] < E[r][c] && E[nr][nc] < min)
				{
					min = E[nr][nc];
					minD = d;
				}
		}

		if (min < oo)
		{
			char ret = getLetter(r + dr[minD], c + dc[minD], ch);
			L[r][c] = ret;
			return ret;
		}
		
		L[r][c] = ch;
		return ch;
	}

	boolean ok(int r, int c)
	{
		return r >= 0 && r < R && c >= 0 && c < C;
	}

}
