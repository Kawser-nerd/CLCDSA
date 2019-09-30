import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String po=sc.nextLine();
  String[]s=po.split("");
  int i,j;
  for(i=0;true;i++){
  if(s[i].equals("A"))break;
  }
  
  for(j=s.length-1;true;j--){
  if(s[j].equals("Z"))break;
  }
  System.out.println(j-i+1);
}
}