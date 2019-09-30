import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = "Bad";
        if(n==100) s = "Perfect";
        else if(n>=90) s = "Great";
        else if(n>=60) s = "Good";
        System.out.println(s);
    }
}