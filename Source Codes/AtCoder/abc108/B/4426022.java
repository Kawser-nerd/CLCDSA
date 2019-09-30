import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int x1, y1, x2, y2;
      x1=Integer.parseInt(sc.next());
      y1=Integer.parseInt(sc.next());
      x2=Integer.parseInt(sc.next());
      y2=Integer.parseInt(sc.next());

      System.out.println((x2+y1-y2) +" "+ (y2-x1+x2) +" "+ (x1+y1-y2) +" "+ (y1-x1+x2));
    
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}