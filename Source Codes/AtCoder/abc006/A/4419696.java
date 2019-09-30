import java.util.*;

public class Main {
 public static void main(String[] args) {
   
   Scanner scanner = new Scanner(System.in);
   
   int input = scanner.nextInt();
   
   if (input % 3 == 0) {
     System.out.println("YES");
   } else {
     System.out.println("NO");
   }
 }
}