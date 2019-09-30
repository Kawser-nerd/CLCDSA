import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        long a = input.nextLong();
        long b = input.nextLong();
        long c = input.nextLong();
        long count = 0;
        if (a == 0){
            count++;
            count += b / c;
        }else if (a == 1){
            count += b / c;
        }else{
            count += b / c;
            count -= (a-1) / c;
        }

        System.out.println(count);
    }
}