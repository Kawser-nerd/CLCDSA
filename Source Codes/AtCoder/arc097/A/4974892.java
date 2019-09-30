import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String s = scanner.next();
    int K = scanner.nextInt();
    scanner.close();
    List<String> list1 = new ArrayList<String>();
    for (int i = 0; i < s.length(); i++) {
      for (int j = i + 1; j <= Math.min(i + K, s.length()); j++) {
        list1.add(s.substring(i, j));
      }
    }
    List<String> list2 = new ArrayList<String>(new HashSet<>(list1));
    Collections.sort(list2);
    System.out.println(list2.get(K - 1));
  }

}