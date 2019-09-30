import java.util.Scanner;
public class Main {
    public static void main(String[] args) throws Exception {
    	Scanner scan=new Scanner(System.in);
    	int sx=scan.nextInt();
    	int sy=scan.nextInt();
    	int tx=scan.nextInt();
    	int ty=scan.nextInt();
    	for(int i=0;i<tx-sx;i++) {
    		System.out.print("R");
    	}
    	for(int i=0;i<ty-sy;i++) {
    		System.out.print("U");
    	}
    	for(int i=0;i<tx-sx;i++) {
    		System.out.print("L");
    	}
    	for(int i=0;i<ty-sy;i++) {
    		System.out.print("D");
    	}
    	System.out.print("D");
    	for(int i=0;i<tx-sx+1;i++) {
    		System.out.print("R");
    	}
    	for(int i=0;i<ty-sy+1;i++) {
    		System.out.print("U");
    	}
    	System.out.print("LU");
    	for(int i=0;i<tx-sx+1;i++) {
    		System.out.print("L");
    	}
    	for(int i=0;i<ty-sy+1;i++) {
    		System.out.print("D");
    	}
    	System.out.println("R");
    }
}