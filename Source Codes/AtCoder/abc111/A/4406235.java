import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      n=Integer.parseInt(sc.next());

      if(n==111){
        System.out.println(999);
      }else if(n==119){
        System.out.println(991);
      }else if(n==191){
        System.out.println(919);
      }else if(n==199){
        System.out.println(911);
      }else if(n==911){
        System.out.println(199);
      }else if(n==919){
        System.out.println(191);
      }else if(n==991){
        System.out.println(119);
      }else if(n==999){
        System.out.println(111);
      }
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}