import java.math.* ;
import java.io.* ;
public class p {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
      String s = br.readLine() ;
      int kases = Integer.parseInt(s) ;
      int INF = 1000000 ;
      for (int kase=1; kase<=kases; kase++) {
	  s = br.readLine() ;
	  int N = Integer.parseInt(s) ;
	  int a[] = new int[N] ;
	  int b[] = new int[N] ;
	  for (int i=0; i<N; i++) {
	      s = br.readLine() ;
	      String[] f = s.split(" ") ;
	      a[i] = Integer.parseInt(f[0]) ;
	      b[i] = Integer.parseInt(f[1]) ;
	  }
	  int pts = 0 ;
	  int wk = 0 ;
	  while (pts < 2 * N) {
	      int good = 0 ;
	      for (int i=0; i<N; i++) {
		  if (b[i] <= pts) {
		      wk++ ;
		      good++ ;
		      if (a[i] == INF) {
			  pts++ ;
		      } else {
			  pts += 2 ;
		      }
		      b[i] = INF ;
		      a[i] = INF ;
		  }
	      }
	      if (good == 0) {
		  int high = -1 ;
		  for (int i=0; i<N; i++) {
		      if (a[i] <= pts &&
			  (high < 0 || b[i] > b[high])) {
			  high = i ;
		      }
		  }
		  if (high >= 0) {
		      wk++ ;
		      pts++ ;
		      good++ ;
		      a[high] = INF ;
		  }
	      }
	      if (good == 0)
		  break ;
	  }
	  if (pts == 2 * N) {
	      System.out.println("Case #" + kase + ": " + wk) ;
	  } else {
	      System.out.println("Case #" + kase + ": " + "Too Bad") ;
	  }
      }
    }
}
