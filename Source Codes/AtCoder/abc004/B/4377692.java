import java.util.*;
public class Main{
  public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    String po[][]=new String[4][4];
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        po[i][j]=sc.next();
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        System.out.print((j==0)?po[3-i][3-j]:" "+po[3-i][3-j]);
      }System.out.println();
    }
  }
}