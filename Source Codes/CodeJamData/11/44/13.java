import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int tc = in.nextInt ();
    for (int tt = 1; tt <= tc; tt++) {
      int P = in.nextInt ();
      int W = in.nextInt ();

      ArrayList <Integer> [] S = new ArrayList[P];
      for (int i = 0; i < P; i++) {
        S[i] = new ArrayList <Integer> ();
      }

      int dq;
      for (dq = 1; dq * 32 < P; dq++);
      int [][] D = new int [P][dq];

      for (int i = 0; i < W; i++) {
        String s = in.next ();
        Scanner z = new Scanner (s).useDelimiter (",");
        int x = z.nextInt ();
        int y = z.nextInt ();
        S[x].add (y);
        S[y].add (x);
        D[x][y >> 5] |= (1 << (y & 31));
        D[y][x >> 5] |= (1 << (x & 31));
      }

      boolean [] F = new boolean [P];
      int [] Q = new int [P], L = new int [P];
      int Qh = 0, Qt = 1;
      F[0] = true;

      Arrays.fill (L, P + 239);
      L[0] = 0;

      while (Qh < Qt) {
        int v = Q[Qh++], vl = L[v];
        for (int s : S[v])
          if (!F[s]) {
            Q[Qt++] = s;
            L[s] = vl + 1;
            F[s] = true;
          }
      }

      int ans = 0;

      if (L[1] == 1) {
        for (int i = 0; i < dq; i++)
          ans += Integer.bitCount (D[0][i]);
      } else {
        ArrayList <Integer> [] T = new ArrayList[P];
        ArrayList <Integer> [] TR = new ArrayList[P];
        for (int i = 0; i < P; i++)
          TR[i] = new ArrayList <Integer> ();

        int [][] U = new int [P][P];
        for (int i = 0; i < P; i++) {
          T[i] = new ArrayList <Integer> ();
          for (int s : S[i])
            if (L[i] + 1 == L[s] && (L[s] < L[1] || s == 1)) {
              if (s != 1) T[i].add (s);
              TR[s].add(i);
            }
        }

        for (int s : T[0]) {
          for (int i = 0; i < dq; i++)
            U[0][s] += Integer.bitCount (D[0][i] | D[s][i]);
          //System.out.println (s + " " + U[0][s]);
        }

        Arrays.fill (F, false);
        Qh = 0;
        Qt = 1;
        F[0] = true;
        while (Qh < Qt) {
          int v = Q[Qh++];
          if (v != 0) {
            for (int s : TR[v])
              for (int t : T[v]) {
                int cur = 0;
                for (int i = 0; i < dq; i++)
                  cur += Integer.bitCount (D[t][i] & ~(D[s][i] | D[v][i]));
                if (U[s][v] + cur > U[v][t])
                  U[v][t] = U[s][v] + cur;
              }
          }
          for (int s : S[v])
            if (!F[s]) {
              Q[Qt++] = s;
              F[s] = true;
            }
        }

        for (int i : TR[1])
          for (int s : TR[i])
            if (U[s][i] > ans) {
              ans = U[s][i];
              //System.out.println (s + " " + i + " " + U[s][i]);
            }

        ans -= L[1];  
      }

      System.out.println ("Case #" + tt + ": " + (L[1] - 1) + " " + ans);
    }
  }
}