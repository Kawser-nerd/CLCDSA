import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int[] x=new int[3];
      for(int i=0; i<3; i++){
        x[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(x);
      System.out.println(x[0]+x[1]+x[2]*10);
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}