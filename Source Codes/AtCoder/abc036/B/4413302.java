import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  sc.nextLine();
  String[][]po=new String[n][n];
  for(int i=0;i<n;i++){
    String p[]=sc.nextLine().split("",0);
  for(int j=0;j<n;j++){
  po[i][j]=p[j];
  }
  }
   for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    System.out.print(po[n-1-j][i]);
  }System.out.println();}
}}