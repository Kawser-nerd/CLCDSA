import java.util.Scanner;
 
public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    
    float a = sc.nextInt();
    
    float sum = 0;
    for(int i=1; i<=a; i++){
      sum += i*10000 / a;
    }
    System.out.println(sum);
  }
}