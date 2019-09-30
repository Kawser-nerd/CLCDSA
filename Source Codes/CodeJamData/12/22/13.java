import java.io.* ;
import java.text.DecimalFormat;
import java.util.*;
import static java.lang.Math.* ;
import static java.util.Arrays.* ;

public class C {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		in = new Scanner(new InputStreamReader(new FileInputStream("c_in.txt")));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream("c_out.txt")));
		
		int n = in.nextInt() ; in.nextLine() ;
		int t = 1 ;
		while( n-- > 0)
			new C().solveProblem(t++);
		
		out.close();
	}

	static Scanner in = new Scanner(new InputStreamReader(System.in));
	static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	

	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	int h, m, n ;
	
	int[] dx = {1,-1,0,0};
	int[] dy = {0,0,1,-1} ;
	
	int[][] lo ;
	int[][] hi ;
	public void solveProblem(int nr) {	
		out.print("Case #" + nr + ": " ) ;
		
		h = in.nextInt() ;
		m = in.nextInt() ;
		n = in.nextInt() ;
		
		lo = new int [m][n] ;
		hi = new int[m][n] ;
		for( int i = 0 ; i < m ; i ++ )
			for( int j = 0 ; j < n ; j++ )
				hi[i][j] = in.nextInt();
		for( int i = 0 ; i < m ; i ++ )
			for( int j = 0 ; j < n ; j++ )
				lo[i][j] = in.nextInt();

		System.err.println("Case #" + nr + " solved") ;
		
		St begin = new St(0,0,0.0) ;
		PriorityQueue<St> qu = new PriorityQueue<St>() ;
		qu.add(begin) ;
		
		boolean[][] done = new boolean[m][n] ;
		double[][] tijd = new double[m][n] ;
		for( int i = 0 ; i < m ; i++ )
			fill(tijd[i],Double.MAX_VALUE) ;
		
		while( !qu.isEmpty()){
			
			St st = qu.poll() ;
			if( done[st.i][st.j] )
				continue ;
			
			done[st.i][st.j] = true ;
			tijd[st.i][st.j] = st.tijd ;
			
			for( int k = 0 ; k < 4 ; k++ ){
				int ni = st.i + dx[k] ;
				int nj = st.j + dy[k] ;
				if( ni == -1 || nj == -1 || ni == m || nj == n )
					continue ;
				
				if( lo[ni][nj] + 50 > hi[ni][nj] || lo[st.i][st.j] + 50 > hi[ni][nj]  || lo[ni][nj] + 50 > hi[st.i][st.j])
					continue ;
				
				double water = h - st.tijd*10. ;
				if( water + 50. > hi[ni][nj])
					water = hi[ni][nj] - 50. ;
				
				double t = 1.0 ;
				if( water < (double) lo[st.i][st.j] + 20. - 1e-9)
					t = 10.0 ;
				if( water > h - 1e-9)
					t = 0.0 ;
				t += (h-water)/10. - st.tijd ;
				if( st.tijd + t < tijd[ni][nj])
					qu.add(new St(ni,nj,st.tijd+t)) ;
				
			}
			
		}
		System.out.println(Arrays.deepToString(tijd));
		out.println(tijd[m-1][n-1]) ;
		
	}
	
	
	class St implements Comparable<St>{
		
		int i, j ;
		double tijd ;
		
		
		public St(int i, int j, double tijd) {
			super();
			this.i = i;
			this.j = j;
			this.tijd = tijd;
		}


		public int compareTo( St o){
			return Double.compare(tijd, o.tijd) ;
		}
		
	}

}