import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    char[] a = sc.next().toCharArray();
    Arrays.sort(a);
    if((new String(a)).equals("abc")){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}