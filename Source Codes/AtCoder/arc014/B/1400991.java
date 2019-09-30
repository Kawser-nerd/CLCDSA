import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    ArrayList<String> word = new ArrayList<String>();
    String preW = sc.next();
    word.add(preW);
    int lose = 0;
    for(int i = 2; i <= N; i++) {
      String s = sc.next();
      if(word.contains(s)) {
        lose = i;
        break;
      }
      if(preW.charAt(preW.length() - 1) != s.charAt(0)) {
        lose = i;
        break;
      }
      preW = s;
      word.add(s);
    }
    String ans = "";
    if(lose == 0) {
      ans = "DRAW";
    } else {
      if(lose % 2 == 0) {
        ans = "WIN";
      } else {
        ans = "LOSE";
      }
    }
    System.out.println(ans);
  }
}