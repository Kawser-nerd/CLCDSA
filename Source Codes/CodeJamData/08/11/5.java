import java.util.*;

/**
 * 
 * 
 * @author Michael Seibert
 */
public class MinimumProduct
{

   /**
    * @param args
    */
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      int numCases = in.nextInt();
      for (int i = 0; i < numCases; i++)
         doCase(i + 1, in);
   }

   private static void doCase(int caseNum, Scanner in)
   {
      int dims = in.nextInt();
      
      List<Integer> v1 = new ArrayList<Integer>(dims);
      
      for (int i = 0; i < dims; i++)
         v1.add(in.nextInt());

      Collections.sort(v1);
      
      List<Integer> v2 = new ArrayList<Integer>(dims);
      
      for (int i = 0; i < dims; i++)
         v2.add(in.nextInt());
      
      Collections.sort(v2, new Comparator<Integer>() {
         @Override
         public int compare(Integer o1, Integer o2)
         {
            return -o1.compareTo(o2);
         }
      });
      
      long prod = 0;
      
      for (int i = 0; i < dims; i++)
         prod += v1.get(i) * (long)v2.get(i);
      
      System.out.println("Case #" + caseNum + ": " + prod);
   }
}
