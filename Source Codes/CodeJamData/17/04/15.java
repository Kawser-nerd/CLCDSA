import java.util.Arrays ;
import java.util.Scanner ;
public class d {
   static final int BIG = 1000000000 ;
   static int[][] maxflow(int[][] g) {
      int n = g.length ;
      int[][] flow = new int[n][n] ;
      int prev[] = new int[n] ;
      int min[] = new int[n] ;
      while (true) {
         Arrays.fill(prev, -1) ;
         Arrays.fill(min, BIG) ;
         min[0] = 0 ;
         while (true) {
            boolean changed = false ;
            for (int i=0; i<n; i++)
               for (int j=0; j<n; j++)
                  if (flow[i][j] < g[i][j] && min[j] > min[i] + 1) {
                     changed = true ;
                     min[j] = min[i] + 1 ;
                     prev[j] = i ;
                  }
            if (!changed)
               break ;
         }
         if (min[n-1] == BIG)
            return flow ;
         int maxflow = BIG ;
         int j ;
         for (int i=n-1; (j=prev[i])>=0; i=j)
            maxflow = Math.min(maxflow, g[j][i] - flow[j][i]) ;
         for (int i=n-1; (j=prev[i])>=0; i=j) {
            flow[j][i] += maxflow ;
            flow[i][j] -= maxflow ;
         }
      }
   }
   static int fastminmatch(int[][] a) {
      int n = a.length ;
      int nn = 2*n + 2 ;
      int[][] g = new int[nn][nn] ;
      int[][] c = new int[nn][nn] ;
      for (int i=0; i<n; i++) {
         g[0][i+1] = 1 ;
         c[0][i+1] = 0 ;
         g[n+i+1][1+2*n] = 1 ;
         c[n+i+1][1+2*n] = 0 ;
      }
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++) {
            g[i+1][n+j+1] = 1 ;
            c[i+1][n+j+1] = a[i][j] ;
            c[n+j+1][i+1] = -a[i][j] ;
         }
      int[][] f = maxflow(g) ;
      int r = 0 ;
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++)
            if (f[i+1][n+j+1] > 0)
               r += a[i][j] ;
      return r ;
   }
   static void solveit(Scanner sc) throws Exception {
      int N = sc.nextInt() ;
      int M = sc.nextInt() ;
      char[][] b = new char[N][N] ;
      boolean rows[] = new boolean[N] ;
      boolean cols[] = new boolean[N] ;
      boolean diags[] = new boolean[2*N-1] ;
      boolean diagd[] = new boolean[2*N-1] ;
      int seendiags = 0 ;
      for (int i=0; i<M; i++) {
         char c = sc.next().charAt(0) ;
         int ci = sc.nextInt() - 1 ;
         int ri = sc.nextInt() - 1 ;
         if (c == 'o')
            b[ri][ci] = 3 ;
         else if (c == 'x')
            b[ri][ci] = 1 ;
         else if (c == '+')
            b[ri][ci] = 2 ;
         else
            throw new Exception("Bad char") ;
         if ((b[ri][ci] & 1) != 0) {
            if (rows[ri] || cols[ci])
               throw new Exception("Conflict on ortho") ;
            rows[ri] = true ;
            cols[ci] = true ;
         }
         if ((b[ri][ci] & 2) != 0) {
            if (diags[ri+ci] || diagd[ri-ci+N-1])
               throw new Exception("Conflict on diag") ;
            diags[ri+ci] = true ;
            diagd[ri-ci+N-1] = true ;
            seendiags++ ;
         }
      }
      {
         int i = 0 ;
         int j = 0 ;
         while (i < N && j < N) {
            while (i < N && rows[i])
               i++ ;
            while (j < N && cols[j])
               j++ ;
            if (i < N && j < N)
               b[i][j] |= 4 ;
            i++ ;
            j++ ;
         }
      }
      int freediags = 2 * N - 1 - seendiags ;
      if (freediags > 0) {
         int mapdsf[] = new int[2*N-1] ;
         int mapddf[] = new int[2*N-1] ;
         int ats=0, atd=0 ;
         for (int i=0; i<2*N-1; i++) {
            if (!diags[i])
               mapdsf[i] = ats++ ;
            if (!diagd[i])
               mapddf[i] = atd++ ;
         }
         int gn = 2 * freediags + 2 ;
         int[][] g = new int[gn][gn] ;
         for (int i=0; i<freediags; i++) {
            g[0][1+i] = 1 ;
            g[freediags+1+i][gn-1] = 1 ;
         }
         for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
               if (!diags[i+j] && !diagd[i-j+N-1]) {
                  int src = mapdsf[i+j] ;
                  int dst = mapddf[i-j+N-1] ;
                  g[1+src][freediags+1+dst] = 1 ;
               }
         int[][] f = maxflow(g) ;
         for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
               if (!diags[i+j] && !diagd[i-j+N-1]) {
                  int src = mapdsf[i+j] ;
                  int dst = mapddf[i-j+N-1] ;
                  if (f[1+src][freediags+1+dst] > 0) {
                     b[i][j] |= 8 ;
                  }
               }
      }
      int changed = 0 ;
      int score = 0 ;
      for (int i=0; i<N; i++)
         for (int j=0; j<N; j++)
            if (b[i][j] != 0) {
               if ((b[i][j] & 12) != 0)
                  changed++ ;
               int t = b[i][j] ;
               while (t > 0) {
                  score++ ;
                  t &= t - 1 ;
               }
            }
      System.out.println("" + score + " " + changed) ;
      for (int i=0; i<N; i++) {
         for (int j=0; j<N; j++) {
            if ((b[i][j] & 12) != 0) {
               int t = ((b[i][j] >> 2) | b[i][j]) & 3 ;
               if (t == 3) {
                  System.out.println("o " + (j+1) + " " + (i+1)) ;
               } else if (t == 2) {
                  System.out.println("+ " + (j+1) + " " + (i+1)) ;
               } else {
                  System.out.println("x " + (j+1) + " " + (i+1)) ;
               }
            }
         }
      }
   }
   public static void main(String[] args) throws Exception {
      Scanner sc = new Scanner(System.in) ;
      int T = sc.nextInt() ;
      for (int kase=1; kase<=T; kase++) {
         System.out.print("Case #" + kase + ": ") ;
         solveit(sc) ;
      }
   }
}
