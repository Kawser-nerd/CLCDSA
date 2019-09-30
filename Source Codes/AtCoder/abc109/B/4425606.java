import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      n=Integer.parseInt(sc.next());
      String[] w=new String[n];
      for(int i=0; i<n; i++){
        w[i]=sc.next();
      }

      boolean ans=true;
      out: for(int i=1; i<n; i++){
        if(w[i].charAt(0)!=w[i-1].charAt(w[i-1].length()-1)){
          ans=false;
          break out;
        }
        for(int j=0; j<i; j++){
          if(w[i].equals(w[j])){
            ans=false;
            break out;
          }
        }
      }

      if(ans==true){
        System.out.println("Yes");
      }else{
        System.out.println("No");
      }
      

      }catch (Exception e) {
      System.out.println("out");
    }
  }
}