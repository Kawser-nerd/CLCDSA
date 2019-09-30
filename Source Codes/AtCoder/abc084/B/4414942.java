import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int a=sc.nextInt();
  int b=sc.nextInt();
  String po=sc.next();
  String s[]=po.split("-",0);
  System.out.println((s.length==2)?(s[0].length()==a&&s[1].length()==b)?"Yes":"No":"No");
}}