import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int a, b;
      a=Integer.parseInt(sc.next());
      b=Integer.parseInt(sc.next());
      
      if(a*b%2==0){
        System.out.println("No");
      }else{
        System.out.println("Yes");
      }
      

      }catch (Exception e) {
      System.out.println("out");
    }
  }
}