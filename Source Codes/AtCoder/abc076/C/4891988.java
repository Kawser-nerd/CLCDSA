import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String SS, TT;
    SS = sc.next();
    TT = sc.next();
    char[] S = SS.toCharArray();
    char[] T = TT.toCharArray();
    if (S.length < T.length) {
      System.out.println("UNRESTORABLE");
      return;
    }
    for (int i = S.length - T.length; i >= 0; i--) {
      boolean flag = true;
      for (int j = 0; j < T.length; j++) {
        if (S[i + j] == '?')
          continue;
        if (S[i + j] != T[j]){
          flag = false;
        }
      }
      if (flag) {
        for (int j = 0; j < T.length; j++)
          S[i + j] = T[j];
        for (int j = 0; j < S.length; j++)
          if (S[j] == '?')
            S[j] = 'a';
        System.out.println(S);
        return;
      }
    }
    System.out.println("UNRESTORABLE");
  }
}