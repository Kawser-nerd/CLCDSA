import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();int m=sc.nextInt();sc.nextLine();
  for(int i=0;i<m+2;i++)System.out.print("#");
  System.out.println();
  for(int i=0;i<n;i++){
  System.out.print("#");
    System.out.print(sc.nextLine());
    System.out.println("#");
  }
  for(int i=0;i<m+2;i++)System.out.print("#");
  System.out.println();
}
}