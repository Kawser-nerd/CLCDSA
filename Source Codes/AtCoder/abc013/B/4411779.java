import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  System.out.println(Math.min(Math.min(Math.abs(n-m),Math.abs(n+10-m)),Math.abs(m+10-n)));
}}