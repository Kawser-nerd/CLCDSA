import java.math.* ;
import java.io.* ;
public class p {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
      String s = br.readLine() ;
      int kases = Integer.parseInt(s) ;
      for (int kase=1; kase<=kases; kase++) {
	  s = br.readLine() ;
	  String[] f = s.split(" ") ;
	  int A = Integer.parseInt(f[0]) ;
	  int B = Integer.parseInt(f[1]) ;
	  s = br.readLine() ;
	  f = s.split(" ") ;
	  double p[] = new double[A] ;
	  for (int i=0; i<A; i++)
	      p[i] = Double.parseDouble(f[i]) ;
	  double r = B + 2 ;
	  double p2[] = new double[A] ;
	  p2[0] = p[0] ;
	  for (int i=1; i<A; i++)
	      p2[i] = p2[i-1] * p[i] ;
	  for (int bs=0; bs<A; bs++) {
	      double t = p2[A-bs-1] * (2 * bs + B - A + 1) +
		  (1-p2[A-bs-1]) * (2 * bs + B - A + B + 2) ;
	      if (t < r)
		  r = t ;
	  }
	  System.out.println("Case #" + kase + ": " + r) ;
      }
    }
}
