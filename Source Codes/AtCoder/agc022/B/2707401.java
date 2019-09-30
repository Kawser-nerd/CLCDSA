import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    Set<Integer> ans = new HashSet<>();
    int lastAns;
    if (N == 3) {
      System.out.println("2 3 25");
    } else if (N==4) {
      System.out.println("2 3 5 20");
    } else if (N==5) {
      System.out.println("2 3 4 5 16");
    } else {
      ans.add(2);
      ans.add(3);
      int sum = 5;
      for (int i=4;;i++) {
        if (i%2==0 || i%3==0) {
          ans.add(i);
          sum += i;
          lastAns = i;
          if (ans.size() == N) {
            break;
          }
        }
      }
      if (sum % 6 == 0) {
        // do nothing
      } else if (sum % 6 == 2) {
        ans.remove(8);
        for (int i = lastAns+1;;i++) {
          if (i % 6 == 0) {
            ans.add(i);
            break;
          }
        }
      } else if (sum % 6 == 3) {
        ans.remove(9);
        for (int i = lastAns+1;;i++) {
          if (i % 6 == 0) {
            ans.add(i);
            break;
          }
        }
      } else {
        ans.remove(9);
        for (int i = lastAns+1;;i++) {
          if (i % 6 == 4) {
            ans.add(i);
            break;
          }
        }
      }
      for (Integer an : ans) {
        System.out.print(an + " ");
      }
    }
  }
}