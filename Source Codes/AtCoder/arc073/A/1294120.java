import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();

        int[] pushes = new int[N];

        for(int i=0;i<N;i++) {
            pushes[i] = sc.nextInt();
        }
        int sum = 0;
        int till = 0;
        for(int i=0;i<N;i++){

            if(till>pushes[i]){
                sum += (pushes[i]- pushes[i-1]);
            }
            else{
                sum += T;
            }

            till = pushes[i]+T;

        }

        //last one
       // sum += T;

        System.out.println(sum);

        sc.close();

    }

}