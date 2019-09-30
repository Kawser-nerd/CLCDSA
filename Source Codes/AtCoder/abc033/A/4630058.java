import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N =	sc.nextInt();
	if(N==0 || N==1111 || N==2222|| N==3333|| N==4444|| N==5555|| N==6666||N==7777||N==8888||N==9999) {
            System.out.println("SAME");
        } else {
            System.out.println("DIFFERENT");
        }
    }
}