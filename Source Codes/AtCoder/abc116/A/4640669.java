import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args){
    MyScanner sc = new MyScanner();
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    System.out.println(a * b / 2);
  }
  
  public static PrintWriter out;
  
  public static class MyScanner{
    BufferedReader br;
    StringTokenizer st;
    
    public MyScanner(){
      br = new BufferedReader(new InputStreamReader(System.in));
    }
    
    String next(){
      while(st == null || !st.hasMoreElements()){
        try{
          st = new StringTokenizer(br.readLine());
        }catch(IOException e){
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }
    
    int nextInt(){
      return Integer.parseInt(next());
    }
    
    String nextLine(){
      String str = "";
      try{
        str = br.readLine();
      }catch(IOException e){
        e.printStackTrace();
      }
      return str;
    }
  }
}