import java.util.*;
import java.util.List;
import java.util.ArrayList;
import java.math.*;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        if(X==3||X==5||X==7){
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }
    }
}