import java.util.Scanner;

class Main{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        System.out.println((int)((1900 * m + 100 * (n - m)) * Math.pow(2, m)));
    }
}