import java.math.BigDecimal;
import java.util.Scanner;

/**
 * 
 * 
 * @author Michael Seibert
 */
public class Numbers
{
   final static BigDecimal dec = new BigDecimal("5.2360679774997896964091736687313");
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
      String string = dec.pow(in.nextInt()).toPlainString();
      int ndx = string.indexOf('.');
      
      String result;
      
      if (ndx > 2)
         result = string.substring(ndx - 3, ndx);
      else
      {
         result = '0' + string.substring(0, ndx);
      }
      
      System.out.println("Case #" + caseNum + ": " + result);
   }
}
