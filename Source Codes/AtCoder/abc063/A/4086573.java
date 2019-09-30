import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        scan.close();
        if (a + b < 10)
            System.out.println(a + b);
        else
            System.out.println("error");
    }
}