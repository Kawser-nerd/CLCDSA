import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int s=n%60;
  n/=60;
  int m=n%60;
  n/=60;
  System.out.println(((n<10)?("0"+n):n)+":"+((m<10)?("0"+m):m)+":"+((s<10)?("0"+s):s));
}
}