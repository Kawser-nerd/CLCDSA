import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		DataSet d = new DataSet();
		d.input();
		if(d.H%d.h==0&&d.W%d.w==0)
			System.out.println("No");
		else if(d.H%d.h!=0){
			System.out.println("Yes");
			for(int i=0;i<d.H;i++){
				for(int j=0;j<d.W;j++){
					System.out.print((i%d.h==0)?1000*d.h-1001:-1000);
					if(j==d.W-1) System.out.println();
					else System.out.print(" ");
				}
			}
		}
		else if(d.W%d.w!=0){
			System.out.println("Yes");
			for(int i=0;i<d.H;i++){
				for(int j=0;j<d.W;j++){
					System.out.print((j%d.w==0)?1000*d.w-1001:-1000);
					if(j==d.W-1) System.out.println();
					else System.out.print(" ");
				}
			}
		}
	}

}

class DataSet{
	
	int H,W,h,w;
	
	public void input(){
		Scanner sc = new Scanner(System.in);
		H = sc.nextInt();
		W = sc.nextInt();
		h = sc.nextInt();
		w = sc.nextInt();
		sc.close();
	}
	
}