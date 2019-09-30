import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  String po=sc.nextLine();
  int n=sc.nextInt();
  String s[]=po.split("",0);
  for(int i=0;i<n;i++){
    int a=sc.nextInt()-1;int b=sc.nextInt()-1;
    for(int j=0;j<=(b-a)/2;j++){
  String c=s[a+j];
    s[a+j]=s[b-j];
    s[b-j]=c;
    }
  }
  for(int i=0;i<s.length;i++)System.out.print(s[i]);
  System.out.println();
  
}

}