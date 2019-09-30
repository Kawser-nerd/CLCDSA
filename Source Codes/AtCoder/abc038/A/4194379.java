import java.util.*;

public class Main{

  public static void main (String[] args){
    
    Scanner scanner = new Scanner (System.in);
    
    String name = scanner.nextLine();
    
    char lastLetter = name.charAt(name.length()-1);
    
    if(lastLetter=='T'){
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}