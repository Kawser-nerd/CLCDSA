import java.util.*;
public class Main {
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int m = sc.nextInt();
  Set<Integer> s1 = new HashSet<>();
  Set<Integer> sn = new HashSet<>();
  for (int i=0; i<m; i++) {
    int a = sc.nextInt();
    int b = sc.nextInt();
    if (a == 1)s1.add(b);
    if (b == n)sn.add(a);        
  }
  s1.retainAll(sn);
  System.out.println(s1.isEmpty() ? "IMPOSSIBLE":"POSSIBLE");
}}