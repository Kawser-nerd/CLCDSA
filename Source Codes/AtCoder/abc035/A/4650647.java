import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int W =	sc.nextInt();
	int H =	sc.nextInt();

	if(W%16==0 && H%9==0) {
            System.out.println("16:9");
        }else {
            System.out.println("4:3");
        }
    }
}