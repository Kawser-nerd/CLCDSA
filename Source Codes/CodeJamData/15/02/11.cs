using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace solver
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = 0;
            int D = 0;
            int index = 1;
            //int[] pancakes = new int[0];

            String line = Console.In.ReadLine();
            while (line != null)
            {
                if(T == 0){
		            T = Convert.ToInt32(line);
	            }else if(D == 0){
		            D = Convert.ToInt32(line);
	            }else{
		            int maxValue = 0;
		            D = 0;
		            int[] pancakes = line.Split(' ').Select(k=>Convert.ToInt32(k)).ToArray();
		            maxValue = pancakes.Max();
		
		            int minMinutes = maxValue;
		            int i = 1;
		            while(i<=maxValue){
			            int minutes = i;
                        foreach(int p in pancakes){
                            if(p > i){
					            minutes += (p / i) - (p % i == 0 ? 1 : 0);
				            }
                        }
			
			            minMinutes = (new int[]{minMinutes,minutes}).Min();
			            i+=1;
		            }
		
		            Console.WriteLine("Case #"+index+": "+minMinutes);
                    index++;
	            }
                //Console.WriteLine(line);
                line = Console.In.ReadLine();
            }
        }
    }
}
