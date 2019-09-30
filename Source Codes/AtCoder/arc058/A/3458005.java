import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		boolean[] moji=new boolean[10];
		for(int i=0; i<10; i++) {
			moji[i]=true;
		}
		int N=sc.nextInt();
		int K=sc.nextInt();
		for(int i=0; i<K; i++) {
			moji[sc.nextInt()]=false;
		}
		int[] ss=new int[10-K];
		int a=0;
		for(int i=0; i<10; i++) {
			if(moji[i]) {
				ss[a]=i;
				a++;
			}
		}
		int min=114514;
		int tmp=0;

		for(int i=0; i<a; i++) {
			for(int j=0; j<a; j++) {
				for(int k=0; k<a; k++) {
					for(int l=0; l<a; l++) {
						for(int m=0; m<a; m++) {
							tmp=10000*ss[i]+1000*ss[j]+100*ss[k]+10*ss[l]+ss[m];
							if(tmp<min && tmp>=N) {
								min=tmp;
							}
						}
					}
				}
			}
		}

		for(int i=0; i<a; i++) {
			for(int j=0; j<a; j++) {
				for(int k=0; k<a; k++) {
					for(int l=0; l<a; l++) {
						tmp=1000*ss[i]+100*ss[j]+10*ss[k]+ss[l];
						if(tmp<min && tmp>=N) {
							min=tmp;
						}
					}
				}
			}
		}
		for(int i=0; i<a; i++) {
			for(int j=0; j<a; j++) {
				for(int k=0; k<a; k++) {
					tmp=100*ss[i]+10*ss[j]+ss[k];
					if(tmp<min && tmp>=N) {
						min=tmp;
					}
				}
			}
		}
		for(int i=0; i<a; i++) {
			for(int j=0; j<a; j++) {
				tmp=10*ss[i]+ss[j];
				if(tmp<min && tmp>=N) {
					min=tmp;
				}
			}
		}
		for(int i=0; i<a; i++) {
			tmp=ss[i];
			if(tmp<min && tmp>=N) {
				min=tmp;
			}
		}
		System.out.println(min);
	}
}