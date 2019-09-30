import java.io.*;
import java.util.*;

public class mines {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("mines.in"));
        
        int a = Integer.parseInt(in.nextLine());
        
        for(int i = 0; i < a; i++) {
            System.out.println("Case #" + (i + 1) + ": ");
            String str = in.nextLine();
            int rows = Integer.parseInt(str.substring(0, str.indexOf(" ")));
            int cols = Integer.parseInt(str.substring(str.indexOf(" ") + 1, str.lastIndexOf(" ")));
            int mines = Integer.parseInt(str.substring(str.lastIndexOf(" ") + 1));
            
            if(rows == 1 || cols == 1 || mines == 0) {
                if(rows == 1) {
                    for(int j = 0; j < mines; j++) {
                        System.out.print("*");
                    }
                    for(int j = mines; j < cols - 1; j++) {
                        System.out.print(".");
                    }
                    System.out.println("c");
                }
                else if(cols == 1) {
                    for(int j = 0; j < mines; j++) {
                        System.out.println("*");
                    }
                    for(int j = mines; j < rows - 1; j++) {
                        System.out.println(".");
                    }
                    System.out.println("c");
                } else if(mines == 0) {
                    char[][] mat = new char[rows][cols];
                    for(int j = 0; j < rows; j++) {
                        for(int k = 0; k < cols; k++) {
                            mat[j][k] = '.';
                        }
                    }
                    mat[0][0] = 'c';
                    for(int l = 0; l < rows; l++) {
                        for(int m = 0; m < cols - 1; m++) {
                            System.out.print(mat[l][m]);
                        }
                        System.out.println(mat[l][cols - 1]);
                    }
                }
            } else {
                char[][] mat = new char[rows][cols];
                for(int j = 0; j < rows; j++) {
                    for(int k = 0; k < cols; k++) {
                        mat[j][k] = '.';
                    }
                }
                if(mines <= (rows - 2) * (cols - 2)) {
                    for(int j = 0; j < mines / (cols - 2); j++) {
                        for(int k = 0; k < cols - 2; k++) {
                            mat[j][k] = '*';
                        }
                    }
                    for(int j = 0; j < mines % (cols - 2); j++) {
                        mat[mines / (cols - 2)][j] = '*';
                    }
                    mat[rows - 1][cols - 1] = 'c';
                    for(int j = 0; j < rows; j++) {
                        for(int k = 0; k < cols - 1; k++) {
                            System.out.print(mat[j][k]);
                        }
                        System.out.println(mat[j][cols - 1]);
                    }
                } else {
                    if(mines == rows * cols - 1) {
                        for(int j = 0; j < rows; j++) {
                            for(int k = 0; k < cols; k++) {
                                mat[j][k] = '*';
                            }
                        }
                        mat[0][0] = 'c';
                        for(int j = 0; j < rows; j++) {
                            for(int k = 0; k < cols - 1; k++) {
                                System.out.print(mat[j][k]);
                            }
                            System.out.println(mat[j][cols - 1]);
                        }
                    } else {
                        boolean hasbeenfinished = false;
                        int nomines = rows * cols - mines;
                        int temp = 0;
                        for(int j = 1; j <= rows; j++) {
                            for(int k = 1; k <= cols; k++) {
                                if(!hasbeenfinished && nomines <= j * k && nomines >= j * k - (j - 2) * (k - 2) && j >= 2 && k >= 2) {
                                    hasbeenfinished = true;
                                    mat[rows - 1][cols - 1] = 'c';
                                    for(int l = 0; l < rows - j; l++) {
                                        for(int m = 0; m < cols; m++) {
                                            mat[l][m] = '*';
                                        }
                                    }
                                    for(int l = rows - j; l < rows; l++) {
                                        for(int m = 0; m < cols - k; m++) {
                                            mat[l][m] = '*';
                                        }
                                    }
                                    temp = mines - (rows * cols - j * k);
                                    for(int l = 0; l < (k == 2 ? 0 : temp / (k - 2)); l++) {
                                        for(int m = 0; m < k - 2; m++) {
                                            mat[l + rows - j][m + cols - k] = '*';
                                        }
                                    }
                                    for(int l = 0; l < (k == 2 ? 0 : temp % (k - 2)); l++) {
                                        mat[temp / (k - 2) + rows - j][l + cols - k] = '*';
                                    }
                                    for(int l = 0; l < rows; l++) {
                                        for(int m = 0; m < cols - 1; m++) {
                                            System.out.print(mat[l][m]);
                                        }
                                        System.out.println(mat[l][cols - 1]);
                                    }
                                }
                            }
                        }
                        if(!hasbeenfinished) System.out.println("Impossible");
                    }
                }
            }
        }
    }
}