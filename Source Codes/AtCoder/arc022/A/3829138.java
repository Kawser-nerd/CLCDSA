import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    boolean flag1 = false;
    boolean flag2 = false;
    boolean flag3 = false;
    for(int i = 0; i < S.length(); i++){
      if(S.charAt(i) == 'i' || S.charAt(i) == 'I'){
        flag1 = true;
      }
      if(flag1 == true && (S.charAt(i) == 'c' || S.charAt(i) == 'C')){
        flag2 = true;
      }
      if(flag2 == true && (S.charAt(i) == 't' || S.charAt(i) == 'T')){
        flag3 = true;
      }
    }
    if(flag3){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}