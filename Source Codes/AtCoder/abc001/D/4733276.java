import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] array = new int[12*24+1];
        for (int i = 0; i < n; i++) {
            String[] time = sc.next().split("-");
            int start = Integer.parseInt(time[0]);
            start = start/100 * 60 + start % 100;
            start = start - start % 5;
            int end = Integer.parseInt(time[1]);
            end = end/100 * 60 + end % 100;
            if(end % 5 != 0) {
                end = end + (5 - end % 5);
            }
            array[start/5] += 1;
            array[end/5] -= 1;
        }

        int sum = 0;
        for (int i = 0; i < 12*24+1; i++) {
            sum += array[i];
            array[i] = sum;
        }

        int start = -1;
        for (int i = 0; i < 12*24+1; i++) {
            if(array[i] > 0){
                start = i;
                while(i < 12*24+1 && array[i] > 0){
                    i++;
                }
                int end = i;
                System.out.print(String.format("%04d", start/12*100+start%12*5));
                System.out.print("-");
                System.out.println(String.format("%04d", end/12*100+end%12*5));
            }
        }
    }
}