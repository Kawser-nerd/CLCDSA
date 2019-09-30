import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int s, t;
      s=Integer.parseInt(sc.next());
      t=Integer.parseInt(sc.next());
      
      System.out.println(t-s+1);
      
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}