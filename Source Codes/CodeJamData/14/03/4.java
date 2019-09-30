import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Minesweeper {
	
	public static void main( String[] args ) throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();
			int RC = R;
			M = R*C - M;
			char[][] ans = new char[R][C];
			boolean isSwapt = false;
			if ( R > C ){
				int t = R; R = C; C = t;
				isSwapt = true;
			}
			int i,j;
			char[][] map = new char[R][C];
			boolean flag = true;
			for ( i = 0 ; i < R ; i++ )
				for ( j = 0 ; j < C ; j++ )
					map[i][j] = '*';
			if ( R == 1 ){
				for ( i = 0 ; i < M ; i++  )
					map[0][i] = '.';
			}
			else {
				if ( M%2 == 1 && R == 2 || ( M%2 == 1 &&  M < 9 ) || M < 4 ){
					flag = false;
					if ( M == 1 )
						flag = true;
				}
				else {
					int m = M;
					if ( M%2 == 1 )
						m -= 3;
					int low = m/2;
					if ( low > C )
						low = C;
					m -= low*2;
					for ( i = 0 ; i < 2 ; i++ )
						for ( j = 0 ; j < low ; j++ )
							map[i][j] = '.';
					
					int x = 2;
					int y = 0;
					if ( C%2 == 1 && M%2 == 1 ){
						map[x][y] = map[x][y+1] = map[x][y+2] = '.';
						y = 3;
					}
					while ( m > 0 ){
						if ( y < C-1 ){
							map[x][y] = map[x][y+1] = '.';
							y += 2;
							m-=2;
						}
						else {
							if ( y == C ){
								y = 0; x++;
								continue;
							}
							if ( map[x-1][y] == '*' ){
								map[x][y] = map[x-1][y] = '.';
								m-=2;
							}
							x += 1; y = 0;
						}

					}
					if ( C%2 == 0 && M%2 == 1 )
						if ( y < C-2 ){
							map[x][y] = map[x][y+1] = map[x][y+2] = '.';
						}
						else {
							map[x+1][0] = map[x+1][1] = map[x+1][2] = '.';
							if ( map[x][2] == '*' ){
								map[x][2] = '.';
								map[x+1][2] = '*';
							}
						}
				}
			}
			map[0][0] = 'c';
			if ( isSwapt ){
				for ( i = 0 ; i < R ; i++ )
					for ( j = 0 ; j < C ; j++ )
						ans[j][i] = map[i][j];
			}
			else {
				for ( i = 0 ; i < R ; i++ )
					for ( j = 0 ; j < C ; j++ )
						ans[i][j] = map[i][j];
			}
			bw.write("Case #" + z + ":\n");
			if ( !flag ){
				bw.write("Impossible\n");
			}
			else {
				for ( i = 0 ; i < RC ; i++ ){
					bw.write(ans[i]);
					bw.write("\n");
				}
			}
		}
		sc.close();
		bw.close();
	}

}
