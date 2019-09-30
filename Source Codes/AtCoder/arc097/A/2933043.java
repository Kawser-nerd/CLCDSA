import java.util.*;
import java.util.stream.Collectors;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int k = sc.nextInt();
    ArrayList<String> ss = new ArrayList<>();
    int n = s.length();
    for(int i=0; i<n; i++) {
      for(int j=1; j<=k; j++) {
        if(i + j <= n) {
          ss.add(s.substring(i, i + j));
        }
      }
    }
    List<String> us = ss.stream().sorted().distinct().collect(Collectors.toList());
    System.out.println(us.get(k-1));
  }
}