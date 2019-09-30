import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = {1, 2, 3, 4, 5, 6};
        int n = sc.nextInt();
        n %= 30;
        int index = 0;
        while(index < n) {
            int i1 = index % 5;
            int i2 = index % 5 + 1;
            int temp = array[i1];
            array[i1] = array[i2];
            array[i2] = temp;
            index++;
        }
        for(int num: array) {
            System.out.print(num);
        }
        System.out.println();
    }
}