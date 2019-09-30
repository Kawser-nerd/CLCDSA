import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      n=Integer.parseInt(sc.next());
            
      if(n%2==0){
        System.out.println(n/2);
      }else{
        System.out.println(n/2+1);
      }
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}