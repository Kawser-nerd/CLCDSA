import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      String s;
      s=sc.next();
      int ans=1000;

      for(int i=2; i<s.length(); i++){
        if(Math.abs(Integer.parseInt(s.substring(i-2, i+1))-753)<ans){
          ans=Math.abs(Integer.parseInt(s.substring(i-2, i+1))-753);
        }
      }
      
      System.out.println(ans);
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}