import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        for(int i = 0; i <=(n-1)/9; i++){
            System.out.print(n%9==0?9:n%9);
        }
        System.out.println();
    }
}