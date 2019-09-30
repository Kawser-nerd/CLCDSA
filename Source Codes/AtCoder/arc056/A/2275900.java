import java.util.*;
public class Main {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
  long a = sc.nextInt();
  long b = sc.nextInt();
  long k = sc.nextInt();
  long l = sc.nextInt();
  long s = k/l;
  long t = k%l;
  if(t == 0)System.out.println(s*b);
  else{
    if(t*a < b)System.out.println(s*b + t*a);
    else System.out.println((s+1)*b);
  }
}}