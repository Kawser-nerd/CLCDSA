import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String s = sc.next();
    int max = 0;
    for(int i = 1; i < n; i++){
      int count = 0;
      boolean[] a = new boolean[26];
      for(int j = 0; j < i; j++){
        if(a[s.charAt(j) - 'a']){
          continue;
        }
        for(int k = i; k < n; k++){
          if(s.charAt(j) == s.charAt(k)){
            a[s.charAt(j) - 'a'] = true;
            count++;
            break;
          }
        }
      }
      max = Math.max(max, count);
    }
    System.out.println(max);
  }
}