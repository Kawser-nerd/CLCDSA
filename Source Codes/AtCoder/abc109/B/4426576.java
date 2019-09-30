import java.util.Scanner;
import java.util.Arrays;


public class Main {
  public static void main (String[] args) {
    Scanner reader = new Scanner(System.in);
    int A = reader.nextInt();
    String[] list = new String[A];
    for (int i = 0; i < A; i++) {
    	list[i] = reader.next();
      	if (i > 0) {
          if (list[i-1].charAt(list[i-1].length() - 1) !=  list[i].charAt(0)) {
            System.out.print("No");
              return;
          }
          for (int j = i - 1; j >= 0; j--) {
          	if (list[j].equals(list[i])) {
             System.out.print("No");
              return;
            }
          }
        }
    }
    
    System.out.print("Yes");
    
}
  
}