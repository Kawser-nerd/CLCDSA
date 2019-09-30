import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int [] supportiveArray = {1, 11, 111, 1111, 11111, 111111};
        int [] repdigitArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        ArrayList<Integer> repdigitList = new ArrayList<Integer>();

        for(int i = 0; i < 6; i++){
            int support = supportiveArray[i];

            for(int j = 0; j < 9; j++){
                int repdigit = repdigitArray[j];
                int repdigitPattern = support * repdigit;

                repdigitList.add(repdigitPattern);
            }
        }
        System.out.println(repdigitList.get(N-1));
    }
}