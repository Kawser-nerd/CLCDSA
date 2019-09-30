import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    sc.next();
    String str = sc.next();
    int x = 0, max = 0;
    for(int i = 0; i < str.length(); i++){
      x += (str.charAt(i) == 'I') ? 1 : -1;
      max = Math.max(max, x);
    }
    System.out.println(max);
  }
}