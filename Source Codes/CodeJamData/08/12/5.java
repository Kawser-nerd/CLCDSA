import java.util.*;

public class MilkShakes
{
   public static class Customer
   {
      private ArrayList<Integer> prefs;
      private int maltedLike = -1;

      public Customer(Scanner in)
      {
         int numPrefs = in.nextInt();
         prefs = new ArrayList<Integer>(numPrefs);
         for (int i = 0; i < numPrefs; i++)
         {
            int shakeIndex = in.nextInt() - 1;
            boolean malted = in.nextInt() == 1;
            if (malted)
               maltedLike  = shakeIndex;
            else
               prefs.add(shakeIndex);
         }
      }
      
      public int getMaltedLike()
      {
         return maltedLike;
      }
      
      public boolean satisfied(boolean[] batches)
      {
         if (maltedLike != -1 && batches[maltedLike])
            return false;
         
         for (Integer type : prefs)
            if (!batches[type])
               return true;
         return false;
      }
   }

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
      int flavors = in.nextInt();
      int numCustomers = in.nextInt();
      
      boolean []batches = new boolean[flavors];
      
      List<Customer> customers = new LinkedList<Customer>();
      
      for (int i = 0; i < numCustomers; i++)
      {
         customers.add(new Customer(in));
      }
      
      boolean madeMalt;
      do
      {
         madeMalt = false;
         for (ListIterator<Customer> iter = customers.listIterator(); iter.hasNext(); )
         {
            Customer c = iter.next();
            if (!c.satisfied(batches))
            {
               if (c.getMaltedLike() == -1)
               {
                  System.out.println("Case #" + caseNum + ": IMPOSSIBLE");
                  return;
               }
               madeMalt = madeMalt || !batches[c.getMaltedLike()];
               batches[c.getMaltedLike()] = true;
               iter.remove();
            }
         }
      } while (madeMalt);
      
      System.out.print("Case #" + caseNum + ":");
      
      for (boolean b : batches)
         System.out.print(" " + (b ? 1 : 0));
      
      System.out.println();
   }
}
