import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int num = Integer.parseInt(sc.nextLine());
    int num2 = Integer.parseInt(sc.nextLine());
    int mod = 0;
    int num3 = 0;
    if (num == num2 ){
      System.out.println(0);
    } else if  (num2 > num){
      System.out.println(num2 - num);
    } else {
		mod = num % num2;
      	num3 = (num / num2) + 1;
      	if (mod == 0){
          System.out.println(0);
        } else {
          System.out.println((num3 * num2) -num);
        }
    }
  }
}