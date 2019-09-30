import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  long a=2,b=1;
  int n=sc.nextInt();
  for(int i=0;i<n;i++){
  	long c=a;
    a=b;
    b+=c;
  }
  System.out.println(a);
}

}