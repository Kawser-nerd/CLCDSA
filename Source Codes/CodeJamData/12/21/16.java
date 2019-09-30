import java.io.* ;
import java.text.DecimalFormat;
import java.util.*;
import static java.lang.Math.* ;
import static java.util.Arrays.* ;

public class A {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		in = new Scanner(new InputStreamReader(new FileInputStream("a_in.txt")));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream("a_out.txt")));
		
		int n = in.nextInt() ; in.nextLine() ;
		int t = 1 ;
		while( n-- > 0)
			new A().solveProblem(t++);
		
		out.close();
	}

	static Scanner in = new Scanner(new InputStreamReader(System.in));
	static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	

	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	
	public void solveProblem(int nr) {	
		out.print("Case #" + nr + ": " ) ;
		
		int n = in.nextInt() ;
		
		double[] p = new double[n] ;
		for( int i = 0 ; i < n ; i++ )
			p[i] = in.nextInt();
		
		double som = 0 ;
		for( double pp : p )
			som += (double) pp ;
				
		for( int i = 0 ; i < n ; i++ ){
			double lo = 0.0 ;
			double hi = 1.;
			
			for( int l = 0 ; l < 500 ; l++ ){
				
				double mid = (lo+hi) / 2.0 ;
				
				double eind = p[i] + mid*som ;
				
				double tot = mid ;
				for( int j = 0 ; j < n ; j++ ){
					if( i == j )
						continue ;
					if( p[j] >= eind - eps )
						continue ;
					
					
					tot += (eind-p[j]) / som ;
				}
				
				if( tot > 1.0 )
					hi = mid ;
				else
					lo = mid ;
				
			}
			
			double ou = (100.0*lo) ;
			if( ou < eps)
				ou = 0.0 ;
			out.print(ou) ;
			if( i == n -1 )
				out.println();
			else
				out.print(" ") ;
		}

		System.err.println("Case #" + nr + " solved") ;
	}
	double eps = 1e-9 ;
	

}