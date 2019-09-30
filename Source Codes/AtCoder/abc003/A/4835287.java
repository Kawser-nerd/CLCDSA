import java.util.*;
import java.util.List;
import java.util.ArrayList;
import java.math.*;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int sum = N*(N+1)/2;

        System.out.println(10000*sum/N);
    }
}