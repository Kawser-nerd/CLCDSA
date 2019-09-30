import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String po=sc.nextLine();
  String[]s=po.split("",0);
  for(int i=0;i<s.length;i++)System.out.print((i%2==0)?s[i]:"");System.out.println();
}
}