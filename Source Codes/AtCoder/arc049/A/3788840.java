import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    char[] s = new char[S.length()];
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int C = scanner.nextInt();
    int D = scanner.nextInt();
    String ans = "";
    for(int i = 0; i < S.length(); i++){
      s[i] = S.charAt(i);
    }
    for(int i = 0; i < S.length(); i++){
      if(i == A || i == B || i == C || i == D){
        ans += "\"" + s[i];
      }else{
        ans += s[i];
      }
    }
    if(D == S.length()){
      ans += "\"";
    }
    System.out.println(ans);
  }
}