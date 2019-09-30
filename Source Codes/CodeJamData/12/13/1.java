import java.util.* ;
import java.math.* ;
import java.io.* ;
public class c {
    public static class R implements Comparable {
	public R(long num_, long den_) {
	    num = num_ ;
	    den = den_ ;
	    if (den < 0) {
		num = - num ;
		den = - den ;
	    }
	}
	public int compareTo(Object o) {
	    if (!(o instanceof R))
		return 0 ;
	    R b = (R)o ;
	    long disc = num * b.den - den * b.num ;
	    if (disc > 0)
		return 1 ;
	    if (disc < 0)
		return -1 ;
	    return 0 ;
	}
	public R muladd(int p, int s) {
	    return new R(p * den + s * num, den) ;
	}
	public String toString() {
	    return "" + num + "/" + den ;
	}
	long num, den ;
    }
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
      String s = br.readLine() ;
      int kases = Integer.parseInt(s) ;
      int INF = 1000000 ;
      for (int kase=1; kase<=kases; kase++) {
	  s = br.readLine() ;
	  int N = Integer.parseInt(s) ;
	  int lane[] = new int[N] ;
	  int v[] = new int[N] ;
	  int p[] = new int[N] ;
	  for (int i=0; i<N; i++) {
	      s = br.readLine() ;
	      String[] f = s.split(" ") ;
	      lane[i] = (f[0].charAt(0) == 'L' ? 0 : 1) ;
	      v[i] = Integer.parseInt(f[1]) ;
	      p[i] = Integer.parseInt(f[2]) ;
	  }
	  ArrayList times = new ArrayList() ;
	  times.add(new R(0, 1)) ;
	  for (int i=0; i<N; i++)
	      for (int j=0; j<N; j++)
		  if (i != j) {
		      // when does the front of car i intercept the
		      // back of car b?
		      int dist = p[j] - (p[i] + 5) ;
		      int speed = v[i] - v[j] ;
		      if (speed != 0) {
			  times.add(new R(dist, speed)) ;
		      }
		  }
	  Collections.sort(times) ;
	  int SZ = 1<<N ;
	  boolean possib[] = new boolean[SZ] ;
	  int st = 0 ;
	  for (int i=0; i<N; i++)
	      st |= lane[i]<<i ;
	  possib[st] = true ;
	  R oldC = new R(-1000, 1) ;
	  String rs = null ;
	  for (int tt=0; tt<times.size(); tt++) {
	      R c = (R)times.get(tt) ;
	      if (c.num < 0)
		  continue ; // ignore negative times
	      if (c.compareTo(oldC) == 0)
		  continue ;
	      oldC = c ;
	      R[] posb = new R[N] ;
	      R[] posf = new R[N] ;
	      for (int i=0; i<N; i++) {
		  posb[i] = c.muladd(p[i], v[i]) ;
		  posf[i] = c.muladd(p[i]+5, v[i]) ;
	      }
	      boolean t[][] = new boolean[N][N] ;
	      boolean fix[] = new boolean[N] ;
	      boolean ms[][] = new boolean[N][N] ;
	      for (int i=0; i<N; i++) {
		  for (int j=i+1; j<N; j++) {
		      // characterize:
		      //   no conflict
		      //   conflict
		      //   coming into conflict
		      //   escaping out of conflict
		      int fb = posf[i].compareTo(posb[j]) ;
		      int bf = posb[i].compareTo(posf[j]) ;
		      if (fb < 0 || bf > 0) { // unrelated
		      } else if (fb > 0 && bf < 0) {
			  t[i][j] = t[j][i] = true ;
			  ms[i][j] = ms[j][i] = true ;
			  fix[i] = fix[j] = true ;
		      } else if (fb == 0) {
			  if (v[i] > v[j])
			      ms[i][j] = ms[j][i] = true ;
		      } else if (bf == 0) {
			  if (v[i] < v[j])
			      ms[i][j] = ms[j][i] = true ;
		      } else {
			  throw new Exception("Unexpected") ;
		      }
		  }
	      }
	      /* expand the output according to the ones that can move */
	      /* use relaxation */
	      while (true) {
		  boolean changed = false ;
		  for (int i=0; i<SZ; i++)
		      for (int j=0; j<N; j++)
			  if (!fix[j] && possib[i] && !possib[i^(1<<j)]) {
			      possib[i^(1<<j)] = true ;
			      changed = true ;
			  }
		  if (!changed)
		      break ;
	      }
	      /* kill the ones that are touching or will soon */
	      for (int i=0; i<SZ; i++)
		  for (int j=0; j<N; j++)
		      for (int k=j+1; k<N; k++) {
			  if (((((i >> j) ^ (i >> k)) & 1) == 0 &&
			       ms[j][k])) {
			      possib[i] = false ;
			  }
		      }
	      /* is anything still possible? */
	      int r = 0 ;
	      for (int i=0; i<SZ; i++)
		  if (possib[i])
		      r++ ;
	      if (r == 0) {
		  rs = "" + (c.num / (double)c.den) ;
		  break ;
	      }
	  }
	  if (rs == null)
	      rs = "Possible" ;
	  System.out.println("Case #" + kase + ": " + rs) ;
      }
    }
}
