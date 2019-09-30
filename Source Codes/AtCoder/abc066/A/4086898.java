import java.util.Arrays;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String[] dat = scan.nextLine().split(" ");
        scan.close();
        int[] intdat = new int[3];
        for (int i = 0; i < 3; i++)
            intdat[i] = Integer.parseInt(dat[i]);
        Arrays.sort(intdat);
        System.out.println(intdat[0] + intdat[1]);
    }
}