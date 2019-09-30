import java.util.*;
import java.math.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    for(int i = 0; i < str.length(); i += 2){
      System.out.print(str.charAt(i));
    }
    System.out.println();
  }
}