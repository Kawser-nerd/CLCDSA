import java.util.Scanner;


public class Main {
  public static void main (String[] args) {
    Scanner reader = new Scanner(System.in);
    int A = reader.nextInt();
    int previous = reader.nextInt();
    int tmp =  reader.nextInt();
    int result = Math.abs(tmp - previous);
   	for(int i = 1; i < A; i++) {
      previous = tmp;
      tmp = reader.nextInt();
    	result = gcd(Math.abs(tmp - previous), result);
    }
    System.out.print(result);
    
}
  
 private static int gcd(int x, int y) {
   
   if (y > x) {
   	int tmp = y;
     y = x;
     x = tmp;
   }
   int next;
   while ((next = x % y) != 0) {
     x = y;
     y = next;
     
   }
   return y;
 }
  
}