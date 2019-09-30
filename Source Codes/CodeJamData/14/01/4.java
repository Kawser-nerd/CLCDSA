import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class MagicTrick {

	public void magic() throws IOException {
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int[][] map1 = new int[4][4];
			int[][] map2 = new int[4][4];
			int i,j;
			int r1, r2;
			r1 = sc.nextInt()-1;
			for ( i = 0 ; i < 4 ; i++ )
				for ( j = 0 ;j < 4 ; j++ )
					map1[i][j] = sc.nextInt();
			r2 = sc.nextInt()-1;
			for ( i = 0 ; i < 4 ; i++ )
				for ( j = 0 ;j < 4 ; j++ )
					map2[i][j] = sc.nextInt();
			int ans = 0;
			int sameNum = 0;
			for ( i = 0 ; i < 4 ; i++ )
				for ( j = 0 ; j < 4 ; j++ )
					if ( map1[r1][i] == map2[r2][j] ){
						sameNum++;
						ans = map1[r1][i];
					}
			bw.write("Case #" + z + ": " );
			if ( sameNum == 0 )
				bw.write("Volunteer cheated!");
			else if ( sameNum == 1 )
				bw.write(""+ans);
			else bw.write("Bad magician!");
			bw.write("\n");
		}
		bw.close();
		sc.close();
	}

}
