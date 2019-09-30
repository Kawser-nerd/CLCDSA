import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    int ans = 0;
    for(int i = 0; i < str.length(); i++){
      if(str.charAt(i) == '+'){
        ans++;
      }else{
        ans--;
      }
    }
    System.out.println(ans);
  }
}