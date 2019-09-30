import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      String s, t;
      s=sc.next();
      t=sc.next();

      boolean ans=true;

      for(int i=0; i<s.length(); i++){
        if(s.charAt(i)==t.charAt(i) ||
           (s.charAt(i)=='@' && (t.charAt(i)=='a' || t.charAt(i)=='t' || t.charAt(i)=='c' || t.charAt(i)=='o' || t.charAt(i)=='d' || t.charAt(i)=='e' || t.charAt(i)=='r')) ||
           (t.charAt(i)=='@' && (s.charAt(i)=='a' || s.charAt(i)=='t' || s.charAt(i)=='c' || s.charAt(i)=='o' || s.charAt(i)=='d' || s.charAt(i)=='e' || s.charAt(i)=='r'))){
        }else{
          ans=false;
          break;
        }
      }

      if(ans){
        System.out.println("You can win");
      }else{
        System.out.println("You will lose");
      }
      
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}