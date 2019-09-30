import java.util.Scanner;
 
class Main{
  
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int num = sc.nextInt();
  int max=0;
  int pmax=0;
  int temp=0;
  for(int i=0;i<num;i++) {
	  temp = sc.nextInt();
	  if(max<temp) {
		  pmax=max;
		  max=temp;
	  }else if(temp!=max&&pmax<temp){
	  	pmax=temp;
	  }
  }
   System.out.println(pmax);
 }
  
  
}