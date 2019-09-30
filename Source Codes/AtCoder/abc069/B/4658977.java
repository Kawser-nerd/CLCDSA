import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String S[] = s.split("");
    System.out.printf("%s",S[0]);
    System.out.printf("%d",s.length()-2);
    System.out.println(S[s.length()-1]);
  }
}