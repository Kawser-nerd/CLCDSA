import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    for(int i = 0; i < S.length(); i++){
      if(S.charAt(i) == '0' || S.charAt(i) == '1'|| S.charAt(i) == '2'|| S.charAt(i) == '3'|| S.charAt(i) == '4'|| S.charAt(i) == '5'|| S.charAt(i) == '6'|| S.charAt(i) == '7'|| S.charAt(i) == '8'|| S.charAt(i) == '9'){
        System.out.print(S.charAt(i));
      }
    }
  }
}