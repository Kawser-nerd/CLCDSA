import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       String s=sc.nextLine();
       if(s.equals("acb")||s.equals("abc")||s.equals("bac")||s.equals("bca")||s.equals("cab")||s.equals("cba"))
    	   System.out.println("Yes");
       else
    	   System.out.println("No");
    }
    }