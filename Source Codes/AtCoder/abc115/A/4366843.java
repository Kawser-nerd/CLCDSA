import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int d;
      d=Integer.parseInt(sc.next());

      System.out.print("Christmas");
      for(int i=0; i<25-d; i++){
        System.out.print(" Eve");
      }
      System.out.println("");
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}