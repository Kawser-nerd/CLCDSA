import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int N =	sc.nextInt();
	int M =	sc.nextInt();
	int X =	sc.nextInt();
	int[] a	= new int[M];
	int pre	= 0;
	int fol	= 0;
        for(int i = 0; i<M; i++) {
            int	place =	sc.nextInt();
            if(place<X) pre++;
            else fol++;
        }
        System.out.println(Math.min(pre,fol));
    }
}