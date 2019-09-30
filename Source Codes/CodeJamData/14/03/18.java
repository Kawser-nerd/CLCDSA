import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Exe3 {
	public static void main (String[] args) throws Exception
	{
		Scanner input = new Scanner(new File("input"));
		BufferedWriter output = new BufferedWriter(new FileWriter(new File("output")));
		int T = input.nextInt();
		for ( int i = 0; i<T ; i++)
		{
			int R = input.nextInt();
			int C = input.nextInt();
			int M = input.nextInt();
			char[][] matrix = new char[R][C];
			int free = R*C - M;
			boolean possible = true;
			boolean stupid = false;
			
			for ( int j = 0; j < R; j++)
			{
				for ( int k = 0; k<C; k++)
				{
					matrix[j][k] = '*';
				}
			}
			if ( M == 0 || free == 1)
			{
				stupid = true;
				if ( M == 0 || M == 1)
				{
					for ( int j = 0; j < R; j++)
					{
						for ( int k = 0; k<C; k++)
						{
							matrix[j][k] = '.';
						}
					}
				}
			}
			
			if ( ! stupid)
			{
				if ( C == 1 || R == 1)
				{
					if ( C == 1)
					{
						for ( int j = 0; j < free; j++)
						{
							matrix[j][0] = '.';
						}
					}
					else
					{
						for ( int j = 0; j < free; j++)
						{
							matrix[0][j] = '.';
						}
					}
				}
				else if ( C == 2 || R == 2 )
				{
					if ( free%2 == 1 || free == 2)
					{
						possible = false;
					}
					else
					{
						if ( C == 2 )
						{
							for ( int j = 0; j < free/2; j++)
							{
								matrix[j][0] = '.';
								matrix[j][1] = '.';
							}
						}
						else
						{
							for ( int j = 0; j < free/2; j++)
							{
								matrix[0][j] = '.';
								matrix[1][j] = '.';
							}
						}
					}
				}
				else if ( C == 3 || R == 3 )
				{
					if ( free == 2 || free == 3 || free == 5 || free == 7)
					{
						possible = false;
					}
					else
					{
						matrix[0][1] = '.';
						matrix[1][0] = '.';
						matrix[1][1] = '.';
						free = free - 4;
						if ( R == 3)
						{
							matrix[0][2] = '.';
							matrix[1][2] = '.';
							free = free -2;
							int j = 2;
							while ( free > 0 )
							{
								if ( free > 1)
								{
									matrix[j][0] = '.';
									matrix[j][1] = '.';
									free = free - 2;
								}
								else
								{
									matrix[2][2] = '.';
									free = free - 1;
								}
							}
						}
						else
						{
							matrix[2][0] = '.';
							matrix[2][1] = '.';
							free = free -2;
							int j = 2;
							while ( free > 0 )
							{
								if ( free > 1)
								{
									matrix[0][j] = '.';
									matrix[1][j] = '.';
									free = free - 2;
								}
								else
								{
									matrix[2][2] = '.';
									free = free - 1;
								}
							}
						}
						
					}
				}
				else if ( C > 3 && R > 3)
				{
					if ( free == 2 || free == 3 || free == 5 || free == 7)
					{
						possible = false;
					}
					else
					{
						matrix[0][1] = '.';
						matrix[1][0] = '.';
						matrix[1][1] = '.';
						free = free - 4;
						boolean mannaggiaddio = false;
						if ( free%2 == 1 )
						{
							matrix[2][2] = '.';
							mannaggiaddio = true;
							free --;
						}
						int c = 2;
						int r = 2;
						while( free != 0 && c < C && r < R)
						{
							matrix[0][c] = '.';
							matrix[1][c] = '.';
							free -= 2;
							c++;
							if ( free > 0)
							{
								matrix[r][0] = '.';
								matrix[r][1] = '.';
								free -= 2;
								r++;
							}
						}
						if ( free > 0)
						{
							if ( r == R)
							{
								while ( free != 0 && c < C)
								{
									matrix[0][c] = '.';
									matrix[1][c] = '.';
									free -= 2;
									c++;
								}
							}
							if ( c == C)
							{
								while ( free != 0 && r < R)
								{
									matrix[r][0] = '.';
									matrix[r][1] = '.';
									free -= 2;
									r++;
								}
							}
							for ( int j = 2; j < R && free > 0; j++)
							{
								for ( int k = 2; k < C && free > 0; k++)
								{
									matrix[j][k] = '.';
									free --;
									if ( j == 2 && k == 2 && mannaggiaddio)
									{
										free++;
									}
								}
							}
						}
						
					}
				}
			}

			matrix[0][0] = 'c';
			output.write("Case #"+(i+1)+":");
			output.newLine();
			if ( !possible )
			{
				output.write("Impossible");
				output.newLine();
			}
			else
			{
				for ( int j = 0; j < R; j++)
				{
					for( int k = 0; k < C; k++)
					{
						output.append(matrix[j][k]);
					}
					output.newLine();
				}
			}
			output.flush();
		}
		output.flush();
		input.close();
		output.close();
	}
}


