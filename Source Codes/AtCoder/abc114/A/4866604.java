import java.util.Scanner;

class Main{
  public static void main(String args[]) {

    Scanner scanner = new Scanner(System.in);
    //???????
    int x = scanner.nextInt();
    //x? 3 OR 5 OR 7??
    if(x == 3 || x == 5 || x == 7){
      System.out.println("YES");
    //???????
    }else{
      System.out.println("NO");
    }
  }
}