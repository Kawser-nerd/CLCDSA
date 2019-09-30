using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    long[] x;
    long[] y;
    long[] r;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        double[,] d = new double[N+2,N+2];
        for(int i=0;i<N+2;i++){
            for(int j=0;j<N+2;j++){
                d[i,j] = Distance(i,j);
            }
        }
        Dijkstra D = new Dijkstra(d,N,N+2);
        sb.Append(D.GetCost(N+1)+"\n");

    }
    double Distance(int i,int j){
        return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) > (r[i]+r[j])*(r[i]+r[j]) ? Math.Sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) - (r[i]+r[j]) : 0;
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(Console.ReadLine());
        x = new long[N+2];
        y = new long[N+2];
        r = new long[N+2];
        x[N] = Int64.Parse(str[0]);
        x[N+1] = Int64.Parse(str[2]);
        y[N] = Int64.Parse(str[1]);
        y[N+1] = Int64.Parse(str[3]);
        r[N] = 0;
        r[N+1] = 0;
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            x[i] = Int64.Parse(str[0]);
            y[i] = Int64.Parse(str[1]);
            r[i] = Int64.Parse(str[2]);
        }
    }    
}
class Dijkstra{
	int N;
	int start;
	double[,] distance;
	double[] cost;
	public Dijkstra(double[,] d,int s,int n){
		N = n;
		distance = d;
		start = s;
		Calc();
	}
	void Calc(){
		bool[] finished = new bool[N];
		cost = new double[N];
		for(int i=0;i<N;i++){
			finished[i] = false;
			cost[i] = i == start ? 0 : -1;
		}
		while(true){
			int min = -1;
			for(int i=0;i<N;i++){
				if(!finished[i] && cost[i] != -1 && (min == -1 || cost[min] > cost[i])){
					min = i;
				}
			}
			if(min == -1){
				break;
			}
			finished[min] = true;
			for(int i=0;i<N;i++){
				if(!finished[i] && distance[min,i] != -1 && (cost[i] == -1 || cost[i] > cost[min] + distance[min,i])){
					cost[i] = cost[min] + distance[min,i];
				}
			}
		}
	}
	public double GetCost(int p){
		return cost[p];
	}
}