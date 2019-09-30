//?

import java.util.*;

class Main{
  public void fun1(String x){
    x= x.replaceAll("a","").replaceAll("i","").replaceAll("u","")
        .replaceAll("e","").replaceAll("o","");
    System.out.println(x);
  }
  public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    String w= sc.nextLine();
    Main main= new Main();
    main.fun1(w);
  }
}