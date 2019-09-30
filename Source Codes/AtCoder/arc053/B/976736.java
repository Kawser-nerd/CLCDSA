import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String input = s.next();
    char[] array = input.toCharArray();
    int[] counter = new int[26];
    for (char c : array) {
      counter[c - 'a']++;
    }
    int odd = 0;
    int evenPairs = 0;
    for (int i = 0; i < 26; i++) {
      odd += (counter[i] % 2);
      evenPairs +=  (counter[i] / 2);
    }
    if (odd == 0) {
      System.out.println(2*evenPairs);
    } else {
      System.out.println(2*(evenPairs / odd) + 1);
    }
  }
}