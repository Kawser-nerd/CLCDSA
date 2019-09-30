import java.util.Scanner;
class Main{
  public static void main(String args[]){
    Scanner scan=new Scanner(System.in);
    int N = scan.nextInt();
    double x;
    double sum = 0;
    String str;
    for(int i = 0;i < N; i++){
      x = scan.nextDouble();
      str = scan.next();
      if(str.equals("BTC")) x = x*380000;
      sum = sum+x;
    }
    System.out.println(sum);
  }
}