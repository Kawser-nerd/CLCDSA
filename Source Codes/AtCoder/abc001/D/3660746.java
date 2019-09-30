import java.util.Scanner;
class Main{
	public static void main(String[] aegs) {
		Scanner sc=new Scanner(System.in);
		boolean[] time=new boolean[1442];
		int N=sc.nextInt();
		for(int i=0; i<N; i++) {
			String unko=sc.next();
			int s=Integer.parseInt(unko.substring(0, 4));
			int t=Integer.parseInt(unko.substring(5, 9));
			int hjm=s/100*60+(s%100)/5*5;
			int owri=(t+4)/100*60+(t+4)%100/5*5;
			for(int j=hjm; j<=owri; j++) {
				time[j]=true;
			}
		}
		boolean tdk=false;
		int kaisi=0;
		int owari=0;
		for(int i=0; i<1442; i++) {
			if(time[i]==true && tdk==false) {
				kaisi=i/60*100+(i%60)/5*5;
				tdk=true;
			}
			else if(time[i]==false && tdk==true) {
				owari=i/60*100+(i%60)/5*5;
				System.out.println(String.format("%04d", Integer.parseInt(kaisi+""))+"-"+String.format("%04d", Integer.parseInt((owari)+"")));
				tdk=false;
			}
		}
	}
}