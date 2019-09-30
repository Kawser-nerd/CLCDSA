import java.util.Scanner;

class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n=sc.nextLong();
		boolean win=false;
		long now=n+1;
		while(now!=1)
		{
			now=now/2+now%2;
		//	System.out.println(now);
			win=false;
			if(now==1){
				break;
			}
			now=(now-1)/2+(now+1)%2;
			win=true;
		//	System.out.println(now);
		}
		if(win){
			System.out.println("Takahashi");
		}else{
			System.out.println("Aoki");
		}

	}

}