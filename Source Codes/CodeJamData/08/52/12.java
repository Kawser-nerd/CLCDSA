package googlecodejam;

import java.io.*;
import java.util.*;

public class ProblemB {
   static final int INF = 123456789;
   static int[] dr = new int[] { 0, 1, 0, -1 };
   static int[] dc = new int[] { 1, 0, -1, 0 };
   public static void main(String[] args) {
      try {
         Scanner s = new Scanner(new File("B-small-attempt0.in"));
         PrintWriter p = new PrintWriter(new File("B-small-out.txt"));
         int nCases = Integer.parseInt(s.nextLine());
         for (int i=1; i<=nCases; i++) {
            int[] data = parseIntArray(s.nextLine());
            int nRows = data[0];
            int nCols = data[1];
            char[][] map = new char[nRows][nCols];
            int posR=-1, posC=-1;
            for (int r=0; r<nRows; r++) {
               String row = s.nextLine();
               for (int c=0; c<nCols; c++) {
                  map[r][c] = row.charAt(c);
                  if (map[r][c]=='O') {
                     posR = r;
                     posC = c;
                  }
               }
            }
            GooglyPriorityQueue q = new GooglyPriorityQueue(nRows*nCols*nRows*nCols*4);
            // the state is: where you are, where the output portal is
            int[][][][] best = new int[nRows][nCols][nRows][nCols];
            
            // shoot gun west to create a blue portal
            int gr = posR;
            int gc = posC;
            while (gc>=0 && (map[gr][gc]=='.' || map[gr][gc]=='O')) gc--;
            gc++;
            
            for (int a=0; a<nRows; a++) {
               for (int b=0; b<nCols; b++) {
                  for (int c=0; c<nRows; c++) {
                     for (int d=0; d<nCols; d++) {
                        best[a][b][c][d] = INF;
                     }
                  }
               }
            }
            best[posR][posC][gr][gc] = 0;
            q.insert(0, new int[] { posR, posC, gr, gc });
            int ans = INF;
            while (!q.isEmpty()) {
               data = (int[])q.removeMin();
               int r = data[0];
               int c = data[1];
               int pr = data[2];
               int pc = data[3];
               int val = best[r][c][pr][pc];
               if (map[r][c]=='X') {
                  ans = val;
                  break;
               }
               // Move
               for (int dir=0; dir<4; dir++) {
                  int rr = r+dr[dir];
                  int cc = c+dc[dir];
                  if (rr>=0 && rr<nRows && cc>=0 && cc<nCols && map[rr][cc]!='#') {
                     if (1+val < best[rr][cc][pr][pc]) {
                        best[rr][cc][pr][pc] = 1+val;
                        q.insert(1+val, new int[] { rr, cc, pr, pc });
                     }
                  } else {
                     // walk through portal
                     if (1+val < best[pr][pc][pr][pc]) {
                        best[pr][pc][pr][pc] = 1+val;
                        q.insert(1+val, new int[] { pr, pc, pr, pc });
                     }
                  }
               }
               // Shoot a output portal
               
               for (int dir=0; dir<4; dir++) {
                  gr = r;
                  gc = c;
                  while (gr>=0 && gr<nRows && gc>=0 && gc<nCols && (map[gr][gc]!='#')) {
                     gr += dr[dir];
                     gc += dc[dir];
                  }
                  gr -= dr[dir];
                  gc -= dc[dir];
                  if (val < best[r][c][gr][gc]) {
                     best[r][c][gr][gc] = val;
                     q.insert(val, new int[] { r, c, gr, gc });
                  }
               }
            }
            //String line = s.nextLine();
            if (ans==INF) {
               p.println("Case #" + (i) + ": THE CAKE IS A LIE");
            } else {
               p.println("Case #" + (i) + ": " + ans);
            }
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
   static    class GooglyPriorityQueue {
      int N;
      int size;
      Object[] data;
      int[] keys;
      public GooglyPriorityQueue(int n) {
         N = n;
         size = 0;
         data = new Object[N+1];
         keys = new int[N+1];
         keys[0] = Integer.MIN_VALUE;
      }
      public void insert(int key, Object o) {
         if (size == N) {
            System.out.println("Resizing heap to " + (2*N) + " !");
            Object[] data2 = new Object[2*N+1];
            int[] keys2 = new int[2*N+1];
            System.arraycopy(data, 0, data2, 0, N+1);
            System.arraycopy(keys, 0, keys2, 0, N+1);
            N = 2*N;
            data = data2;
            keys = keys2;
         }
         int k = ++size;
         while (keys[k/2] > key) {
            data[k] = data[k/2];
            keys[k] = keys[k/2];
            k /= 2;
         }
         data[k] = o;
         keys[k] = key;
      }
      public boolean isEmpty() {
         return (size==0);
      }
      public Object removeMin() {
         if (isEmpty()) {
            throw new RuntimeException("Heap is empty!");
         }
         Object ret = data[1];
         Object lastObj = data[size];
         int lastKey = keys[size];
         size--;
         int k = 1;
         while ((2*k<=size && lastKey > keys[2*k]) || (2*k+1<=size && lastKey > keys[2*k+1])) {
            int j = 2*k;
            if (j+1<=size && keys[j+1] < keys[j]) j++;
            keys[k] = keys[j];
            data[k] = data[j];
            k = j;
         }
         keys[k] = lastKey;
         data[k] = lastObj;
         return ret;
      }
   }
}

