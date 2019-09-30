import java.util.Scanner;

class Main{
  
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
	int  num=sc.nextInt();
 int min=101;
   for(int i=0;i<num;i++){
     min=Math.min(min,sc.nextInt());
   }
   System.out.println(min);
   
   
 }
  
  
}