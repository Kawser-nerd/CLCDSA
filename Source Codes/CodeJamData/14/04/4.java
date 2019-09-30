import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class War {


	public static void main( String[] args ) throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			double[] nami = new double[n];
			double[] ken = new double[n];
			int i,j;
			for ( i = 0 ; i < n ; i++ )
				nami[i] = sc.nextDouble();
			for ( i = 0 ; i < n ; i++ )
				ken[i] = sc.nextDouble();
			for ( i = 0 ; i < n ; i++ )
				for ( j = i+1 ; j < n ; j++ ){
					double t;
					if ( nami[i] > nami[j] ){
						t = nami[i]; nami[i] = nami[j]; nami[j] = t;
					}
					if ( ken[i] > ken[j] ){
						t = ken[i]; ken[i] = ken[j]; ken[j] = t;
					}
				}
			int q1 = 0;
			int q2 = n-1;
			int ans1 = 0;
			for ( i = 0 ; i < n ; i++ )
				if ( nami[i] > ken[q1] ){
					ans1++;
					q1++;
				}
				else {
					q2--;
				}
			int ans2 = 0;
			q1 = 0;
			for ( i = 0 ; i < n ; i++ ){
				while ( q1 < n && ken[q1] < nami[i] )
					q1++;
				if ( q1 == n )
					break;
				ans2++;
				q1++;
			}
			bw.write("Case #" + z + ": ");
			bw.write("" + ans1 + " " + (n-ans2) + "\n");
		}
		sc.close();
		bw.close();
	}

}
