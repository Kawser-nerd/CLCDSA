import java.util.Scanner;

public class Main {
  public static void main(String args[]) {
    Scanner acd = new Scanner(System.in);
    int n,a,b,c;
    a=acd.nextInt();
    b=acd.nextInt();
    if(b/100>0)
      n = a * 1000 + b;
    else if(b/10>0)
      n = a * 100 + b;
    else 
      n = a * 10 + b;
    for(c = 1;c < 317 && c * c != n; c++);
    if(c==317)
      System.out.println("No");
    else 
      System.out.println("Yes");
}   
}