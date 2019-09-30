import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      n=Integer.parseInt(sc.next());
      
      System.out.println(n-1);
      
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}