import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;

      n=Integer.parseInt(sc.next());

      if(n==1){
        System.out.println("Hello World");
      }

      if(n==2){
        int a, b;
        a=Integer.parseInt(sc.next());
        b=Integer.parseInt(sc.next());
        System.out.println(a+b);
      }
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}