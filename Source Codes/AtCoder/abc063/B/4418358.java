import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
int []po=new int[26];
  String str=sc.next();
  char[]c=str.toCharArray();
  for(int i=0;i<c.length;i++)po[c[i]-'a']++;
  boolean b=true;
  for(int i=0;i<po.length;i++){
  if(po[i]>1)b=false;
  }
  System.out.println(b?"yes":"no");
}
}