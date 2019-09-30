import java.util.*;

class Main {
  
  public static void main(String args[]) {
    Scanner scan = new Scanner(System.in);
    if( Integer.parseInt( scan.next() ) % 2 == 0 )
      System.out.println("Blue");
    else
      System.out.println("Red");
  }
  
}