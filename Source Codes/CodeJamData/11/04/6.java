import java.util.Scanner;


public class GoroSort {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int nbCase = s.nextInt();
        for (int numCase = 1 ; numCase <= nbCase ; numCase++) {
            s.nextLine();
            int size = s.nextInt();
            s.nextLine();
            int[] array = new int[size];
            int[] arrayReverse = new int[size];
            for (int i = 0 ; i < size ; i++) {
                int v = s.nextInt()-1;
                array[i] = v;
                arrayReverse[v] = i;
            }
            int n = 0;
            for (int i = 0 ; i < size ; i++) if (array[i] != i) n++;
            System.out.print("Case #");
            System.out.print(numCase);
            System.out.print(": ");
            System.out.print(n);
            System.out.println(".000000");
        }
    }
}
