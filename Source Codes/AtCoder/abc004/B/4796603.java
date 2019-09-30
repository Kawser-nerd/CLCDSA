import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Character[][] b = new Character[4][4];
        for (int i = 3; i >= 0; i--)
            for (int j = 3; j >= 0; j--) {
                b[i][j] = sc.next().charAt(0);
            }

        for (int i = 0; i < 4; i++) {
            System.out.println(
                    Arrays.stream(b[i])
                            .map(x -> "" + x)
                            .collect(Collectors.joining(" "))
            );
        }
    }
}