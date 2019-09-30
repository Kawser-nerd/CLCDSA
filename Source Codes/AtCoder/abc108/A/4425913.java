import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int k;
      k=Integer.parseInt(sc.next());

      if(k%2==0){
        System.out.println((k/2)*(k/2));
      }else{
        System.out.println((k/2)*(k/2+1));
      }
    
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}