import java.util.*;


public class Main {
    public static void main(String[] args) {
        // ?????????
        // Let's ???????

        Scanner sc = new Scanner(System.in);
        String[] str = sc.nextLine().split(" ");
        int height = Integer.parseInt(str[0]);
        int width = Integer.parseInt(str[1]);

        String[][] square = new String[height+2][width+2];

        for(int i = 0 ; i < height+2;i++){
            for(int j = 0;j < width+2;j++){
                square[i][j] = "";
            }
        }


        for(int i = 1 ; i <= height;i++){
            String line = sc.nextLine();
            for(int j = 1;j <= width;j++){
                square[i][j] = String.valueOf(line.charAt(j-1));
            }
        }

        for(int i = 1 ; i <= height;i++){
            for(int j = 1;j <= width;j++){

                if(square[i][j].equals("#")){
                    continue;
                }


                int bombCount = 0;

                if(square[i-1][j-1].equals("#")){
                    bombCount++;
                }

                if(square[i-1][j].equals("#")){
                    bombCount++;
                }

                if(square[i-1][j+1].equals("#")){
                    bombCount++;
                }

                if(square[i][j-1].equals("#")){
                    bombCount++;
                }

                if(square[i][j+1].equals("#")){
                    bombCount++;
                }
                
                if(square[i+1][j-1].equals("#")){
                    bombCount++;
                }

                if(square[i+1][j].equals("#")){
                    bombCount++;
                }

                if(square[i+1][j+1].equals("#")){
                    bombCount++;
                }                
                square[i][j] = Integer.toString(bombCount);
            }
        }

        for(int i = 1 ; i <= height;i++){
            for(int j = 1;j <= width;j++){
                System.out.print(square[i][j]);
            }
            System.out.println("");
        }
    }
}