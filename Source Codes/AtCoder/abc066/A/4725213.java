import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int [] values = {input.nextInt(), input.nextInt(), input.nextInt()};
        Arrays.sort(values);
        System.out.println(values[0] + values[1]);
    }
}