using System;
class Program{
	private int max(int x ,int y){
		return (x > y) ? x : y;
	}
	public static void Main(){
		Program prog = new Program();
		int N = int.Parse(Console.ReadLine());
		int[,] A = new int[2,N];
		int p, q;
		string[] str;
		for (p = 0 ;p < 2 ;p++ ){
			str = Console.ReadLine().Split(' ');
			for (q = 0 ;q < N ;q++){
				A[p,q] = int.Parse(str[q]);
			}
		}
		int[,] B = new int[2,N];
		B[1,N-1] = A[1,N-1];
		B[0,N-1] = A[0,N-1] + A[1,N-1];
		if (N >= 2){
			for (q = 1 ;q < N ;q++ ){
				B[1,N-1-q] = A[1,N-1-q] + B[1, N-q];
				B[0,N-1-q] = prog.max(B[1,N-1-q],B[0,N-q]) + A[0,N-1-q];
			}
		}
		Console.WriteLine(B[0,0]);
	}
}