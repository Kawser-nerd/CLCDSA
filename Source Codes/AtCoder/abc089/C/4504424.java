import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
  long m=0,a=0, r=0,c=0, h=0;
	for(int i=0;i<n;i++){
      String s=sc.next().substring(0,1);
    	if(s.equals("M"))m++;
      else if(s.equals("A"))a++;
      else if(s.equals("R"))r++;
      else if(s.equals("C"))c++;
      else if(s.equals("H"))h++;
    }
  System.out.println(m*a*r+m*a*c+m*a*h+m*r*c+m*r*h+m*c*h+a*r*c+a*r*h+a*c*h+r*c*h);
}

}