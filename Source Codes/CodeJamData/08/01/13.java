import java.util.*;
public class SavingTheUniverse {
   public static void main(String[] args) {
      try {
         Scanner s = new Scanner(System.in);
         int n = Integer.parseInt(s.nextLine());
         for (int i=0; i<n; i++) {
            int nEngines = Integer.parseInt(s.nextLine());
            String[] names = new String[nEngines];
            for (int j=0; j<nEngines; j++) {
               names[j] = s.nextLine();
            }
            Arrays.sort(names);
            int nQueries = Integer.parseInt(s.nextLine());
            int[] qdata = new int[nQueries];
            for (int j=0; j<nQueries; j++) {
               qdata[j] = Arrays.binarySearch(names, s.nextLine());
            }
            // best[q][e] returns the minimum number of switches
            // required, given that we are currently using engine e,
            // and about to process query q.
            int[][] best = new int[2][nEngines];
            for (int q=nQueries; q>=0; q--) {
               for (int e=0; e<nEngines; e++) {
                  if (q==nQueries) {
                     // no more queries
                     best[q%2][e] = 0;
                  } else if (e != qdata[q]) {
                     // query is not the search engine
                     best[q%2][e] = best[(q+1)%2][e];
                  } else {
                     best[q%2][e] = 123456789;
                     // decide which engine to switch to
                     for (int ee=0; ee<nEngines; ee++) {
                        if (ee != e) {
                           best[q%2][e] = Math.min(best[q%2][e], 1 + best[(q+1)%2][ee]);
                        }
                     }
                  }
               }
            }
            int res = 123456789;
            for (int e=0; e<nEngines; e++) {
               res = Math.min(res, best[0][e]);
            }
            System.out.println("Case #" + (i+1) + ": " + res);
         }
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}
