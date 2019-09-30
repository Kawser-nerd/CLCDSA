import java.util.*;
 
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    int length = 0;
    int res = 0;
    for (int i = 0; i < S.length(); i++){
        String s = S.substring(i, i + 1);
        if (s.equals("A") || s.equals("G") || s.equals("T") || s.equals("C")){
            length++;
        } else {
            if (res < length) {
                res = length;
            }
            length = 0;
        }
    }
    if (res < length) {
        res = length;
    }
    System.out.println(res);
  }
  
}