import java.util.*;


public class Main {
    public static void main(String[] args) {
        // ?????????
        // Let's ???????

        Scanner sc = new Scanner(System.in);
        String[] line = sc.nextLine().split(" ");
        
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);
        
        int[] array = new int[N+1];

        for(int i = 0;i < M;i++){

            String[] input = sc.nextLine().split(" ");
            
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            array[a]++;
            array[b]++;
        }

        for(int i = 1;i <= N;i++){
            System.out.println(array[i]);
        }

    }
       
}