import java.io.*;
import java.util.*;

public class ProblemD {

   int[][] eval;
   ArrayList[] adj;

   public ProblemD() throws Exception {
      Scanner sc = new Scanner(new File("D-small-attempt1.in"));
//      Scanner sc = new Scanner(new File("D-in.txt"));
//      PrintWriter pw = new PrintWriter(System.out);
       PrintWriter pw = new PrintWriter("C:/Documents and Settings/codejam/Desktop/D-small-out.txt");
      int N = Integer.parseInt(sc.nextLine());
      for (int i=1; i<=N; i++) {
         int[] data = parseIntArray(sc.nextLine());
         int R = data[0];
         int C = data[1];
         adj = new ArrayList[R*C];
         for (int r=0; r<R; r++) for (int c=0; c<C; c++) {
            int sq = C*r + c;
            adj[sq] = new ArrayList<Integer>();
            for (int dr=-1; dr<=1; dr++) for (int dc=-1; dc<=1; dc++) {
               if (dr==0 && dc==0) continue;
               int rr = r+dr;
               int cc = c+dc;
               if (rr<0 || rr>=R || cc<0 || cc>=C) continue;
               int sq2 = C*rr + cc;
               adj[sq].add(sq2);
            }
         }
         int state = 0;
         int kingpos = -1;
         for (int r=0; r<R; r++) {
            String line = sc.nextLine();
            for (int c=0; c<C; c++) {
               int sq = C*r + c;
               if (line.charAt(c)=='K') {
                  kingpos = sq;
               } else if (line.charAt(c)=='.') {
                  state |= (1<<sq);
               }
            }
         }
         eval = new int[1<<(R*C)][R*C];
         int res = doit(state, kingpos);
         pw.println("Case #" + (i) + ": "  + ((res==1) ? "A" : "B"));
      }
      pw.flush();
      pw.close();
   }

   int doit(int state, int kingpos) {
      if (eval[state][kingpos] != 0) return eval[state][kingpos];
      return eval[state][kingpos] = doit2(state, kingpos);
   }

   int doit2(int state, int kingpos) {
      ArrayList<Integer> neighbors = adj[kingpos];
      for (int neighbor: neighbors) {
         if (bittest(state, neighbor)) {
            if (doit(removebit(state, neighbor), neighbor) == -1) {
               return 1;
            }
         }
      }
      return -1;
   }

   boolean bittest(int n, int i) {
      return ((n & (1<<i)) != 0);
   }

   int removebit(int n, int i) {
      return (n & ~(1<<i));
   }

   int[] parseIntArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      int[] ret = new int[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = Integer.parseInt(st.nextToken());
      }
      return ret;
   }

   public static void main(String[] args) {
      try {
         new ProblemD();
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}
