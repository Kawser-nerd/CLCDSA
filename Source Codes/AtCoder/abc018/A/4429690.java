import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] A = new int[3];
        Integer[] B = new Integer[3];
        int[] ranc = new int[3];
        for(int i = 0; i<3; i++) {
            A[i] = sc.nextInt();
            B[i] = A[i];
        }
        Arrays.sort(B, Collections.reverseOrder());
         for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                if(A[i] == B[j]){
                    ranc[i] = j+1;
                }
            }
        }
        for(int i: ranc) {
            System.out.println(i);
        }
    }
}