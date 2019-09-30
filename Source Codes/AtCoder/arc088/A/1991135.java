import java.util.*;

public class Main{
    private static void solve(long X, long Y){
        int length = 1;
        while(2 * X <= Y){
            X = 2 * X;
            length ++;
        }
        System.out.print(length);
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        long X = input.nextLong();
        long Y = input.nextLong();
        input.close();
        solve(X, Y);
    }
}