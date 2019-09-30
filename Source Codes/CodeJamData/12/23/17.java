import java.io.* ;
import java.text.DecimalFormat;
import java.util.*;
import static java.lang.Math.* ;
import static java.util.Arrays.* ;

public class B {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		in = new Scanner(new InputStreamReader(new FileInputStream("b_in.txt")));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream("b_out.txt")));
		
		int n = in.nextInt() ; in.nextLine() ;
		int t = 1 ;
		while( n-- > 0)
			new B().solveProblem(t++);
		
		out.close();
	}

	static Scanner in = new Scanner(new InputStreamReader(System.in));
	static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	

	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	
	public void solveProblem(int nr) {	
		out.println("Case #" + nr + ": " ) ;
		
		int n = in.nextInt() ;
		
		long[] g = new long[n] ;
		for( int i = 0 ; i < n ; i++ )
			g[i] = in.nextLong();
		
		HashMap<Long,Integer> map = new HashMap<Long, Integer>() ;
		for( int i = 1 ; i < (1<<n) ; i++ ){
			
			long som = 0 ;
			for( int j = 0 ; j < n ; j++ ){
				som += ((1<<j) & i ) > 0 ? g[j] : 0 ;
			}
			
			if( map.containsKey(som)){
				String ou = "" ;
				for( int j = 0 ; j < n ; j++ ){
					if( ((1<<j) & i ) > 0 ){
						ou += g[j] + " " ;
 					}
				}
				
				out.println(ou.trim()) ;
				ou = "" ;
				for( int j = 0 ; j < n ; j++ ){
					if( ((1<<j) & map.get(som) ) > 0 ){
						ou += g[j] + " " ;
 					}
				}
				
				out.println(ou.trim()) ;
				return ;
			}
			
			map.put(som, i) ;
		}
		
		out.println("impossible") ;
		
		

		System.err.println("Case #" + nr + " solved") ;
	}
	

}