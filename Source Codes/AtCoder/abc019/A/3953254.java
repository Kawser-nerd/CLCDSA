import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A[] = new int[3];
        for (int i = 0; i < A.length; i++) {
            A[i] = sc.nextInt();
        }
        Arrays.sort(A);
        System.out.println(A[1]);
    }
}