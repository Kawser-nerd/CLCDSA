import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        String s = sc.next();
        int b = sc.nextInt();
        if(s.equals("+")){
          System.out.println(a + b);
        }else{
          System.out.println(a - b);
        }
    }
}