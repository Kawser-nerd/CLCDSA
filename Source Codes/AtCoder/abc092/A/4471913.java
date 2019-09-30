import java.util.*;
import java.io.*;
public class Main{
  public static void main(String[] args){
    RapidScanner sc = new RapidScanner();
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();
    System.out.println(Math.min(a, b) + Math.min(c, d));
  }
}

class RapidScanner{
  BufferedReader reader;
  int index;
  String[] buffer;
  public RapidScanner(){
    reader = new BufferedReader(new InputStreamReader(System.in));
    try{
      buffer = reader.readLine().split(" ");
    }catch(Exception e){
      
    }
    index = 0;
  }
  
  public int nextInt(){
    if(index == buffer.length){
      try{
        buffer = reader.readLine().split(" ");
      }catch(Exception e){
        
      }
      index = 0;
    }
    return Integer.parseInt(buffer[index++]);
  }
}