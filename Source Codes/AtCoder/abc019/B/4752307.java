import java.util.*;
 
public class Main{
  public static int[] dp;
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    String s = sc.nextLine();
    int count = 0;
    char c = '-';
    String ans = "";
    for(int i = 0; i <= s.length(); i++){
      if(i == 0){
        c = s.charAt(i);
        count++;
      }else if(i == s.length()){
        ans = ans + String.valueOf(c) + count;
      }else if(c == s.charAt(i)){
        count++;
      }else{
        ans = ans + String.valueOf(c) + count;
        count = 1;
        c = s.charAt(i);
      }
    }
    System.out.println(ans);
  }
}