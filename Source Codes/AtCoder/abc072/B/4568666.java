import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String S[] = s.split("");
    for(int i = 0;i < s.length();i++){
      if(i%2 == 0){
        System.out.printf("%s",S[i]);
      }
    }
  }
}