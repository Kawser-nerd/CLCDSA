import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      String[][] bd = new String[4][4];

      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          bd[i][j] = sc.next();
        }
      }

      for(int i=3; i>=0; i--){
        System.out.println(bd[i][3]+" "+bd[i][2]+" "+bd[i][1]+" "+bd[i][0]);
      }
      
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}