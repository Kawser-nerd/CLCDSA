import java.util.Scanner;
     
     
     
    class Main {
     
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int H = sc.nextInt();
            int W = sc.nextInt();
            sc.nextLine();
            String [][] S = new String [H][W];
            final int height = H;
            final int width = W;
            int [][] number = new int [H][W];
            String[]tmp = new String[H];
           
            for (int i = 0; i < H ; i++){
                tmp[i] = sc.nextLine();
            }
                
            //set Tiles
            for (int i = 0; i < H ; i++){
                String[] str = tmp[i].split("");
                for (int j = 0; j <W ; j++){
                    S[i][j] = str[j];
                }
            }
     
            //print mine number
            for (int i = 0; i < H ; i++){
                for(int j = 0; j < W; j ++){
                    if(S[i][j].equals("#")){
                        if( countMine(i , j, height, width, S ) == true){
                            continue;
                        }else{
                            System.out.println("No");
                            System.exit(0);
                        }
                    }
                }   
            }
            System.out.println("Yes");
            sc.close();
        }
        
        public static boolean countMine( int i, int j, int height, int width, String[][] S){
            boolean result = false;
            if( i - 1 >= 0 && S[i-1][j].equals("#") ) {
            	result = true;
            }else if( i + 1 < height && S[i+1][j].equals("#") ) {
            	result = true;
            }else if( j + 1 < width && S[i][j+1].equals("#")) {
            	result = true;
            }else if( j - 1 >= 0 && S[i][j-1].equals("#")) {
            	result = true;
            }else {
            }
            return result;
        }
    }