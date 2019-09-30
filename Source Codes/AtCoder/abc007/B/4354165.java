import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      String a;
      a=sc.next();

      if(a.equals("a")){
        System.out.println(-1);
      }else{
        System.out.println("a");
      }


    }catch (Exception e) {
      System.out.println("out");
    }
  }
}