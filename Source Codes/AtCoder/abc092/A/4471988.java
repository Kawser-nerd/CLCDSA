import java.util.*;
import java.io.*;
public class Main{
  public static void main(String[] args){
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int a,b,c,d;
    try{
      a = Integer.parseInt(bf.readLine());
      b = Integer.parseInt(bf.readLine());
      c = Integer.parseInt(bf.readLine());
      d = Integer.parseInt(bf.readLine());
      System.out.println(Math.min(a, b) + Math.min(c, d));
    }catch(Exception e){
      
    }
  }
}