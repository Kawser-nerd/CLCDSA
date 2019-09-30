import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int length = s.length();
    int K = sc.nextInt();
    Set<String> set = new HashSet<>();

    for (int i=1; i<=K; i++) {
      for (int j=0; j<=length-i; j++) {
        set.add(s.substring(j, j+i));
      }
    }
    List<String> list = new ArrayList<>(set);
    Collections.sort(list);
    System.out.println(list.get(K-1));
  }
}