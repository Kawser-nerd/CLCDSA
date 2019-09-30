import java.util.*;
import java.util.List;
import java.util.ArrayList;
import java.math.*;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String SplitN[] = Integer.toString(N).split("");
        if(Arrays.asList(SplitN).contains("3")||N%3==0){
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }
    }
}