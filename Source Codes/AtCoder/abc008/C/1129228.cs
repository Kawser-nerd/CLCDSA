using System;
public class Aprob {
    public static void Main() {
        int N = int.Parse(Console.ReadLine());
        int[] C=new int[N];
        for(int i =0;i<N;i++){
          C[i]=int.Parse(Console.ReadLine());
        }
	float prob=0;
	float yaku;
	foreach(int n in C){
		yaku=0;
		foreach(int m in C){
			if(n%m==0){
				yaku++;
			}
		}
                yaku--;
		if(yaku%2!=0){
			prob+=0.5f;
		}else{
			prob+=(yaku+2)/(2*yaku+2);
		}
      	}
        Console.WriteLine(prob);
    }
}