import java.util.*;
public class Main{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  String po[]=sc.next().split("",0);
  int x=0,y=0;
  for(int i=0;i<n;i++){
    y+=(po[i].equals("I"))?1:-1;
    x=Math.max(x,y);
  }
    System.out.println(x);
}
}