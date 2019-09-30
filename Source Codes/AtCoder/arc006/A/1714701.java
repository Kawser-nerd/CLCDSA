import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] e=new int[6];
		int[] l=new int[6];
		int b=0;
		for(int i=0;i<6;i++){
			e[i]=sc.nextInt();
		}
		b=sc.nextInt();
		for(int i=0;i<6;i++){
			l[i]=sc.nextInt();
		}
		int cnt=0;
		int ans=0;
		boolean bonus=false;
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				if(e[j]==l[i]){
					cnt++;
					break;
				}

				if(j==5&&l[i]==b){
					bonus=true;
				}
			}
		}

		cnt+=(cnt/6);
		if(cnt==5&&bonus){
			cnt+=1;
		}
		System.out.println((cnt>=3)?(8-cnt):(0));
	}

}