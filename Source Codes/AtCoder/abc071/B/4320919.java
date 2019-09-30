import java.util.*;
import java.math.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    boolean[] a = new boolean[26];
    for(int i = 0; i < str.length(); i++){
      a[str.charAt(i) - 'a'] = true;
    }
    for(int i = 0; i < a.length; i++){
      if(!a[i]){
        System.out.println((char)(i + 'a'));
        System.exit(0);
      }
    }
    System.out.println("None");
  }
}