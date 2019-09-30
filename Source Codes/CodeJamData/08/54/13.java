package googlecodejam;

import java.io.*;
import java.util.*;

public class ProblemD {
   public static void main(String[] args) {
      try {
         int MOD = 10007;
         Scanner s = new Scanner(new File("D-small-attempt0.in"));
         PrintWriter p = new PrintWriter(new File("D-small0.txt"));
         int N = Integer.parseInt(s.nextLine());
         for (int i=1; i<=N; i++) {
            int[] data = parseIntArray(s.nextLine());
            int H = data[0];
            int W = data[1];
            int R = data[2];
            int[] rr = new int[R];
            int[] rc = new int[R];
            for (int j=0; j<R; j++) {
               data = parseIntArray(s.nextLine());
               rr[j] = data[0]; rc[j] = data[1];
            }
            int[][] count = new int[128][128];
            for (int r=1; r<=H; r++) {
               for (int c=1; c<=W; c++) {
                  if (r==1 && c==1) { 
                     count[r][c] = 1; continue;
                  }
                  boolean isRock = false;
                  for (int k=0; k<R; k++) {
                     if (rr[k]==r && rc[k]==c) isRock = true;
                  }
                  if (isRock) { count[r][c] = 0; continue; }
                  count[r][c] = 0;
                  if (r-1>=1 && c-2>=1) count[r][c] += count[r-1][c-2];
                  count[r][c] %= MOD;
                  if (r-2>=1 && c-1>=1) count[r][c] += count[r-2][c-1];
                  count[r][c] %= MOD;
               }
            }
            p.println("Case #" + (i) + ": " + count[H][W]);
         }
         p.flush();
         p.close();
      } catch (Exception e) {
         e.printStackTrace();
      }
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
