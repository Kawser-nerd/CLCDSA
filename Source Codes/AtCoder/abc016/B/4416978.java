import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt(),b=sc.nextInt(),n=sc.nextInt();
        if(a+b==n && a-b==n)
            System.out.println("?");
        else if(a+b==n)
            System.out.println("+");
        else if(a-b==n)
            System.out.println("-");
        else
            System.out.println("!");
    }
}