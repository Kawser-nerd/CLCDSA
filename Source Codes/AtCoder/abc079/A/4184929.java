import java.util.*;

public class Main{
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
  
   	String N = scanner.nextLine();
    
    char a = N.charAt(0);
    char b = N.charAt(1);
    char c = N.charAt(2);
    char d = N.charAt(3);
    
    if (a==b && b==c){
      System.out.println("Yes");
    } else if (b==c && c==d){
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}