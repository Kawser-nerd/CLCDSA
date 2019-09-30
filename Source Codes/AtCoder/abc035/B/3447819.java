import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    int T = scanner.nextInt();
    int x = 0;
    int y = 0;
    int count = 0;
    for(int i = 0; i < S.length(); i++){
      if(S.charAt(i) == 'L'){
        x += -1;
      }
      if(S.charAt(i) == 'R'){
        x += 1;
      }
      if(S.charAt(i) == 'U'){
        y += 1;
      }
      if(S.charAt(i) == 'D'){
        y += -1;
      }
      if(S.charAt(i) == '?'){
        count++;
      }
    }
    if(T == 1){
      System.out.println(Math.abs(x)+Math.abs(y)+count);
    }  
    if(T == 2){
      if(Math.abs(x)+Math.abs(y)-count >= 0) {
        System.out.println(Math.abs(x)+Math.abs(y)-count);
      }else if(Math.abs(x)+Math.abs(y)-count < 0 && (Math.abs(x)+Math.abs(y))%2 == count%2){
        System.out.println(0);
      }else{
        System.out.println(1);
      }
    }
  }
}