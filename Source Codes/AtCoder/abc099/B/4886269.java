import java.util.*;
import java.io.*;
class Main {
    int retrunN( int n ){
        int i = 0;
        int sum = 0;
        while ( i <= n){
            sum += i++;
        }
        return sum;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Main At = new Main();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int result = 0;
        result = At.retrunN(b - a) - b;
        System.out.println(result);

    }
}