package googlecodejam;

import java.io.*;
import java.util.*;

public class ProblemC {
   
   public static void main(String[] args) {
      try {
         Scanner s = new Scanner(new File("C-small-attempt0.in"));
         PrintWriter p = new PrintWriter("C-small0.out.txt");
         int C = Integer.parseInt(s.nextLine());
         for (int i=1; i<=C; i++) {
            int[] data = parseIntArray(s.nextLine());
            int nRows = data[0];
            int nCols = data[1];
            int[] broken = new int[nRows];
            for (int r=0; r<nRows; r++) {
               broken[r] = 0;
               String row = s.nextLine();
               for (int c=0; c<nCols; c++) {
                  if (row.charAt(c)=='x') {
                     broken[r] |= (1<<c);
                  }
               }
            }
            int[][] ans = new int[nRows][1<<nCols];
            for (int r=0; r<nRows; r++) {
               for (int b=0; b<(1<<nCols); b++) {
                  ans[r][b] = 0;
                  if ((b & broken[r]) != 0) continue;
                  int B = b;
                  boolean ok = true;
                  while (B > 0) {
                     if (B%4==3) ok = false;
                     B/=2;
                  }
                  if (!ok) continue;
                  if (r==0) {
                     ans[r][b] = bitcount(b);
                     continue;
                  }
                  int forbidden = (b<<1) | (b>>1);
                  for (int bb=0; bb<(1<<nCols); bb++) {
                     if ((bb & forbidden) == 0) {
                        ans[r][b] = Math.max(ans[r][b], bitcount(b) + ans[r-1][bb]);
                     }
                  }
               }
            }
            int best = 0;
            for (int b=0; b<(1<<nCols); b++) best = Math.max(best, ans[nRows-1][b]);
            p.println("Case #" + (i) + ": " + best);
         }
         p.flush();
         p.close();
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
   static int bitcount(int n) {
      int ret=0;
      while (n>0) {
         if (n%2==1) ret++;
         n/=2;
      }
      return ret;
   }
   static int[] parseIntArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      int[] ret = new int[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = Integer.parseInt(st.nextToken());
      }
      return ret;
   }
}
