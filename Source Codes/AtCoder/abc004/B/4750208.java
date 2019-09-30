import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String v0[] = new String[4];
        String v1[] = new String[4];
        String v2[] = new String[4];
        String v3[] = new String[4];

        for(int i = 0; i < 4; i++){
            v0[i] = scan.next();
        }
        for(int i = 0; i < 4; i++){
            v1[i] = scan.next();
        }
        for(int i = 0; i < 4; i++){
            v2[i] = scan.next();
        }
        for(int i = 0; i < 4; i++){
            v3[i] = scan.next();

        }

        for(int i = 3; i>-1; i--){
            System.out.print(v3[i]);
            System.out.print(" ");
        }
        System.out.println();
        for(int i = 3; i>-1; i--){
            System.out.print(v2[i]);
            System.out.print(" ");
        }
        System.out.println();
        for(int i = 3; i>-1; i--){
            System.out.print(v1[i]);
            System.out.print(" ");
        }
        System.out.println();
        for(int i = 3; i>-1; i--){
            System.out.print(v0[i]);
            System.out.print(" ");
        }
        System.out.println();
    }
}