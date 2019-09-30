import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner scanner= new Scanner(System.in);
        int N = scanner.nextInt();
        int m = 0;
        String s = String.valueOf(N);
        for(int i = 0; i < s.length(); i++){
            m += s.charAt(i) - '0';
        }
        if(N % m == 0){
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

}