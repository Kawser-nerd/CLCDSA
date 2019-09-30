import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    boolean[] expo = new boolean[x+1];
    expo[1] = true;
    for(int i = 2; i <=x; i++){
      int v = i * i;
      while(v <= x){
        expo[v] = true;
        v *= i;
      }
    }
    for(int i = x; i >= 1; i--){
      if(expo[i]){
        System.out.println(i);
        break;
      }
    }
  }
}