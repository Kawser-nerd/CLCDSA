import java.io.*;
import java.util.*;

public class ProblemC {

   double[][] probs;
   int nQuestions;

   public ProblemC() throws Exception {
      Scanner sc = new Scanner(new File("C-in.txt"));
      PrintWriter pw = new PrintWriter(System.out);
       //PrintWriter pw = new PrintWriter("C:/Documents and Settings/codejam/Desktop/C-out.txt");
      int C = Integer.parseInt(sc.nextLine());
      for (int i=1; i<=C; i++) {
         int[] data = parseIntArray(sc.nextLine());
         int nSubmissions = data[0];
         nQuestions = data[1];
         probs = new double[nQuestions][];
         for (int j=0; j<nQuestions; j++) {
            probs[j] = parseDoubleArray(sc.nextLine());
         }
         ArrayList<Double> products = new ArrayList<Double>();
         recurse(products, 0, 1.0);
         Collections.sort(products);
         int remaining = nSubmissions;
         double ans = 0.0;
         for (int j=products.size()-1; j>=0 && remaining>0; j--) {
            ans += products.get(j);
            remaining--;
         }
         pw.println("Case #" + (i) + ": "  + (ans));
      }
      pw.flush();
      pw.close();
   }

   void recurse(ArrayList<Double> products, int index, double sofar) {
      if (index==nQuestions) {
         products.add(sofar);
      } else {
         for (int i=0; i<4; i++) {
            recurse(products, index+1, sofar*probs[index][i]);
         }
      }
   }

   int[] parseIntArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      int[] ret = new int[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = Integer.parseInt(st.nextToken());
      }
      return ret;
   }

   double[] parseDoubleArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      double[] ret = new double[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = Double.parseDouble(st.nextToken());
      }
      return ret;
   }

   public static void main(String[] args) {
      try {
         new ProblemC();
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}
