import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = readInt();
        char[][] charMatrix = new char[N][N];

        for(int i=0; i<N; i++){
            String tmpStr = sc.next();
            for(int j=0; j<N; j++) {
                charMatrix[i][j] = tmpStr.charAt(j);
            }
        }

        long cnt = 0;

        for(int i=0; i<N; i++){
            char[][] shiftedMatrix = shiftCharMatrix(charMatrix, 0, i);

            if(checkCharMatrixSymmetry(shiftedMatrix)){
                cnt += N;
            }
        }

        System.out.println(cnt);
    }

    private static char[][] shiftCharMatrix(char[][] matrix, int H, int W) {
        int SIZE_H  = matrix.length;
        int SIZE_W = matrix[0].length;
        char[][] shiftedMatrix = new char[SIZE_H][SIZE_W];

        for(int h=0; h<SIZE_H; h++){
            for(int w=0; w<SIZE_W; w++){
                int next_h = (h + H) % SIZE_H;
                int next_w = (w + W) % SIZE_W;
                shiftedMatrix[next_h][next_w] = matrix[h][w];
            }
        }
        return shiftedMatrix;
    }

    private static boolean checkCharMatrixSymmetry(char[][] matrix){
        int N = matrix.length;
        for(int i=0; i< N; i++){
            for(int j=i; j<N; j++){
                if(matrix[i][j] != matrix[j][i]){
                    return false;
                }
            }
        }

        return true;
    }

    private static char readChar(){
        return sc.next().charAt(0);
    }

    private static int readInt(){
        return Integer.parseInt(sc.next());
    }

    private static long readLong(){
        return Long.parseLong(sc.next());
    }

}