import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  String po=sc.next();
  if(n%2==0)System.out.println(-1);
  else {
  String s="b";
    int count=1;
    while(s.length()<n){
    s=(count%3==0)?"b"+s+"b":(count%3==1)?"a"+s+"c":"c"+s+"a";
      count++;
    }
    System.out.println(s.equals(po)?s.length()/2:-1);
  }
}
}