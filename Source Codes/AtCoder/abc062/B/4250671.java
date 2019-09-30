import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();

		  for (int i = 0; i < w+2; i++) {
            System.out.print('#');
        }
        System.out.println();

        for (int i = 0; i < h; i++) {
            String s = sc.next();
            System.out.print('#');
            for (int j = 0; j < w; j++) {
                System.out.print(s.charAt(j));
            }
            System.out.println('#');
        }
        
        for (int i = 0; i < w+2; i++) {
            System.out.print('#');
        }
    }
}