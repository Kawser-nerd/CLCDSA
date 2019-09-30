import java.util.*;
import java.util.List;
import java.util.ArrayList;
import java.math.*;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        if(B%A==0){
            System.out.println(A+B);
        }
        else{
            System.out.println(B-A);
        }
    }
}