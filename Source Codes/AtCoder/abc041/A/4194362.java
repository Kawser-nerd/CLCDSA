import java.util.*;

public class Main{

  public static void main (String[] args){
    
    Scanner scanner = new Scanner (System.in);
    
    String phrase = scanner.nextLine();
    int number = scanner.nextInt();
    
    
    char letter = phrase.charAt(number-1);
    
    System.out.println(letter);
  }
}