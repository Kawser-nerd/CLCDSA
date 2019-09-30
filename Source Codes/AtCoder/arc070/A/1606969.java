import java.util.Scanner;

public class Main{

   public static void main(String[] args){
   
      Scanner reader = new Scanner(System.in);
      int home = reader.nextInt();
      
      double interm = -0.5 + Math.sqrt(0.25 + 2*home);
      if(interm%1.0 > 0) {
         System.out.println((int)(interm + 1));
      } else {
         System.out.println((int)interm);
      }
   }
}