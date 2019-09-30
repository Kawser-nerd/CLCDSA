import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int cards[]=new int[]{1,2,3,4,5,6};
  n%=30;
  for(int i=0;i<n;i++){
  	int po=cards[i%5];
    cards[i%5]=cards[i%5+1];
    cards[i%5+1]=po;
  }
  for(int i=0;i<6;i++)
  System.out.print(cards[i]);
  System.out.println();
}
}