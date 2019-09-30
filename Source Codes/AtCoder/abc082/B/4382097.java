import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();
    char[] t = sc.next().toCharArray();
    Arrays.sort(s);
    Arrays.sort(t);
    reverse(t);
    String ss = new String(s);
    String tt = new String(t);
    if(ss.compareTo(tt) < 0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
  
  public static char[] reverse(char[] array){
    for(int i = 0; i < array.length/2; i++){
      char tmp = array[i];
      array[i] = array[array.length - 1 - i];
      array[array.length - 1 - i] = tmp;
    }
    return array;
  }
}