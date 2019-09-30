import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String str = sc.next();
    String[] s = str.split("");
    int x = 0;
    int max = 0;
    String I = "I";
    String D = "D";
    for(int i = 0;i < n;i++){
      if(s[i].equals(I)){
        x = x+1;
        /*if(max <= x){
          max = x;
        }*/
      }
      else if(s[i].equals(D)){
        x = x-1;
        /*if(max <= x){
          max = x;
        }*/
      }
      if(max <= x){
        max = x;
      }
    }
    System.out.println(max);
  }
}