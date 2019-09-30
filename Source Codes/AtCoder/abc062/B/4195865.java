import java.util.*;

public class Main{

  public static void main (String[] args){
    
    Scanner scanner = new Scanner (System.in);
    
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    String[] list = new String[H];
    
    scanner.nextLine();
    for(int i=0; i<H; i++){
      String temp = scanner.nextLine();
      list[i] = temp;
    }
    
    for(int i=0; i<W+2; i++){
      System.out.print("#");
    }
    System.out.println();
    
    for (int i=0; i<H; i++){
      System.out.print("#");
      System.out.print(list[i]);
      System.out.println("#");
    }
    for(int i=0; i<W+2; i++){
      System.out.print("#");
    }
    System.out.println();
  }
}