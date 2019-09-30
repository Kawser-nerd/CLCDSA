import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  String s = sc.next();
  int a = sc.nextInt();
  int b = sc.nextInt();
  int c = sc.nextInt();
  int d = sc.nextInt();
  System.out.print(s.substring(0,a));
  System.out.print("\"");
  System.out.print(s.substring(a,b));
  System.out.print("\"");
  System.out.print(s.substring(b,c));
  System.out.print("\"");
  System.out.print(s.substring(c,d));
  System.out.print("\"");
  System.out.println(s.substring(d,s.length()));
}}