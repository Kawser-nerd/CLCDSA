using System;
class Program{
	static bool[,] h=new bool[4,15];
	static string[] arr=new string[8];
	static bool e=false;
	static void Main(){
		for(int i=0;i<8;i++){
			arr[i]=Console.ReadLine();
			int q=arr[i].IndexOf("Q");
			if(q!=-1){
				h[0,i]=true;
				h[1,q]=true;
				h[2,i+q]=true;
				h[3,i-q+7]=true;
			}
		}
		fu(0,0);
		if(!e){Console.WriteLine("No Answer");}
	}
	static void fu(int a,int m){
		if(a==5&&!e){
			int t=0;for(int j=0;j<8;j++){t=h[0,j]==true?t+1:t;}
			for(int j=0;j<8;j++){t=h[1,j]==true?t+10:t;}
			for(int j=0;j<15;j++){t=h[2,j]==true?t+100:t;}
			for(int j=0;j<15;j++){t=h[3,j]==true?t+1000:t;}
			if(t==8888){
				for(int i=0;i<8;i++){Console.WriteLine(arr[i]);}
				e=true;
			}
		}
		else{
			for(int i=m;i<8&&!e;i++){
				if(!h[0,i]){
					for(int j=0;j<8&&!e;j++){
						if(!h[1,j]&&!h[2,i+j]&&!h[3,i-j+7]){
							h[0,i]=true;h[1,j]=true;
							h[2,i+j]=true;h[3,i-j+7]=true;
							arr[i]=arr[i].Remove(j,1);
							arr[i]=arr[i].Insert(j,"Q"); 
							fu(a+1,i);
							arr[i]=arr[i].Remove(j,1);
							arr[i]=arr[i].Insert(j,"."); 
							h[0,i]=false;h[1,j]=false;
							h[2,i+j]=false;h[3,i-j+7]=false;
						}
					}
				}
			}
		}
	}
}